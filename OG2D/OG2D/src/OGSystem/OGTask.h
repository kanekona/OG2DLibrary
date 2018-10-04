#pragma once
//_____________________________
//|タスクシステム               
//|履歴：2018/03/20    
//|____________________________
#include "OGSystem\OGsystem.h"
/**
*TaskSystem
*/
class OGTK
{
public:
	/**
	*@brief	:GammeEngineの初期化時に設定したい処理を行う初期化関数
	*/
	void Init();
	/**
	*@brief	:開始時に生成したいタスクを指定する関数
	*/
	void StartTaskObject();
	/**
	*@brief	:destructor
	*/
	virtual ~OGTK();
};