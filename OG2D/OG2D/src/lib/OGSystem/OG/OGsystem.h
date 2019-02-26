#pragma once
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
#include "Object\GameObject.h"
#include "Object\SceneTask.h"
#include "Object\UITask.h"
#include "Shader\shader.h"
#include "Order\Order.h"
#include "Texture\LayerTexture.h"
/**
*@brief	sceneを管理するclass
*/
class SceneManager_
{
	//! 現在タスク
	SceneTask* nowScene;
	//! 次のタスク
	SceneTask* nextScene;
	//! 他タスク
	std::vector<SceneTask*> otherScene;
public:
	/**
	*@brief	constructor
	*/
	explicit SceneManager_();
	/**
	*@brief	destructor
	*/
	virtual ~SceneManager_();
	/**
	*@brief	タスクを登録する
	*@param[in]	SceneTask* 現在に登録したいタスク
	*/
	void SetNowTask(SceneTask* task);
	/**
	*@brief	タスクを登録する
	*@param[in]	SceneTask* 次に登録したいタスク
	*/
	void SetNextTask(SceneTask* task);
	/**
	*@brief	タスクを登録する
	*@param[in]	SceneTask* 登録したいタスク
	*/
	void SetOtherTask(SceneTask* task);
	/**
	*@brief	タスクを移行する
	*/
	void SceneMigration();
	/**
	*@brief	他タスクの削除管理
	*/
	void OrtherSceneKillCheck();
	/**
	*@brief	現在タスクを取得
	*@return SceneTask* 現在のタスク
	*/
	SceneTask* GetNowTask() const;
	/**
	*@brief	次タスクを取得
	*@return SceneTask* 次のタスク
	*/
	SceneTask* GetNextTask() const;
	/**
	*@brief	他タスクを全取得
	*@return vector<SceneTask*> 他タスク達
	*/
	std::vector<SceneTask*> GetOtherAllTask() const;
};
/**
*@brief	ゲームエンジン
*/
class EngineSystem : private NonCopyable
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
	bool cursor_on;
	//! ファイルパス
	const std::string path;
	//! ファイル名
	std::string file;
	//! WindowPosition
	Vec2 w_pos;	
	//! Object描画順
	std::vector<OrderCheck> object_orders;
	//! UI描画順
	std::vector<OrderCheck> ui_orders;
	//! Engine終了状況
	bool deleteEngine;
	//! 登録済みGameObject
	std::vector<GameObject*> nowGameObjects;
	//! 登録予定GameObject
	std::vector<GameObject*> addGameObjects;
	//! 登録済みUI
	std::vector<UIObject*> nowUIs;
	//! 登録予定UI
	std::vector<UIObject*> addUIs;
	//! タスク管理
	SceneManager_* _sceneManager;
	//! nextWindowCreate
	bool nextWindowCreateEnable;
	//! デバイス管理
	Audio* audiodevice;
	/**
	*@brief	登録予定タスクを登録する
	*/
	void ObjectApplication();
	/**
	*@brief	Object描画順を設定する
	*/
	void ConfigObjectDrawOrder();
	/**
	*@brief	登録予定タスクの有無
	*@return 登録予定タスクが存在すればtrue
	*/
	bool CheckAddObject();
	/**
	*@brief	削除予定タスクの有無
	*@return 削除予定タスクが存在すればtrue
	*/
	bool CheckKillObject();
	/**
	*@brief	削除予定タスクを削除する
	*/
	void ObjectKillCheck();
	/**
	*@brief	登録予定UIを登録する
	*/
	void UIApplication();
	/**
	*@brief	UI描画順を設定する
	*/
	void ConfigUIDrawOrder();
	/**
	*@brief	登録予定UIの有無
	*@return 登録予定UIが存在すればtrue
	*/
	bool CheckAddUI();
	/**
	*@brief	削除予定UIの有無
	*@return 削除予定UIが存在すればtrue
	*/
	bool CheckKillUI();
	/**
	*@brief	削除予定UIを削除する
	*/
	void UIKillCheck();
	/**
	*@brief	タスク更新処理
	*/
	void Task_Update();
	/**
	*@brief	タスク描画処理
	*/
	void Task_Render_2D();
	/**
	*@brief	登録タスク全削除
	*/
	void AllObjectsDelete();
	/**
	*@brief	Sceneの状態チェック
	*/
	void SceneStateCheck();
	/**
	*@brief	GameObjectsの状態チェック
	*/
	void GameObjectsStateCheck();
	/**
	*@brief	UIsの状態チェック
	*/
	void UIsStateCheck();
public:
	//! カメラ2D
	Camera2D* camera;
	//! window
	Window* window;
	//! フレームレート
	FPS* fps;
	//! サウンド管理
	SoundManager* soundManager;
	//! 入力管理
	Input* in;
	//! デバッグ機能
	bool DebugFunction;
	/**
	*@brief	constructor
	*/
	explicit EngineSystem();
	/**
	*@brief	constructor
	*@param[in]	int x WindowSizeX
	*@param[in]	int y WindowSizeY
	*@param[in]	char* name WindowName
	*@param[in]	bool flag ScreenMode
	*/
	explicit EngineSystem(
		const int x,
		const int y,
		const char* name,
		const bool flag = false);
	/**
	*@brief	destructor
	*/
	virtual ~EngineSystem();
	/**
	*@brief	初期化処理
	*@return 成功でtrue
	*/
	bool Initialize();
	/**
	*@brief	System更新処理
	*/
	void Update();
	/**
	*@brief	Window情報登録
	*@param[in]	int x WindowSizeX
	*@param[in]	int y WindowSizeY
	*@param[in]	char* name WindowName
	*@param[in]	bool flag ScreenMode
	*/
	void SetWindow(
		const int x,
		const int y,
		const char* name,
		const bool flag = false);
	/**
	*@brief	Window情報取得
	*@param[out]	int* x WindowSizeX
	*@param[out]	int* y WindowSizeY
	*@param[out]	bool* flag ScreenMode
	*@param[out]	Vec2* pos WindowPosition
	*/
	void GetWindow(
		int& x,
		int& y,
		bool& flag,
		Vec2& pos);
	/**
	*@brief	Window生成位置登録
	*@param[in]	Vec2 pos 位置情報
	*/
	void SetWindowPos(const Vec2& pos);
	/**
	*@brief	カーソル可視化設定
	*@param[in]	bool flag 可視化設定
	*/
	void SetCursorOn(const bool flag);
	/**
	*@brief	アイコン画像設定
	*@param[in]	string path ファイルパスファイルパス
	*/
	void SetIcon(const std::string& path);
	/**
	*@brief	Window設定処理
	*/
	void WindowConfig();
	/**
	*@brief	全オブジェクトの停止設定
	*@param[in]	bool flag 停止設定
	*/
	void AllObjectStop(const bool flag = true);
	/**
	*@brief	全UIの停止設定
	*@param[in]	bool flag 停止設定
	*/
	void AllUIStop(const bool flag = true);
	/**
	*@brief	全シーンの停止設定
	*@param[in]	bool flag 停止設定
	*/
	void AllSceneStop(const bool flag = true);
	/**
	*@brief	全タスクの停止設定
	*@param[in]	bool flag 停止設定
	*/
	void AllStop(const bool flag = true);
	/**
	*@brief	全オブジェクトのポーズ設定
	*@param[in]	bool flag ポーズ設定
	*/
	void AllObjectPause(const bool flag = true);
	/**
	*@brief	全シーンのポーズ設定
	*@param[in]	bool flag ポーズ設定
	*/
	void AllScenePause(const bool flag = true);
	/**
	*@brief	全UIのポーズ設定
	*@param[in]	bool flag ポーズ設定
	*/
	void AllUIPause(const bool flag = true);
	/**
	*@brief	全タスクのポーズ設定
	*@param[in]	bool flag ポーズ設定
	*/
	void AllPause(const bool flag = true);
	/**
	*@brief	全オブジェクトの削除命令
	*/
	void AllObjectKill();
	/**
	*@brief	全UIの削除命令
	*/
	void AllUIKill();
	/**
	*@brief	全シーンの削除命令
	*/
	void AllSceneKill();
	/**
	*@brief	全タスク削除命令
	*/
	void AllKill();
	/**
	*@brief	アプリケーション終了
	*/
	void GameEnd();
	/**
	*@brief	終了設定を返す
	*@return bool 終了設定
	*/
	bool GetEnd() const;
	/**
	*@brief	次Window生成を行うかを返す
	*@return bool trueなら再びWindowを生成する
	*/
	bool GetNextWindowCreateEnable() const;
	/**
	*@brief	タスク変更時処理
	*/
	void ChengeTask();
	/**
	*@brief	タスク達の更新処理
	*/
	void TaskGameUpdate();
	/**
	*@brief	タスクを登録する
	*@param[in]	SceneTask* task タスク
	*/
	void SetScene(
		SceneTask* task);
	/**
	*@brief	GameObjectを登録する
	*@param[in]	GameObject* object GameObject
	*/
	void SetGameObject(
		GameObject* object);
	/**
	*@brief	UIを登録する
	*@param[in]	UIObject* ui UI
	*/
	void SetUI(UIObject* ui);
	/**
	*@brief	他Sceneを登録する
	*@param[in]	SceneTask* task Task
	*/
	void SetOtherScene(SceneTask* task);
	/**
	*@brief	開始タスクを登録する
	*@param[in]	SceneTask* task タスク
	*/
	void SetStartTask(
		SceneTask* task);
	/**
	*@brief	値リセット
	*/
	void Reset();
	/**
	*@brief	WindowChenge
	*@param[in]	const Vec2& pos WindowPosition
	*@param[in]	const Vec2& size WindowSize
	*@param[in]	char* name WindowTitleName
	*@param[in]	bool screen WindowMode
	*/
	void WindowChenge(const Vec2& pos, const Vec2& size, const char* name, const bool screen);
	/**
	*@brief	WindowChenge
	*@param[in]	int x WindowPosition_x
	*@param[in]	int y WindowPosition_y
	*@param[in]	int w WindowSize_w
	*@param[in] int h WindowSize_h
	*@param[in]	char* name WindowTitleName
	*@param[in]	bool screen WindowMode
	*/
	void WindowChenge(const int x, const int y, const int w, const int h, const char* name, const bool screen);
	/**
	*@brief	登録されているオブジェクトすべてを取得する
	*@return vector<GameObject*> 登録全オブジェクト
	*/
	std::vector<GameObject*> GetAllObject() const;
	/**
	*@brief	登録予定オブジェクトすべてを取得する
	*@return vector<GameObject*> 登録予定全オブジェクト
	*/
	std::vector<GameObject*> GetAllAddObject() const;
	/**
	*@brief	登録されているUIすべてを取得する
	*@return vector<UIObject*> 登録全UI
	*/
	std::vector<UIObject*> GetAllUI() const;
	/**
	*@brief	登録予定UIすべてを取得する
	*@return vector<UIObject*> 登録予定全UI
	*/
	std::vector<UIObject*> GetAllAddUI() const;
	/**
	*@brief	他Sceneを全て取得する
	*@return vector<SceneTask*> 他Scene達
	*/
	std::vector<SceneTask*> GetAllOtherScenes() const;
	/**
	*@brief	エンジン終了を返す
	*@return bool エンジン終了設定
	*/
	bool GetDeleteEngine();
	/**
	*@brief	エンジン終了を登録
	*@param[in]	bool falg 終了設定
	*/
	void SetDeleteEngine(const bool flag);
	/**
	*@brief	登録されているタスクを表示する
	*/
	void ShowNameAddedObject();
	/**
	*@brief	オブジェクト検索(最初の同名のオブジェクトを返す)
	*@param[in]	string objectName オブジェクト名
	*@return template<class*> 指定単体タスクclass
	*/
	template <class T> T* GetObject(const std::string& objectName) const
	{
		for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == objectName)
				{
					return (T*)(*id);
				}
			}
		}
		for (auto id = this->addGameObjects.begin(); id != this->addGameObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == objectName)
				{
					return (T*)(*id);
				}
			}
		}
		return nullptr;
	}
	/**
	*@brief	オブジェクト検索(同名すべてを返す)
	*@param[in]	string objectName オブジェクト名
	*@return vector<template<class*>> 指定複数タスクclass
	*/
	template <class T> std::vector<T*> GetObjects(const std::string& objectName) const
	{
		std::vector<T*> w;
		for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == objectName)
				{
					w.emplace_back((T*)(*id));
				}
			}
		}
		for (auto id = this->addGameObjects.begin(); id != this->addGameObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == objectName)
				{
					w.emplace_back((T*)(*id));
				}
			}
		}
		return w;
	}
	/**
	*@brief	UI検索(最初の同名のUIを返す)
	*@param[in]	string tag UITag
	*@return template<class*> 指定単体タスクclass
	*/
	template <class T> T* GetUI(const std::string& tag) const
	{
		for (auto id = this->nowUIs.begin(); id != this->nowUIs.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == tag)
				{
					return (T*)(*id);
				}
			}
		}
		for (auto id = this->addUIs.begin(); id != this->addUIs.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == tag)
				{
					return (T*)(*id);
				}
			}
		}
		return nullptr;
	}
	/**
	*@brief	UI検索(同名すべてを返す)
	*@param[in]	string tag UItag
	*@return vector<template<class*>> 指定複数タスクclass
	*/
	template <class T> std::vector<T*> GetUIs(const std::string& tag) const
	{
		std::vector<T*> w;
		for (auto id = this->nowUIs.begin(); id != this->nowUIs.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == tag)
				{
					w.emplace_back((T*)(*id));
				}
			}
		}
		for (auto id = this->addUIs.begin(); id != this->addUIs.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == tag)
				{
					w.emplace_back((T*)(*id));
				}
			}
		}
		return w;
	}
	/**
	*@brief	NowScene取得
	*@return template<class*> 現在Scene
	*/
	template <class T> T* GetNowScene() const
	{
		if (this->_sceneManager->GetNowTask())
		{
			return (T*)(this->_sceneManager->GetNowTask());
		}
		return nullptr;
	}
	/**
	*@brief	NextScene取得
	*@return template<class*> 次Scene
	*/
	template <class T> T* GetNextScene() const
	{
		if (this->_sceneManager->GetNextTask())
		{
			return (T*)(this->_sceneManager->GetNextTask());
		}
		return nullptr;
	}
	/**
	*@brief	OtherScene検索
	*@param[in]	std::string name Scene名
	*@return vector<template class*> 該当Scene達
	*/
	template <class T> std::vector<T*> GetSceneOthers(const std::string& name) const
	{
		std::vector<T*> w;
		auto id = this->_sceneManager->GetOtherAllTask();
		for (auto is = id.begin(); is != id.end(); ++is)
		{
			if ((*is)->GetTaskName() == name)
			{
				w.emplace_back((T*)(*is));
			}
		}
		return w;
	}
};

extern EngineSystem* ge;
extern ResourceManager* rm;