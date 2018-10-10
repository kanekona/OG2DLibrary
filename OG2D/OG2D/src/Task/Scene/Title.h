#pragma once
#include "OG\OGsystem.h"

class Title : public SceneTask
{
	/**
	*@brief	constructor
	*/
	explicit Title();
	/**
	*@brief	XVˆ—
	*/
	void Update() override;
public:
	/**
	*@brief	Scene¶¬
	*@return Title* ¶¬‚µ‚½Scene
	*/
	static Title* Create();
	/**
	*@brief	destructor
	*/
	virtual ~Title();
};