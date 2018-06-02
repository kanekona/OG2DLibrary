#include "StreamingSound.h"
//---------------------------------
//@:StrimingSoundclass
//---------------------------------
void StreamingSound::queueStream(StreamWav& stream, Source& source, Buffer& buffer, std::vector<char>& sound_buffer)
{
	size_t length = stream.read(sound_buffer);
	buffer.Bind(stream.isStereo(), &sound_buffer[0], static_cast<u_int>(length), stream.sampleRate());
	source.queueBuffer(buffer);
}
void StreamingSound::streamProc(const std::string& path, const bool loop, std::shared_ptr<Source>& source, std::shared_ptr<Param>& param)
{
	StreamWav stream(path);
	stream.loop(loop);
	Buffer buffer[BUFFER_NUM];
	// �ǂݍ��݃o�b�t�@��1�b�Ԃ�̒����ɂ���
	u_int buffer_size = stream.sampleRate() * (stream.isStereo() ? 2 : 1) * sizeof(uint16_t);
	std::vector<char> sound_buffer(buffer_size);
	// ���ׂẴX�g���[���o�b�t�@���Đ��L���[�ɐς�
	for (u_int i = 0; i < BUFFER_NUM; ++i)
	{
		queueStream(stream, *source, buffer[i], sound_buffer);
	}
	source->Volume(1.0);
	source->Play();
	while (!stream.isEnd())
	{
		std::cout << stream.GetlastSize() << std::endl;
		param->mutex.lock();
		bool stopped = param->stopped;
		bool back = param->backStartPos;
		param->backStartPos = false;
		param->mutex.unlock();
		if (stopped) { break; }
	//	stream.BackSound = back;
		if (source->processed() > 0)
		{
			ALuint buffer_id = source->UnqueueBuffer();
			for (u_int i = 0; i < BUFFER_NUM; ++i)
			{
				if (buffer_id == buffer[i].GetID())
				{
					// �Đ��̏I������o�b�t�@���ăL���[�C���O
					queueStream(stream, *source, buffer[i], sound_buffer);
					break;
				}
			}
		}
		//�w�肵�����Ԃ����X���b�h���u���b�N����
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME_MS));
	}
	std::cout << "Streaming�I��" << std::endl;
	//stream.End();
}
StreamingSound::StreamingSound()
{

}
StreamingSound::StreamingSound(const std::string& path, const bool loop) :
	source_(std::make_shared<Source>()),
	param_(std::make_shared<Param>()),
	pause_(false)
{
	this->filepath_ = path;
	this->loop_ = loop;
	this->isplay_ = false;
	this->param_->backStartPos = false;
}
void StreamingSound::createSound(const std::string& path_, bool loop)
{
	source_ = std::make_shared<Source>();
	param_ = std::make_shared<Param>();
	pause_ = false;
	this->filepath_ = path_;
	this->loop_ = loop;
	this->isplay_ = false;
	this->param_->backStartPos = false;
}
void StreamingSound::gain(const float gain)
{
	this->source_->Volume(gain);
}
void StreamingSound::pitch(const float value_) const
{
	this->source_->Pitch(value_);
}
void StreamingSound::pause()
{
	//�ʃX���b�h�����b�N����
	this->param_->mutex.lock();
	bool stopped = this->param_->stopped;
	//�ʃX���b�h�̃��b�N����������
	this->param_->mutex.unlock();
	if (stopped) return;
	if (this->isplay_)
	{
		this->source_->Pause();
		this->isplay_ = false;
	}
	else
	{
		this->source_->Play();
		this->isplay_ = true;
	}
}
void StreamingSound::stop()
{
	this->gain(0.0f);
	this->param_->backStartPos = true;
	std::lock_guard<std::mutex>(this->param_->mutex);
	this->param_->stopped = true;
	this->isplay_ = false;
}
bool StreamingSound::isPlaying()
{
	this->param_->mutex.lock();
	bool stopped = this->param_->stopped;
	this->param_->mutex.unlock();
	if (stopped) return false;
	return this->source_->isPlay();
}
void StreamingSound::play()
{
	if (!this->isplay_) {
	//���s�X���b�h�̐���
	std::thread thread(streamProc, this->filepath_, this->loop_, source_, param_);
	//�X���b�h�̊Ǘ��������
	thread.detach();
	this->param_->mutex.lock();
	this->param_->stopped = false;
	this->param_->mutex.unlock();
	this->isplay_ = true;
	}
}
void StreamingSound::DeleteSound()
{
	gain(0.0);
	//�X���b�h�Ԃ̏������擾����
	std::lock_guard<std::mutex>(this->param_->mutex);
	this->param_->stopped = true;
	this->isplay_ = false;
}
float StreamingSound::GetTime() const
{
	//���݂̎��Ԃ�Ԃ�����streaming������1�b���Ƃɓǂݍ��ݒ�������0~1���炢�����Ԃ�Ȃ���
	return this->source_->currenttime();
}
void StreamingSound::debugUpdata()
{

}