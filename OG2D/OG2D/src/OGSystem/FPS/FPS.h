/**
*フレームレートを計算,制限(未実装)するclass
*既存GameEngineを使用している場合はDEBUG時のみ自動で生成される
*/
#pragma once
#include "OGSystem\_OGsystem.h"

class FPS {
public:
	/**
	*@brief	:constructor
	*/
	FPS();				
	/**
	*@brief	:destructor
	*/
	~FPS();
	/**
	*@brief	:更新処理
	*/
	void Update();
private:
	//! 全フレームタイム
	float lastTime;		
	//! カウント数
	int count;	
	//! fps値
	GLfloat fps;
};
