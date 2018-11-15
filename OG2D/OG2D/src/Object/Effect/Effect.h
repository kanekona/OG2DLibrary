#pragma once
#include "OGSystem\ResourceManager\ResourceManager.h"
#include "OG\_OGsystem.h"
#include "Object\GameObject.h"
/**
*Stateと同様に設計するが、
*更新処理は描画処理はEngineSystemに登録して自動的に行わせる
*そのため大元はGameObjectを使用する
*当たり判定系をnullptrにすれば軽くなる？
*/
class EffectManager : private NonCopyable
{
	ResourceManager* rm;
public:
	explicit EffectManager(ResourceManager* manager);
};