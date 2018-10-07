#pragma once
#include "OGSystem\OGsystem.h"
/**
*@brief	Engine生成に関する処理を行うclass
*/
class OGTK
{
public:
	/**
	*@brief	GammeEngineの初期化時に設定したい処理を行う初期化関数
	*/
	void Init();
	/**
	*@brief	開始時に生成したいタスクを指定する関数
	*/
	void StartTaskObject();
	/**
	*@brief destructor
	*/
	virtual ~OGTK();
};