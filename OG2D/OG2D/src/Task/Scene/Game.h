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
	*@brief	Scene生成
	*@return Game* 生成したScene
	*/
	static Game* Create();
	/**
	*@brief	destructor
	*/
	virtual ~Game();
};