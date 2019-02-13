#include "Effect.h"

EffectManager::EffectManager()
{

}

void EffectManager::Set(const std::string& tag, Effect* effect)
{
	this->data[tag] = effect;
}

Effect* EffectManager::Get(const std::string& tag)
{
	return this->data[tag];
}

void EffectManager::Delete(const std::string& tag)
{
	this->data.erase(tag);
}

void Effect::Update()
{
	++this->timeCnt;
	this->Active();
}

unsigned int Effect::GetTimeCnt() const
{
	return this->timeCnt;
}

LayerTexture* LayerEffect::GetTexture()
{
	return this->texture;
}

Texture* TextureEffect::GetTexture()
{
	return this->texture;
}