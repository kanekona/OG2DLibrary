
#pragma once
#include "OGsystem.h"
/**
*@brief	System
*既存GameEngineClassを使用する場合OGSystem
*使用しない場合_OGSystem(こちら用は未制作)
*/
class OGSystem : private NonCopyable
{
public:
	/**
	*@brief	constructor
	*/
	explicit OGSystem();
	/**
	*@brief	システム生成
	*@return bool 成功true
	*/
	bool Create();
	/**
	*@brief	更新チェック
	*@return bool 続行true
	*/
	bool LibConfirmation();
	/**
	*@brief	destructor
	*/
	virtual ~OGSystem();
};