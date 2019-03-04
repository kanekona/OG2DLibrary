#pragma once
#include "NonCopyable\NonCopyable.hpp"
#include "Scene\Scene.h"
#include "Window\Window.h"
/**
*@brief	‰Šú‰»class
*‰Šú‰»‚É•K—v‚È’l‚ğ“n‚µ‚½‚è‚·‚éclass
*/
class Initializer : private NonCopyable
{
public:
	/**
	*@brief	Window‚Ìİ’è‚ğ“n‚·
	*@return WindowParameter Window Parameter
	*/
	WindowParameter ConfigWindow();
	/**
	*@brief	Begin Scene Adaptation
	*/
	Scene* SceneAdaptation();
};