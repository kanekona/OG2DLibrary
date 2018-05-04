#pragma once
//_____________________________
//|システムクラス２             
//|履歴：2018/03/20       
//|履歴：2018/03/23		   
//|____________________________
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
#include "Random\Random.h"
#include "TaskObject.h"

class EngineSystem
{
public:
	EngineSystem();
	EngineSystem(int,int,char*,bool = false);
	~EngineSystem();
	Camera2D::SP camera;
	Window::SP window;
	FPS::SP fps;
	Audio::SP audiodevice;
	SoundManager::SP soundManager;
	Input in;
	std::vector<std::pair<DWORD, TaskObject::SP>> taskobjects;
	std::vector<TaskObject::SP> addTaskObjects;
	void Initialize();
	void Update();
	void SetWindow(int,int,char*,bool = false);
	void SetWindowPos(Vec2&);
	void SetCursorOn(const bool);
	void SetIcon(std::string);
	bool DebugFunction;
	void SetPause(const bool);
	bool GetPause() const;
	void GameEnd();
	bool GetEnd() const;
	void ChengeTask();
	void Task_UpDate();
	void Task_Render_AF();
	void TaskGameUpDate();
	void TaskKillCheck();
	void SetTaskObject(const TaskObject::SP&);
	void KillTask(const TaskObject::SP&);
	void AllTaskDelete();
	bool GetDeleteEngine();
	void SetDeleteEngine(bool);
private:
	bool end;
	int w_wi;
	int w_he;
	char* w_na;
	bool w_sc;;
	bool isPause;
	bool Cursor_on;
	std::string path = "./data/image/";
	std::string file;
	Vec2 w_pos;
	bool DeleteEngine;
	void TaskApplication();
};

extern EngineSystem* OGge;