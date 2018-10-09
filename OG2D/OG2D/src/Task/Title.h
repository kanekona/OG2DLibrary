#pragma once
#include "OG\OGsystem.h"

class Title : SceneTask
{
	/**
	*@brief	constructor
	*/
	explicit Title();
public:
	/**
	*@brief	Scene生成
	*@return Title* 生成したScene
	*/
	static Title* Create();
	/**
	*@brief	destructor
	*/
	virtual ~Title();
};