#pragma once
#include "OGSystem\ResourceManager\ResourceManager.h"
#include "OG\_OGsystem.h"
#include "Object\GameObject.h"
#include "Texture\LayerTexture.h"
#include <Windows.h>
/**
*State�Ɠ��l�ɐ݌v���邪�A
*�X�V�����͕`�揈����EngineSystem�ɓo�^���Ď����I�ɍs�킹��
*���̂��ߑ匳��GameObject���g�p����
*�����蔻��n��nullptr�ɂ���Όy���Ȃ�H
*/

class Effect : public GameObject
{
	unsigned int timeCnt;
public:
	virtual void Active() = 0;
	void Update() final;
	virtual void Render2D() = 0;
	unsigned int GetTimeCnt() const;
};

class EffectManager : private NonCopyable
{
	std::unordered_map<std::string, Effect*> data;
public:
	explicit EffectManager();
	void Set(const std::string& tag, Effect* effect);
	Effect* Get(const std::string& tag);
	void Delete(const std::string& tag);
};

class LayerEffect : public Effect
{
	LayerTexture* texture;
	virtual void Render2D() = 0;
	virtual void Active() = 0;
public:
	LayerTexture* GetTexture();
};

class TextureEffect : public Effect
{
	Texture* texture;
	virtual void Render2D() = 0;
	virtual void Active() = 0;
public:
	Texture* GetTexture();
};

class TestEffect : public TextureEffect
{
	void Active() override final
	{
		if (this->GetTimeCnt() > 10)
		{
			this->Kill();
		}
	}
	void Render2D() override
	{
		this->GetTexture()->Draw(Box2D(), Box2D());
	}
};