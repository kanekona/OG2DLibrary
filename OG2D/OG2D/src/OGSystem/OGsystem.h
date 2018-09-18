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
#include "Font\TextureFont.h"
#include "TaskObject.h"
/**
*@brief	:描画順を管理するclass
*/
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
/**
*@brief	:メインシステム処理
*/
class EngineSystem
{
	//! 終了状況
	bool end;
	//! WindowSize_W
	int w_wi;
	//! WindowSize_H
	int w_he;
	//! WindowName
	const char* w_na;
	//! WindowMode
	bool w_sc;
	//! カーソル可視化
	bool Cursor_on;
	//! ファイルパス
	const std::string path;
	//! ファイル名
	std::string file;
	//! WindowPosition
	Vec2 w_pos;	
	//! 描画順
	std::vector<OrderCheck> Orders;
	//! Engine終了状況
	bool DeleteEngine;
	//! 登録タスク
	std::vector<std::pair<unsigned short, TaskObject*>> taskObjects;
	//! 登録予定タスク
	std::vector<TaskObject*> addTaskObjects;
public:
	//! カメラ2D
	Camera2D * camera;
	//! window
	Window* window;
	//! フレームレート
	FPS* fps;
	//! デバイス管理
	Audio* audiodevice;
	//! サウンド管理
	SoundManager* soundManager;
	//! 入力管理
	Input* in;
	//! デバッグ機能
	bool DebugFunction;
	/**
	*@brief	:constructor
	*/
	EngineSystem();
	/**
	*@brief	:constructor
	*@param	:int x WindowSizeX
	*@param	:int y WindowSizeY
	*@param	:char* name WindowName
	*@param	:bool flag ScreenMode
	*/
	EngineSystem(
		const int x,
		const int y,
		const char* name,
		const bool flag = false);
	/**
	*@brief	:destructor
	*/
	~EngineSystem();
	/**
	*@brief	:初期化処理
	*@return:成功でtrue
	*/
	bool Initialize();
	/**
	*@brief	:System更新処理
	*/
	void Update();
	/**
	*@brief	:Window情報登録
	*@param	:int x WindowSizeX
	*@param	:int y WindowSizeY
	*@param	:char* name WindowName
	*@param	:bool flag ScreenMode
	*/
	void SetWindow(
		const int x,
		const int y,
		const char* name,
		const bool flag = false);
	/**
	*@brief	:Window生成位置登録
	*@param	:Vec2 pos 位置情報
	*/
	void SetWindowPos(const Vec2& pos);
	/**
	*@brief	:カーソル可視化設定
	*@param	:bool flag 可視化設定
	*/
	void SetCursorOn(const bool flag);
	/**
	*@brief	:アイコン画像設定
	*@param	:string path ファイルパスファイルパス
	*/
	void SetIcon(const std::string& path);
	/**
	*@brief	:全タスクの停止設定
	*@param	:bool flag 停止設定
	*/
	void AllStop(const bool flag = true);
	/**
	*@brief	:全タスクのポーズ設定
	*@param	:bool flag ポーズ設定
	*/
	void AllPause(const bool flag = true);
	/**
	*@brief	:アプリケーション終了
	*/
	void GameEnd();
	/**
	*@brief	:終了設定を返す
	*@return:bool 終了設定
	*/
	bool GetEnd() const;
	/**
	*@brief	:タスク変更時処理
	*/
	void ChengeTask();
	/**
	*@brief	:タスク達の更新処理
	*/
	void TaskGameUpDate();
	/**
	*@brief	:タスクを登録する
	*@param	:TaskObject* task タスク
	*/
	void SetTaskObject(
		TaskObject* task);
	/**
	*@brief	:エンジン終了を返す
	*@return:bool エンジン終了設定
	*/
	bool GetDeleteEngine();
	/**
	*@brief	:エンジン終了を登録
	*@param	:bool falg 終了設定
	*/
	void SetDeleteEngine(const bool flag);
	/**
	*@brief	:登録されているタスクを表示する
	*/
	void ShowNameAddedObject();
	/**
	*@brief	:タスク検索(最初の同名のタスクを返す)
	*@param	:string taskName タスク名
	*@return:指定単体タスクclass
	*/
	template <class T> T* GetTask(const std::string& taskName)
	{
		for (auto id = this->taskObjects.begin(); id != this->taskObjects.end(); ++id)
		{
			if (id->second)
			{
				if (id->second->GetTaskName() == taskName)
				{
					return (T*)id->second;
				}
			}
		}
		for (auto id = this->addTaskObjects.begin(); id != this->addTaskObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTaskName() == taskName)
				{
					return (T*)(*id);
				}
			}
		}
		return nullptr;
	}
	/**
	*@brief	:タスク検索(同名すべてを返す)
	*@param	:string taskName タスク名
	*@return:指定複数タスクclass
	*/
	template <class T> std::vector<T*> GetTasks(const std::string& taskName)
	{
		std::vector<T*> w;
		for (auto id = this->taskObjects.begin(); id != this->taskObjects.end(); ++id)
		{
			if (id->second)
			{
				if (id->second->GetTaskName() == taskName)
				{
					w.push_back((T*)id->second);
				}
			}
		}
		for (auto id = this->addTaskObjects.begin(); id != this->addTaskObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTaskName() == taskName)
				{
					w.push_back((T*)(*id));
				}
			}
		}
		return w;
	}
private:
	/**
	*@brief	:登録予定タスクを登録する
	*/
	void TaskApplication();
	/**
	*@brief	:描画順を設定する
	*/
	void ConfigDrawOrder();
	/**
	*@brief	:登録予定タスクの有無
	*@return:登録予定タスクが存在すればtrue
	*/
	bool CheckAddTask();
	/**
	*@brief	:削除予定タスクの有無
	*@return:削除予定タスクが存在すればtrue
	*/
	bool CheckKillTask();
	/**
	*@brief	:タスク更新処理
	*/
	void Task_UpDate();
	/**
	*@brief	:タスク描画処理
	*/
	void Task_Render_AF();
	/**
	*@brief	:削除予定タスクを削除する
	*/
	void TaskKillCheck();
	/**
	*@brief	:登録タスク全削除
	*/
	void AllTaskDelete();
};

extern EngineSystem* OGge;
extern ResourceManager* rm;