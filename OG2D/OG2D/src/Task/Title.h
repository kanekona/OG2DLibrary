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
	*@brief	Scene����
	*@return Title* ��������Scene
	*/
	static Title* Create();
	/**
	*@brief	destructor
	*/
	virtual ~Title();
};