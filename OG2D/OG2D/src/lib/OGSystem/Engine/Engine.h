#pragma once
#include "Framework.h"
#include "FPS\FPS.h"
#include "Audio\Audio.h"
#define ERROR_GLFE_INIT 0x01
#define ERROR_GLEW_INIT 0x02
/**
*@brief	Game Engine
*/
class Engine : private NonCopyable
{
	//! frame rate
	FPS fps;
	//! Main Framework
	Framework* framework;
	//! MainFrame Window Address
	Window* window;
	//! Audiodevice
	Audio* audiodevice;
	//! Enable
	bool enable;
	/**
	*@brief	Outside Library Initializer
	*/
	void OutsideLibraryInitialize();
	/**
	*@brief	OpenGL OpenFW Initialize
	*/
	void GLFWInitialize();
public:
	/**
	*@brief	constructor
	*/
	explicit Engine();
	/**
	*@brief	destructor
	*/
	virtual ~Engine();
	/**
	*@brief	システム更新
	*@return bool System Continuation
	*/
	bool SystemUpdate();
};