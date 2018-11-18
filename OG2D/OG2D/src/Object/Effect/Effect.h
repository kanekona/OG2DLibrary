#pragma once
#include "OGSystem\ResourceManager\ResourceManager.h"
#include "OG\_OGsystem.h"
#include "Object\GameObject.h"
#include <Windows.h>
/**
*State�Ɠ��l�ɐ݌v���邪�A
*�X�V�����͕`�揈����EngineSystem�ɓo�^���Ď����I�ɍs�킹��
*���̂��ߑ匳��GameObject���g�p����
*�����蔻��n��nullptr�ɂ���Όy���Ȃ�H
*/

class Effect : public GameObject
{
	virtual void Update() = 0;
};

class EffectManager : private NonCopyable
{
	std::unordered_map<std::string, Effect*> data;
public:
	explicit EffectManager();
	void SetEffect(const std::string& tag, Effect* effect);
	Effect* GetEffect(const std::string& tag) const;
};

class LayerEffect : public Effect
{
	void Update() override;
};

class TextureEffect : public Effect
{
	void Update() override;
};