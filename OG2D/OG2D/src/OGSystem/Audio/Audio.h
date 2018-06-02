#pragma once
#include "OGSystem\_OGsystem.h"

class Audio
{
public:
	Audio();
	~Audio();
	typedef std::shared_ptr<Audio> SP;
	static SP Create();
private:
	ALCdevice* device;
	ALCcontext*context;
public:
};
class Buffer
{
public:
	Buffer();
	explicit Buffer(const std::string& path_);
	~Buffer();
	ALuint id_;
	float nowTime;
	float GetTime() const;
	ALuint GetID() const;
	void Bind(const bool stereo, const void* data, const u_int size, const u_int rate) const;
};
class Source
{
public:
	Source();
	~Source();
	ALuint id_;
	void BindBuffer(const Buffer& buffer_);
	void UnBindBuffer() const;
	ALuint GetID() const;
	void Play() const;
	void Stop() const;
	void Pause() const;
	void Volume(const float volume_) const;
	void Pitch(const float value_) const;
	void Looping(const bool loop_) const;
	bool isPlay() const;
	float currenttime() const;
	void queueBuffer(const Buffer& buffer_) const;
	ALuint UnqueueBuffer() const;
	int processed() const;
};
class Wav
{
public:
	struct Info {
		u_int id;
		u_int ch;
		u_int sample_rate;
		u_int bit;
		u_int size;
	};
	explicit Wav(const std::string& file);
	//�`�����l������Ԃ�
	u_int channel() const;
	//�f�[�^���X�e���I�Ȃ�true��Ԃ�
	bool isStereo() const;
	//�T���v�����O���[�g��Ԃ�
	u_int sampleRate() const;
	//�f�[�^�T�C�Y��Ԃ�
	u_int size() const;
	//�Đ����Ԃ�Ԃ�
	float time() const;
	//�g�`�f�[�^��Ԃ�
	const char* data() const;
	//wav�̏����擾
	static bool analyzeWavFile(Info& info, std::ifstream& fstr);
private:
	Info info;
	float time_;
	std::vector<char> data_;
	//�w��o�C�g���̃������̓��e��int�l�ɂ���
	static u_int getValue(const char* ptr, const u_int num);
	//wav�̎w��`�����N��T��
	static bool searchChunk(std::ifstream& fstr, const char* chunk);
	//�`�����N�̃T�C�Y���擾
	static u_int getChunkSize(std::ifstream& fstr);
};
class StreamWav {
public:
	explicit StreamWav(const std::string& file);
	bool isStereo() const;
	u_int sampleRate() const;
	void loop(const bool loop);
	//�Đ��ʒu��擪�ɖ߂�
	void toTop();
	bool isEnd() const;
	size_t GetlastSize() const;
	//�Đ��o�b�t�@�Ƀf�[�^��ǂݍ���
	size_t read(std::vector<char>& buffer);
private:
	std::ifstream fstr_;
	Wav::Info info;
	size_t top_pos_;
	bool loop_;
	size_t last_size_;
	//�t�@�C������o�b�t�@�փf�[�^��ǂݍ���
	size_t readData(std::vector<char>& buffer, const size_t offset, const size_t size);
};