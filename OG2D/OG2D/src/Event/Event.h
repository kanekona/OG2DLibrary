#pragma once
#include "OGSystem\OGsystem.h"
/**
*enum Event
*@brief	読み込むイベントの種類
*/
enum Event
{
	//! リソース読み込みイベント
	RESOURCE_LOAD,
};
/**
*@brief	イベントタスク
*/
class EventTask
{
	//! ファイル情報
	std::ifstream ifs;
public:
	/**
	*@brief	constructor
	*/
	explicit EventTask();
	/**
	*@brief	destructor
	*/
	virtual ~EventTask();
	/**
	*@brief	イベントを読み込む
	*@param[in]	Event eventType 生成するEventの種類
	*@param[in]	string path 読み込むEventファイルのパス
	*@return	bool 成功true
	*/
	bool Load(const Event& eventType, const std::string& path);
};