#pragma once
#include "OG\OGsystem.h"

/**
*@brief	画面遷移時に使うフェードインアウト
*アニメーションさせるかで処理が変わる
*/
class Load : public SceneTask
{
	explicit Load();
public:
	static Load* Create();
	virtual ~Load();
};