#pragma once
//______________________________//
//|�V�X�e���N���X�Q              |//
//|�����F2018/03/20���q��       |//
//|�����F2018/03/23���q��		   |//
//|____________________________|//
#include "Camera\Camera.h"
#include "Window\Window.h"
#include "FPS\FPS.h"
#include "Input\Input.h"
#include "Font\Font.h"
#include "Texture\Texture.h"
#include "Collision\Collision.h"
#include "Font\Font.h"
#include "Audio\SoundManager.h"
#include "Timer\glTimer.h"
#include "Easing\easing.hpp"
#include "Audio\StreamingSound.h"

class EngineSystem
{
public:
	EngineSystem();
	EngineSystem(int widht, int height, char* name, bool screen);
	~EngineSystem();
	Camera2D::SP camera;
	Window::SP window;
	FPS::SP fps;
	Audio::SP audiodevice;
	SoundManager::SP soundManager;
	Input in;
	void Initialize();
	void Update();
	void SetWindow(int width, int height, char* name, bool screen);
	void SetCursorOn(const bool on);
	void SetIcon(std::string filpath_);
	bool DebugFunction;
	void SetPause(const bool ispause_);
	bool GetPause() const;
	void GameEnd();
	bool GetEnd() const;
	void ChengeTask();
private:
	bool end;
	int w_wi;
	int w_he;
	char* w_na;
	bool w_sc;
	bool isPause;
	bool Cursor_on;
	std::string path = "./data/image/";
	std::string file;
};

extern EngineSystem* gameEngine;