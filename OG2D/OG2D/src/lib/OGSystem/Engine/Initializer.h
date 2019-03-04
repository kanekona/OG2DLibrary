#pragma once
#include "NonCopyable\NonCopyable.hpp"
#include "Scene\Scene.h"
#include "Window\Window.h"
/**
*@brief	������class
*�������ɕK�v�Ȓl��n�����肷��class
*/
class Initializer : private NonCopyable
{
public:
	/**
	*@brief	Window�̐ݒ��n��
	*@return WindowParameter Window Parameter
	*/
	WindowParameter ConfigWindow();
	/**
	*@brief	Begin Scene Adaptation
	*/
	Scene* SceneAdaptation();
};