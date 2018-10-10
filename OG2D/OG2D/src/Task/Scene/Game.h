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
	*@brief	Scene����
	*@return Game* ��������Scene
	*/
	static Game* Create();
	/**
	*@brief	destructor
	*/
	virtual ~Game();
};