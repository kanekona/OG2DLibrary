#include "Sound.h"
//---------------------------------
//@:Soundclass
//---------------------------------
Sound::Sound()
	:filepath_("./data/bgm/")
{

};
Sound::Sound(const std::string& path_, const bool loop) :
	buffer(std::make_shared<Buffer>(filepath_ + path_)),
	source(std::make_shared<Source>()),
	filepath_("./data/bgm/")
{
	this->source->BindBuffer(*this->buffer);
	this->Looping(loop);
	this->Pitch(1.0f);
	this->volume_ = 1.0f;
	this->Volume(this->volume_);
}
Sound::~Sound()
{

};
bool Sound::Create(const std::string& path_, const bool loop)
{
	this->buffer = std::make_shared<Buffer>(filepath_ + path_);
	this->source = std::make_shared<Source>();
	this->source->BindBuffer(*this->buffer);
	this->Looping(loop);
	this->Pitch(1.0f);
	this->volume_ = 1.0f;
	this->Volume(this->volume_);
	return true;
}
void Sound::Play() const
{
	this->source->Play();
}
void Sound::Stop() const
{
	this->source->Stop();
}
void Sound::Pause() const
{
	this->source->Pause();
}
void Sound::Volume(const float value_) const
{
	this->source->Volume(value_);
}
void Sound::Pitch(const float value_) const
{
	this->source->Pitch(value_);
}
void Sound::Looping(const bool loop_) const
{
	this->source->Looping(loop_);
}
bool Sound::IsPlay() const
{
	return this->source->isPlay();
}
float Sound::CurrentTime() const
{
	return this->source->currenttime();
}
float Sound::Duration() const
{
	return this->buffer->GetTime();
}
void Sound::SetVolume(float maxVolume_)
{
	this->volume_ = maxVolume_;
}
float Sound::GetVolume() const
{
	return this->volume_;
}