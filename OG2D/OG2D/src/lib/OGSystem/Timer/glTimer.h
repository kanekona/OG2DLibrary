
#pragma once
#include "OG\_OGsystem.h"
/**
*@brief	実時間を導くためのclass
*/
class Time : private NonCopyable
{
	//! 初期タイム
	float initTime;
	//! 現在タイム
	float nowTime;
	//! 停止中のタイムの保存
	float saveTime;
	//! 追加タイム
	float addTime;
	//! 計測中判定
	bool isPlay;
	//! 動作中判定
	bool behavior;
public:
	/**
	*@brief	constructor
	*/
	explicit Time();
	/**
	*@brief	destructor
	*/
	virtual ~Time();
	/**
	*@brief	計測開始
	*/
	void Start();
	/**
	*@brief	計測停止
	*/
	void Stop();
	/**
	*@brief	一時停止
	*/
	void Pause();
	/**
	*@brief	現在タイムを返す
	*@return float 現在のタイム
	*/
	float GetTime();
	/**
	*@brief	開始タイムの変更
	*@param[in] float time_ 初期時のタイム
	*/
	void InitTime(const float time_);
	/**
	*@brief	計測判定
	*@return bool 計測を行っているか調べる
	*/
	bool IsPlay() const;
};