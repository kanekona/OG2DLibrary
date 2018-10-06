#pragma once
#include "OGSystem\OGsystem.h"

class ConfigTask : public SceneTask
{
	//! ��Scene�����WindowMode�l
	bool nextWindowMode;
	/**
	*@brief	:constructor
	*/
	explicit ConfigTask();
	/**
	*@brief	:�X�V����
	*/
	void Update() override;
	/**
	*@brief	:�����폜����
	*@param	:bool flag NextWindowMode
	*/
	void Destroy(const bool flag);
public:
	/**
	*@brief	:destructor
	*/
	virtual ~ConfigTask();
	/**
	*@brief	:Scene����
	*@return:ConfigTask* ����Scene
	*/
	static ConfigTask* Create();
};