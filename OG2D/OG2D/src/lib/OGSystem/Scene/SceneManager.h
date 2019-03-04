#pragma once
#include "Scene.h"

class SceneManager : private NonCopyable
{
	Scene* nowScene;
	Scene* nextScene;
	/**
	*@brief Scene Change Adaptation
	*/
	void ChangeAdaptation();
public:
	/**
	*@brief	Scene Change
	*@param[in] Scene* nextScene NextScene
	*/
	void ChangeScene(Scene* nextScene);
	/**
	*@brief Scene Update
	*/
	void SceneUpdate();
	/**
	*@brief Get Now Scene
	*@return Scene* Now Scene
	*/
	Scene* Get();
	/**
	*@brief	constructor
	*@param[in] Scene* begin Start Scene
	*/
	explicit SceneManager(Scene* begin);
};