
#pragma once
#include "NonCopyable\NonCopyable.hpp"
#include "System\System_.h"
/**
*@brief	フレームレートを計算,制限するclass
*
*既存GameEngineを使用している場合はUpdateをDEBUG時のみ行う
*/
class FPS : private NonCopyable 
{
	//! 全フレームタイム
	float lastTime;
	//! カウント数
	int count;
	//! fps値
	GLfloat fps;
	//! frame rate
	int framerate;
	//! oneframetime
	float oneFrameTime;
	//! FrameCount
	unsigned int frameCount;
	//! StartDeltaTime
	const float startDeltaTime;
	//! DeltaTime
	float delta;
public:
	/**
	*@brief	constructor
	*/
	explicit FPS();				
	/**
	*@brief	destructor
	*/
	virtual ~FPS();
	/**
	*@brief	更新処理
	*/
	void Update();
	/**
	*@bried	フレームレート指定
	*@param[in]	int rate frame rate
	*/
	void SetFrameRate(const int rate);
	/**
	*@brief	フレームチェック
	*@return 秒間フレームに達しているならtrue
	*/
	bool FrameCheck();
	/**
	*@brief Get DeltaTime
	*@return float DeltaTime
	*/
	float DeltaTime();
};
