#pragma once
#include "OG\OGsystem.h"

class Title : public SceneTask
{
	/**
	*@brief	constructor
	*/
	explicit Title();
	/**
	*@brief	�X�V����
	*/
	void Update() override;
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