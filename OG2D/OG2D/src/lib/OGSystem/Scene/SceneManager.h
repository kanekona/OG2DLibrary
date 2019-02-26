#pragma once
#include "Scene.h"

class SceneManager : private NonCopyable
{
	Scene* nowScene;
	Scene* nextScene;
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
	*@brief Scene Change Adaptation
	*/
	void ChangeAdaptation();
	/**
	*@brief Get Now Scene
	*@return Scene* Now Scene
	*/
	Scene* Get();
};