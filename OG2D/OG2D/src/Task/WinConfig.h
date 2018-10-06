#pragma once
#include "OGSystem\OGsystem.h"

class ConfigTask : public SceneTask
{
	//! ŸScene‚©‚ç‚ÌWindowMode’l
	bool nextWindowMode;
	/**
	*@brief	:constructor
	*/
	explicit ConfigTask();
	/**
	*@brief	:XVˆ—
	*/
	void Update() override;
	/**
	*@brief	:©•ªíœˆ—
	*@param	:bool flag NextWindowMode
	*/
	void Destroy(const bool flag);
public:
	/**
	*@brief	:destructor
	*/
	virtual ~ConfigTask();
	/**
	*@brief	:Scene¶¬
	*@return:ConfigTask* ¶¬Scene
	*/
	static ConfigTask* Create();
};