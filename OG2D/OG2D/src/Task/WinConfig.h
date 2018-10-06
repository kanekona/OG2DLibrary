#pragma once
#include "OGSystem\OGsystem.h"

class ConfigTask : public SceneTask
{
	//! 次SceneからのWindowMode値
	bool nextWindowMode;
	/**
	*@brief	:constructor
	*/
	explicit ConfigTask();
	/**
	*@brief	:更新処理
	*/
	void Update() override;
	/**
	*@brief	:自分削除処理
	*@param	:bool flag NextWindowMode
	*/
	void Destroy(const bool flag);
public:
	/**
	*@brief	:destructor
	*/
	virtual ~ConfigTask();
	/**
	*@brief	:Scene生成
	*@return:ConfigTask* 生成Scene
	*/
	static ConfigTask* Create();
};