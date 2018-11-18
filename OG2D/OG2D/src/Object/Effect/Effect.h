#pragma once
#include "OGSystem\ResourceManager\ResourceManager.h"
#include "OG\_OGsystem.h"
#include "Object\GameObject.h"
#include <Windows.h>
/**
*Stateと同様に設計するが、
*更新処理は描画処理はEngineSystemに登録して自動的に行わせる
*そのため大元はGameObjectを使用する
*当たり判定系をnullptrにすれば軽くなる？
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