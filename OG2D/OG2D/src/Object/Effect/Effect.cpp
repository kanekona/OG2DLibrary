#include "Effect.h"

EffectManager::EffectManager()
{

}

void EffectManager::SetEffect(const std::string& tag, Effect* effect)
{
	this->data[tag] = effect;
}

Effect* EffectManager::GetEffect(const std::string& tag)
{
	return this->data[tag];
}

unsigned int Effect::GetTimeCnt() const
{
	return this->timeCnt;
}