/**
*既存GameEngineClassを使用する場合OGSystem
*使用しない場合_OGSystem
*/
#pragma once
#include "OGsystem.h"
///#include "_OGsystem.h"

class OGSystem : private NonCopyable
{
public:
	/**
	*@brief	:constructor
	*/
	OGSystem();
	/**
	*@brief	:システム生成
	*@return:bool 成功true
	*/
	bool Create();
	/**
	*@brief	:更新チェック
	*@return:bool 続行true
	*/
	bool LibConfirmation();
	/**
	*@brief	:destructor
	*/
	virtual ~OGSystem();
};