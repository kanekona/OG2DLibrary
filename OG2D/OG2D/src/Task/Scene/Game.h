#pragma once
#include "OG\OGsystem.h"

class Game : public SceneTask
{
	/**
	*@brief	constructor
	*/
	explicit Game();
public:
	/**
	*@brief	Sceneê∂ê¨
	*@return Game* ê∂ê¨ÇµÇΩScene
	*/
	static Game* Create();
	/**
	*@brief	destructor
	*/
	virtual ~Game();
};