#pragma once
#include "OGSystem\OGsystem.h"
#include <mutex>
///制作中！！！
/**
*@brief	:特定classのデータ処理を別スレッドで行うclass
*/
class Param
{
public:
	std::mutex mutex;
	bool flag;
};
class DataThread
{
	//! 解放を行うデータクラス
	TaskObject* object;
	//! 排他的アクセスを行う
	Param* param;
public:
	/**
	*@brief	:constructor
	*/
	DataThread();
	/**
	*@brief	:destructor
	*/
	virtual ~DataThread();
	/**
	*@brief	:解放処理のデータ登録
	*/
	template <class T>void SetData(const TaskObject& t)
	{
		
	}
};
template <class T> class Thread__
{

};

Thread__<TaskObject> thre;