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
#include "Texture\Texture.h"
#include "Collision\Collision.h"
#include "Font\Font.h"
#include "Audio\SoundManager.h"
#include "Timer\glTimer.h"
#include "Easing\easing.hpp"
#include "Audio\StreamingSound.h"
#include "Random\Random.h"
#include "ResourceManager\ResourceManager.h"
#include "TaskObject.h"

class OrderCheck
{
public:
	OrderCheck()
	{
		this->id = -1;
		this->order_s = -1.f;
	}
	int id;
	float order_s;
};

class EngineSystem
{
	bool end;			//終了状況
	int w_wi;			//WindowSize
	int w_he;			//WindowSize
	char* w_na;			//WindowName
	bool w_sc;			//WindowMode
	bool isPause;		//PauseCheck
	bool Cursor_on;		//カーソル可視化
	const std::string path;	//ファイルパス
	std::string file;	//ファイル名
	Vec2 w_pos;			//WindowPosition
	std::vector<OrderCheck> Orders;	//描画順
	bool DeleteEngine;	//Engine終了状況
	std::vector<std::pair<DWORD, TaskObject::SP>> taskobjects;	//タスクオブジェクト達
	std::vector<TaskObject::SP> addTaskObjects;	//登録予定タスク達
	std::vector<std::pair<DWORD, TaskObject*>> taskobjects_;
	std::vector<TaskObject*> addTaskObjects_;
public:
	Camera2D * camera;		//カメラ2D
	Window* window;			//window
	FPS* fps;				//フレームレート
	Audio* audiodevice;		//デバイス管理
	SoundManager* soundManager;	//サウンド管理
	Input* in;				//入力管理
	bool DebugFunction;			//デバッグ機能
	EngineSystem();			//コンストラクタ
	EngineSystem(			//コンストラクタ
		const int,
		const int,
		char*,
		const bool = false);
	~EngineSystem();		//デストラクタ
	
	bool Initialize();		//初期化処理
	void Update();			//更新処理
	void SetWindow(			//Window情報登録
		const int,
		const int,
		char*,
		const bool = false);
	void SetWindowPos(const Vec2&);	//Window生成位置設定
	void SetCursorOn(const bool);	//カーソル可視化有無
	void SetIcon(const std::string&);	//アイコン使用画像設定
	void SetPause(const bool);	//ポーズ設定
	bool GetPause() const;		//ポーズを返す
	void GameEnd();				//アプリケーション終了登録
	bool GetEnd() const;		//アプリケーション終了を返す
	void ChengeTask();			//タスク変更時処理
	void TaskGameUpDate();		//タスク達の更新処理
	void SetTaskObject(			//タスクを登録
		const TaskObject::SP&);
	void SetTaskObject(
		TaskObject*);
	bool GetDeleteEngine();		//エンジン終了を返す
	void SetDeleteEngine(const bool);	//エンジン終了登録
	//タスク検索(最初の同名のタスクを返す)
	template <class T> std::shared_ptr<T> GetTask(const std::string& taskName)
	{
		for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
		{
			if ((*id).second)
			{
				if ((*id).second->GetTaskName() == taskName)
				{
					return std::static_pointer_cast<T>((*id).second);
				}
			}
		}
		for (auto id = this->addTaskObjects.begin(); id != this->addTaskObjects.end(); ++id)
		{
			if ((*id))
			{
				if ((*id)->GetTaskName() == taskName)
				{
					return std::static_pointer_cast<T>(*id);
				}
			}
		}
		return nullptr;
	}
	template <class T> std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks(const std::string& taskName)
	{
		std::shared_ptr<std::vector<std::shared_ptr<T>>> w = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>> ());
		for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
		{
			if ((*id).second)
			{
				if ((*id).second->GetTaskName() == taskName)
				{
					w->push_back(std::static_pointer_cast<T>((*id).second));
				}
			}
		}
		for (auto id = this->addTaskObjects.begin(); id != this->addTaskObjects.end(); ++id)
		{
			if ((*id))
			{
				if ((*id)->GetTaskName() == taskName)
				{
					w->push_back(std::static_pointer_cast<T>((*id)));
				}
			}
		}
		return w;
	}
	template <class T> T* GetTask_(const std::string& taskName)
	{
		for (auto id = this->taskobjects_.begin(); id != this->taskobjects_.end(); ++id)
		{
			if (id->second)
			{
				if (id->second->GetTaskName() == taskName)
				{
					return std::static_pointer_cast<T>(id->second);
				}
			}
		}
		for (auto id = this->addTaskObjects_.begin(); id != this->addTaskObjects_.end(); ++id)
		{
			if (id)
			{
				if (id->GetTaskName() == taskName)
				{
					return std::static_pointer_cast<T>(id);
				}
			}
		}
	}
	template <class T> std::vector<T*> GetTasks_(const std::string& taskName)
	{
		std::vector<T*> w = new std::vector<T*>;
		for (auto id = this->taskobjects_.begin(); id != this->taskobjects_.end(); ++id)
		{
			if (id->second)
			{
				if (id->second->GetTaskName() == taskName)
				{
					w->push_back(std::static_pointer_cast<T>(id->second));
				}
			}
		}
		for (auto id = this->addTaskObjects_.begin(); id != this->addTaskObjects_.end(); ++id)
		{
			if (id)
			{
				if (id->GetTaskName() == taskName)
				{
					w->push_back(std::static_pointer_cast<T>(id));
				}
			}
		}
		return w;
	}
private:
	void TaskApplication();	//タスク登録予定を登録する
	void ConfigDrawOrder();	//描画順を設定する
	bool CheckAddTask();	//登録予定のタスクの有無
	bool CheckKillTask();	//削除予定のタスクの有無
	void Task_UpDate();			//タスク更新処理
	void Task_Render_AF();		//タスク描画処理
	void TaskKillCheck();		//削除予定のタスクを削除
	void AllTaskDelete();		//登録タスク全削除
};

extern EngineSystem* OGge;
extern ResourceManager* rm;