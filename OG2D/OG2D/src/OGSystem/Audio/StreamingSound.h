#pragma once
#include "Audio.h"
#include <mutex>
class StreamingSound {
private:
	enum {
		BUFFER_NUM = 2,
		SLEEP_TIME_MS = 250
	};
	std::shared_ptr<Source> source_;
	bool pause_;
	// �Đ��p�̃X���b�h�Ƃ̘A�g
	struct Param {
		std::mutex mutex;
		bool stopped;
		Param() :stopped(false) {}
		bool backStartPos;
		bool DeleteThread;
	};
	std::shared_ptr<Param> param_;
	std::string filepath_;
	bool loop_;
	bool isplay_;
public:
	StreamingSound();
	StreamingSound(const std::string& path, const bool loop = false);
	void gain(const float gain);
	void pause();
	void play();
	void pitch(const float value_) const;
	void stop();
	void DeleteSound();
	bool isPlaying();
	float GetTime() const;
	void debugUpdata();
	void createSound(const std::string& path, bool loop = false);
private:
	static void queueStream(StreamWav& stream, Source &source, Buffer& buffer, std::vector<char>& sound_buffer);
	static void streamProc(const std::string& path, const bool loop, std::shared_ptr<Source>& source, std::shared_ptr<Param>& param);
};