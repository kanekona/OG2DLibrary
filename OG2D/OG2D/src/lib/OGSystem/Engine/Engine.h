#pragma once
#include "Framework.h"
#include "FPS\FPS.h"
#include "Audio\Audio.h"
#include "Initializer.h"
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
	//! Engine Initializer
	Initializer* initializer;
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
	*@brief	�V�X�e���X�V
	*@return bool System Continuation
	*/
	bool SystemUpdate();
};