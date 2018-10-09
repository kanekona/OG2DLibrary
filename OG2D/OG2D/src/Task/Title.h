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
	*@brief	Sceneê∂ê¨
	*@return Title* ê∂ê¨ÇµÇΩScene
	*/
	static Title* Create();
	/**
	*@brief	destructor
	*/
	virtual ~Title();
};