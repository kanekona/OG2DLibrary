#include "Audio.h"
//---------------------------------
//@:Audioclass
//---------------------------------
Audio::Audio()
{
	std::cout << "Audio()" << std::endl;
	//�A�v���P�[�V�������f�o�C�X�ɐڑ�������
	//�����̓f�o�C�X�̎w��,NULL�Ȃ����̃f�o�C�X
	this->device = alcOpenDevice(nullptr);
	if (!this->device)
	{
		std::cout << "�f�o�C�X�̐ڑ�Error" << std::endl;
		return;
	}
	//�R���e�L�X�g�̐���
	this->context = alcCreateContext(this->device, nullptr);
	if (!this->context)
	{
		std::cout << "�R���e�L�X�g����Error" << std::endl;
		return;
	}
	//���삷��R���e�L�X�g�̑I��
	if (alcMakeContextCurrent(this->context) == ALC_FALSE)
	{
		std::cout << "����R���e�L�X�g�̑I��Error" << std::endl;
		return;
	}
}
Audio::~Audio()
{
	std::cout << "~Audio()" << std::endl;
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(this->context);
	alcCloseDevice(this->device);
}
Audio::SP Audio::Create()
{
	return Audio::SP(new Audio());
}
//---------------------------------
//@:Bufferclass
//---------------------------------
Audio::Buffer::Buffer()
{
	std::cout << "Buffer()" << std::endl;
	//�o�b�t�@���P����
	alGenBuffers(1, &this->id_);
	//���ݐi�s���Ԃ�0�ɂ���
	this->nowTime = 0.f;
}
Audio::Buffer::Buffer(std::string& path_)
{
	std::cout << "Buffer(string)" << std::endl;
	//�o�b�t�@���P����
	alGenBuffers(1, &this->id_);
	//Wav�t�@�C���̓ǂݍ���
	Wav wav_data(path_);
	//�o�ߎ��Ԃ��m�F
	this->nowTime = wav_data.time();
	// �g�`�f�[�^���o�b�t�@�ɃZ�b�g
	alBufferData(id_, wav_data.isStereo() ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, wav_data.data(), wav_data.size(), wav_data.sampleRate());
}
Audio::Buffer::~Buffer()
{
	std::cout << "~Buffer()" << std::endl;
	//�o�b�t�@�̍폜
	alDeleteBuffers(1, &this->id_);
}
float Audio::Buffer::GetTime() const
{
	std::cout << "GetTime()" << std::endl;
	//�i�s���Ԃ�Ԃ�
	return this->nowTime;
}
ALuint Audio::Buffer::GetID() const
{
	std::cout << "GetID()" << std::endl;
	//�o�b�t�@�ɓo�^���Ă���ID��Ԃ�
	return this->id_;
}
void Audio::Buffer::Bind(const bool stereo, const void* data, const u_int size, const u_int rate) const
{
	std::cout << "Bint(bool,void*,u_int,u_int)" << std::endl;
	//�g�`�f�[�^���o�b�t�@�ɃZ�b�g
	alBufferData(this->id_, stereo ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, data, size, rate);
}
//---------------------------------
//@:Sourceclass
//---------------------------------
Audio::Source::Source()
{
	std::cout << "Source()" << std::endl;
	//�\�[�X���P��������
	alGenSources(1, &this->id_);
}
Audio::Source::~Source()
{
	std::cout << "~Source()" << std::endl;
	//�g�`�f�[�^����������
	this->UnBindBuffer();
	//�\�[�X���폜����
	alDeleteSources(1, &this->id_);
}
void Audio::Source::BindBuffer(const Buffer& burrer_)
{
	std::cout << "BindBuffer()" << std::endl;
	//�\�[�X�Ƀo�b�t�@���w�肷��
	alSourcei(this->id_, AL_BUFFER, burrer_.GetID());
}
void Audio::Source::UnBindBuffer() const
{
	std::cout << "UnBindBuffer()" << std::endl;
	//�\�[�X�̃o�b�t�@����������
	alSourcei(this->id_, AL_BUFFER, 0);
}
ALuint Audio::Source::GetID() const
{
	std::cout << "GetID()" << std::endl;
	//�\�[�X��ID��Ԃ�
	return this->id_;
}
void Audio::Source::Play() const
{
	std::cout << "Play()" << std::endl;
	//�Đ�����
	alSourcePlay(this->id_);
}
void Audio::Source::Stop() const
{
	std::cout << "Stop()" << std::endl;
	//�~�߂�
	alSourceStop(this->id_);
}
void Audio::Source::Pause() const
{
	std::cout << "Pause()" << std::endl;
	//�ꎞ��~����
	alSourcePause(this->id_);
}
void Audio::Source::Volume(const float volume_) const
{
	std::cout << "Volume(float)" << std::endl;
	//���ʂ̕ύX
	alSourcef(this->id_, AL_GAIN, volume_);
}
void Audio::Source::Pitch(const float value_) const
{
	std::cout << "Pitch(float)" << std::endl;
	//�s�b�`�̕ύX
	alSourcef(this->id_, AL_PITCH, value_);
}
void Audio::Source::Looping(const bool loop_) const
{
	std::cout << "Looping(bool)" << std::endl;
	//TRUE�ŏI�����ŏ��̈ʒu�ɖ߂�
	alSourcei(this->id_, AL_LOOPING, loop_ ? AL_TRUE : AL_FALSE);
}
bool Audio::Source::isPlay() const
{
	std::cout << "isPlay()" << std::endl;
	//���݂̏�Ԃ�Ԃ�
	ALint state;
	alGetSourcei(this->id_, AL_SOURCE_STATE, &state);
	return state == AL_PLAYING;
}
float Audio::Source::currenttime() const
{
	//���݂̍Đ����Ԃ�Ԃ�
	ALfloat nowtime;
	alGetSourcef(this->id_, AL_SEC_OFFSET, &nowtime);
	return nowtime;
}
void Audio::Source::queueBuffer(const Buffer& buffer_) const
{
	std::cout << "queueBuffer(Buffer)" << std::endl;
	ALuint buffers = buffer_.GetID();
	//�o�b�t�@�l�[���̃L���[���쐬
	alSourceQueueBuffers(this->id_, 1, &buffers);
}
ALuint Audio::Source::UnqueueBuffer() const
{
	std::cout << "UnqueueBuffer()" << std::endl;
	ALuint buffers;
	//�L���[����o�b�t�@����������
	alSourceUnqueueBuffers(this->id_, 1, &buffers);
	return buffers;
}
int Audio::Source::processed() const
{
	std::cout << "processed()" << std::endl;
	int pro_;
	//�Đ��ς݂̃o�b�t�@����Ԃ�
	alGetSourcei(this->id_, AL_BUFFERS_PROCESSED, &pro_);
	return pro_;
}
//---------------------------------
//@:Wavclass
//---------------------------------
Audio::Wav::Wav(const std::string& file)
{
	std::ifstream fstr(file, std::ios::binary);
	if (!fstr)
	{
		std::cout << "�t�@�C���ǂݍ��݃G���[" << std::endl;
		throw;
	}
	// �t�@�C���������
	if (!Audio::Wav::analyzeWavFile(this->info, fstr))
	{
		std::cout << "Wav�t�@�C���ǂݍ��݃G���[: " << file << std::endl;
		throw;
	}
	if ((this->info.id != 1) || (this->info.bit != 16))
	{
		// ID���P�ŗʎq���r�b�g����16�ȊO�͈���Ȃ�
		std::cout << "Wav�t�@�C���̃t�H�[�}�b�g�G���[" << std::endl;
		throw;
	}
	// �Đ�����(�b)
	this->time_ = this->info.size / this->info.ch / 2.0f / this->info.sample_rate;
	// �f�[�^�ǂݍ���
	data_.resize(this->info.size);
	Audio::Wav::searchChunk(fstr, "data");
	fstr.seekg(4, fstr.cur);
	fstr.read(&data_[0], info.size);
}
u_int Audio::Wav::channel() const
{
	return this->info.ch;
}
bool Audio::Wav::isStereo() const
{
	return this->info.ch == 2;
}
u_int Audio::Wav::sampleRate() const
{
	return this->info.sample_rate;
}
u_int Audio::Wav::size() const
{
	return this->info.size;
}
float Audio::Wav::time() const
{
	return this->time_;
}
const char* Audio::Wav::data() const
{
	return &this->data_[0];
}
u_int Audio::Wav::getValue(const char* ptr, const u_int num)
{
	u_int value = 0;
	for (u_int i = 0; i < num; ++i, ++ptr)
	{
		// TIPS:int�^��菬�����^��int�^�Ɋg������Ă���v�Z�����̂�8bit�ȏ�V�t�g���Ă����Ȃ�
		value = value + (static_cast<u_char>(*ptr) << (i * 8));
	}
#ifdef __BIG_ENDIAN__
	value = (value << 24) | ((value << 8) & 0xff0000) | ((value >> 8) & 0xff00) | (value >> 24);
#endif
	return value;
}
bool Audio::Wav::searchChunk(std::ifstream& fstr, const char* chunk)
{
	//�`�����N�J�n�ʒu
	int WAV_START_SIZE = 12;
	fstr.seekg(WAV_START_SIZE, fstr.beg);
	// �`�����N�̕��т͕s��Ȃ̂ŁA��Ƀt�@�C���̐擪����T��
	while (1)
	{
		char tag[4];
		fstr.read(tag, 4);
		if (!std::strncmp(tag, chunk, 4))
		{
			return true;
		}
		// ���̃`�����N��
		char data[4];
		fstr.read(data, 4);
		u_int chunk_size = Audio::Wav::getValue(data, 4);
		fstr.seekg(chunk_size, fstr.cur);
		if (fstr.eof())
		{
			break;
		}
	}
	return false;
}
u_int Audio::Wav::getChunkSize(std::ifstream& fstr)
{
	char data[4];
	fstr.read(data, 4);
	return Audio::Wav::getValue(data, 4);
}
bool Audio::Wav::analyzeWavFile(Info& info, std::ifstream& fstr)
{
	// �t�@�C����wav�`�������ׂ�
	enum
	{
		WAV_HEADER_SIZE = 12
	};
	char header[WAV_HEADER_SIZE];
	fstr.read(header, WAV_HEADER_SIZE);
	if (std::strncmp(&header[0], "RIFF", 4))
	{
		std::cout << "���̃t�@�C����RIFF�ł͂���܂���" << std::endl;
		return false;
	}
	if (std::strncmp(&header[8], "WAVE", 4))
	{
		std::cout << "���̃t�@�C����Wave�ł͂���܂���" << std::endl;
		return false;
	}
	enum
	{
		// fmt�`�����N���̃f�[�^�ʒu
		WAV_ID = 0,
		WAV_CH = WAV_ID + 2,
		WAV_SAMPLE_RATE = WAV_CH + 2,
		WAV_BPS = WAV_SAMPLE_RATE + 4,
		WAV_BLOCK_SIZE = WAV_BPS + 4,
		WAV_BIT = WAV_BLOCK_SIZE + 2,
	};
	// fmt�`�����N��T���ăf�[�^�`�����擾
	if (!searchChunk(fstr, "fmt "))
	{
		std::cout << "fmt�`�����N�����݂��܂���" << std::endl;
		return false;
	}
	u_int chunk_size = Audio::Wav::getChunkSize(fstr);
	std::vector<char> chunk(chunk_size);
	fstr.read(&chunk[0], chunk_size);
	info.id = Audio::Wav::getValue(&chunk[WAV_ID], 2);
	info.ch = Audio::Wav::getValue(&chunk[WAV_CH], 2);
	info.sample_rate = Audio::Wav::getValue(&chunk[WAV_SAMPLE_RATE], 4);
	info.bit = Audio::Wav::getValue(&chunk[WAV_BIT], 2);
	// data�`�����N��T���ăf�[�^�����擾
	if (!searchChunk(fstr, "data"))
	{
		std::cout << "data�`�����N�����݂��܂���" << std::endl;
		return false;
	}
	info.size = Audio::Wav::getChunkSize(fstr);
	return true;
}
//---------------------------------
//@:StreamWavclass
//---------------------------------
Audio::StreamWav::StreamWav(const std::string& file) :
	fstr_(file, std::ios::binary),
	loop_(false)
{
	if (!this->fstr_) throw "�t�@�C�����J�����Ƃ��ł��܂���";
	// �t�@�C���������
	if (!Wav::analyzeWavFile(this->info, this->fstr_))
	{
		return;
	}
	if ((this->info.id != 1) || (this->info.bit != 16))
	{
		// ID���P�ŗʎq���r�b�g����16�ȊO�͈���Ȃ�
		std::cout << "Wav�t�@�C���t�H�[�}�b�g�G���[" << std::endl;
		return;
	}
	this->last_size_ = this->info.size;
	// �f�[�^�̐擪�ʒu���o���Ă���
	this->top_pos_ = static_cast<size_t>(this->fstr_.tellg());
}
bool Audio::StreamWav::isStereo() const
{
	return this->info.ch == 2;
}
u_int Audio::StreamWav::sampleRate() const
{
	return this->info.sample_rate;
}
size_t Audio::StreamWav::GetlastSize() const
{
	return this->last_size_;
}
void Audio::StreamWav::loop(const bool loop)
{
	this->loop_ = loop;
}
void Audio::StreamWav::toTop()
{
	this->fstr_.seekg(this->top_pos_, this->fstr_.beg);
	this->last_size_ = this->info.size;
}
bool Audio::StreamWav::isEnd() const
{
	return last_size_ == 0;
}
size_t Audio::StreamWav::read(std::vector<char>& buffer)
{
	size_t remain_size = buffer.size();
	// ���[�v���Ȃ��ꍇ�A�c��̒��r���[�ȃT�C�Y��ǂݍ���ŏI��
	if (!this->loop_ && (this->last_size_ < remain_size))
	{
		remain_size = this->last_size_;
	}
	size_t offset = 0;
	size_t total_read_size = 0;
	// ���[�v�Đ��̏ꍇ�̓o�b�t�@�𖞂����܂Ńf�[�^��ǂݍ���
	while (remain_size > 0) {
		size_t read_size = Audio::StreamWav::readData(buffer, offset, remain_size);

		total_read_size += read_size;
		remain_size -= read_size;
		this->last_size_ -= read_size;
		offset += read_size;
		if (this->loop_ && !this->last_size_)
		{
			Audio::StreamWav::toTop();
		}
	}
	return total_read_size;
}
size_t Audio::StreamWav::readData(std::vector<char>& buffer, const size_t offset, const size_t size)
{
	size_t read_size = (size < this->last_size_) ? size : this->last_size_;
	this->fstr_.read(&buffer[offset], read_size);
	return read_size;
}