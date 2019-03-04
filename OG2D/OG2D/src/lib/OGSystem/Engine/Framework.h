#pragma once
#include "Scene\SceneManager.h"
#include "NonCopyable\NonCopyable.hpp"
#include "Window\Window.h"
/**
*@brief Game Framework
*/
class Framework : private NonCopyable
{
	//! Scene Manager
	SceneManager* sceneManager;
	//! Window
	Window* window;
	//! Enable Engine Destroy
	bool* enableEngineDestroy;
	//! FrameworkInstance
	static Framework* instance;
	/**
	*@brief	constructor
	*@param[in] bool* destroy Engine Destroy Frag Address
	*/
	explicit Framework(bool* destroy);
	/**
	*@brief	destructor
	*/
	virtual ~Framework();
public:
	/**
	*@brief Get FrameworkInstance
	*@return Framework* Instance
	*/
	static Framework* Get();
	/**
	*@brief	Create Framework Instance
	*@param[in] bool* destroy Engine Destroy Frag Address
	*@return Framework* Get Framework Instance
	*@detail ä˘Ç…ê∂ê¨Ç≥ÇÍÇƒÇ¢ÇÈèÍçáÇÕâΩÇ‡çsÇ¢Ç‹ÇπÇÒ
	*/
	static Framework* Create(bool* destroy);
	/**
	*@brief	Instance Destroy
	*/
	static void Destroy();
	/**
	*@brief Change Next Scene
	*@param[in] Scene* next NextScene
	*/
	void ChangeScene(Scene* next);
	/**
	*@brief	Get Now Scene
	*@return Scene* Now Scene
	*/
	Scene* GetScene();
	/**
	*@brief	Get Window
	*/
	Window* GetWindow();
	/**
	*@brief Framework Update
	*/
	void Update();
	/**
	*@brief	Engine Destroy
	*/
	void EngineDestroy();
	/**
	*@brief	Create SceneManager
	*@param[in] Scene* begin Start Scene
	*/
	void CreateSceneManager(Scene* begin);
};
