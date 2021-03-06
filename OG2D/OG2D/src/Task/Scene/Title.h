#pragma once
#include "OG\OGsystem.h"

class Title : public SceneTask
{
	/**
	*@brief	constructor
	*/
	explicit Title();
	/**
	*@brief	更新処理
	*/
	void Update() override;
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