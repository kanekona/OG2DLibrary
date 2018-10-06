#include "OGsystem.h"
//--------------------------------------------------
//@:SceneManager
//--------------------------------------------------
SceneManager::SceneManager()
{
	this->nowScene = nullptr;
	this->nextScene = nullptr;
}
SceneManager::~SceneManager()
{
	OG::Destroy<SceneTask>(this->nowScene);
	OG::Destroy<SceneTask>(this->nextScene);
	for (auto id = this->otherScene.begin(); id != this->otherScene.end(); ++id)
	{
		OG::Destroy<SceneTask>(*id);
	}
}
void SceneManager::SetNowTask(SceneTask* task)
{
	OG::Destroy<SceneTask>(this->nowScene);
	this->nowScene = task;
}
void SceneManager::SetNextTask(SceneTask* task)
{
	OG::Destroy<SceneTask>(this->nextScene);
	this->nextScene = task;
}
void SceneManager::SceneMigration()
{
	OG::Destroy<SceneTask>(this->nowScene);
	this->nowScene = this->nextScene;
	this->nextScene = nullptr;
}
void SceneManager::OrtherSceneKillCheck()
{
	for (auto id = this->otherScene.begin(); id != this->otherScene.end();)
	{
		if ((*id) && (*id)->ModeCheck(Scene::Mode::KILL))
		{
			OG::Destroy<SceneTask>(*id);
			id = this->otherScene.erase(id);
		}
		else
		{
			++id;
		}
	}
}
void SceneManager::SetOtherTask(SceneTask* task)
{
	this->otherScene.push_back(task);
}
SceneTask* SceneManager::GetNowTask() const
{
	return this->nowScene;
}
SceneTask* SceneManager::GetNextTask() const
{
	return this->nextScene;
}
std::vector<SceneTask*> SceneManager::GetOtherAllTask() const
{
	return this->otherScene;
}
//--------------------------------------------------
//@:GameEngineclass									
//--------------------------------------------------
EngineSystem::EngineSystem()
	:path("./data/image/")
{
	//Window情報がセットされなかった時のための初期設定
	this->w_wi = 960;
	this->w_he = 540;
	this->w_na = "NoName";
	this->w_sc = false;
	this->cursor_on = true;
	this->file = "testicon.png";
	this->w_pos = { 0, 30 };
	this->deleteEngine = false;
	this->nextWindowCreateEnable = false;
}
EngineSystem::EngineSystem(const int widht,const int height, const char* name, const bool screen)
{
	this->w_he = widht;
	this->w_he = height;
	this->w_na = name;
	this->w_sc = screen;
}
bool EngineSystem::Initialize()
{
	//初期化処理
	//Windowの生成
	this->window = new Window(w_wi, w_he, w_na, w_sc, w_pos);
	this->WindowConfig();
	//カメラ2Dの生成
	this->camera = new Camera2D(Box2D(0, 0, w_wi, w_he));
	//fpsの設定
	this->fps = new FPS();
	//入力関連の初期化
	this->in = new Input();
	this->in->Inputinit(this->window->GetWindow());
	//サウンド管理の初期化
	this->soundManager = new SoundManager();
	//オーディオデバイスの初期化と設定
	this->audiodevice = new Audio();
	//シーン管理を生成
	this->_sceneManager = new SceneManager();
	//各値の初期化
	DebugFunction = false;
	this->end = false;
	return true;
}
void EngineSystem::SetWindow(const int width, const int height, const char* name, const bool screen)
{
	//Window情報を登録する
	this->w_wi = width;
	this->w_he = height;
	this->w_na = name;
	this->w_sc = screen;
}
void EngineSystem::WindowChenge(const Vec2& pos, const Vec2& size, const char* name, const bool screen)
{
	this->window->ChengeTitle(name);
	this->window->ChengeWindow(pos, size, screen);
	this->camera->Initialize(Box2D(0.f, 0.f, size.x, size.y));
	glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y);
}
void EngineSystem::WindowChenge(const int x,const int y,const int w,const int h, const char* name, const bool screen)
{
	this->window->ChengeTitle(name);
	this->window->ChengeWindow(x, y, w, h, screen);
	this->camera->Initialize(Box2D(0, 0, w, h));
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}
void EngineSystem::GetWindow(int& width, int& height, bool& screen,Vec2& pos)
{
	width = this->w_wi;
	height = this->w_he;
	screen = this->w_sc;
	pos = this->w_pos;
}
void EngineSystem::SetCursorOn(const bool on)
{
	//カーソルの可視化有無
	this->cursor_on = on;
}
void EngineSystem::SetIcon(const std::string& filepath_)
{
	//アイコンに使用する画像の設定
	this->file = filepath_;
}
void EngineSystem::WindowConfig()
{
	//Window設定
	this->window->LimitsWindow();
	this->window->InMouseMode(this->cursor_on);
	this->window->SetIcon(this->path + this->file);
}
void EngineSystem::Update()
{
	//入力状況の更新
	this->in->Update();
#if(_DEBUG)
	this->fps->Update();
#endif
}
void EngineSystem::Task_Update()
{
	//SceneManagerのUpdateを呼ぶ
	if (this->_sceneManager->GetNowTask())
	{
		this->_sceneManager->GetNowTask()->UpdateManager();
	}
	auto is = this->_sceneManager->GetOtherAllTask();
	for (auto id = is.begin(); id != is.end(); ++id)
	{
		(*id)->UpdateManager();
	}
	//GameObjectsのUpdateを呼ぶ
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
	{
		(*id)->UpdateManager();
	}
}
void EngineSystem::Task_Render_AF()
{
	//GameObjectsのRenderを呼ぶ
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
	{
		(*id)->RenderManager();
	}
}
void EngineSystem::TaskGameUpdate()
{
	this->Task_Update();		//更新処理
	this->camera->Update();	//カメラ処理
	this->Task_Render_AF();		//描画処理
	this->SceneStateCheck();		//シーンの状態管理
	this->GameObjectsStateCheck();	//ゲームオブジェクトの状態確認
}
void EngineSystem::SceneStateCheck()
{
	if (this->_sceneManager->GetNowTask())
	{
		if (this->_sceneManager->GetNowTask()->ModeCheck(Scene::KILL))
		{
			//オブジェクトの削除を指定されているならば
			if (this->_sceneManager->GetNowTask()->GetGameObjectDestroy())
			{
				this->AllObjectKill();
			}
			this->_sceneManager->SceneMigration();
			if (!this->_sceneManager->GetNowTask())
			{
				this->GameEnd();
			}
		}
	}
	this->_sceneManager->OrtherSceneKillCheck();
}
void EngineSystem::GameObjectsStateCheck()
{
	//GameObjectの登録
	if (this->CheckAddTask() || this->CheckKillTask())
	{
		this->TaskKillCheck();		//削除予定のタスクを削除する
		this->TaskApplication();	//登録予定のタスクを登録する
		this->ConfigDrawOrder();	//タスクの集合体の変更後に描画順を設定する
	}
}
void EngineSystem::ConfigDrawOrder()
{
	//描画順の設定
	//登録タスク分の描画順を入れておくclassを作っておく
	this->orders.resize(this->nowGameObjects.size());
	//初期状態をコピーする
	for (int i = 0; i < this->nowGameObjects.size(); ++i)
	{
		this->orders[i].id = i;
		this->orders[i].order_s = this->nowGameObjects[i]->GetDrawOrder();
	}
	//描画順に合わせてidとorderを並び替える
	for (int i = 0; i < this->nowGameObjects.size(); ++i)
	{
		for (int j = i; j < this->nowGameObjects.size(); ++j)
		{
			if (this->orders[i].order_s > this->orders[j].order_s)
			{
				OrderCheck kari = this->orders[i];
				this->orders[i] = this->orders[j];
				this->orders[j] = kari;
			}
		}
	}
}
EngineSystem::~EngineSystem()
{
	this->deleteEngine = true;
	//登録しているタスクをすべて破棄する
	delete this->_sceneManager;
	this->AllGameObjectsDelete();
	//生成したclassをdeleteする
	delete this->audiodevice;
	delete this->soundManager;
	delete this->fps;
	delete this->in;
	delete this->window;
	delete this->camera;
}
void EngineSystem::GameEnd()
{
	//アプリケーションの終了予定設定
	this->end = true;
	//this->nextWindowCreateEnable = flag;
}
bool EngineSystem::GetEnd() const
{
	//アプリケーションを終了の有無を返す
	return this->end;
}
void EngineSystem::Reset()
{
	this->end = false;
	this->nextWindowCreateEnable = false;
	this->deleteEngine = false;
}
bool EngineSystem::GetNextWindowCreateEnable() const
{
	return this->nextWindowCreateEnable;
}
void EngineSystem::ChengeTask()
{
	//タスクを変更する際に元に戻したい処理
	this->camera->SetPos(Vec2(0.f, 0.f));
	this->camera->SetSize(this->window->GetSize());
}
void EngineSystem::SetTask(SceneTask* to)
{
	this->_sceneManager->SetNextTask(to);
}
void EngineSystem::SetStartTask(SceneTask* to)
{
	this->_sceneManager->SetNowTask(to);
}
void EngineSystem::SetGameObject(GameObject* object)
{
	this->addGameObjects.push_back(object);
}
std::vector<GameObject*> EngineSystem::GetAllObject() const
{
	return this->nowGameObjects;
}
std::vector<GameObject*> EngineSystem::GetAllAddObject() const
{
	return this->addGameObjects;
}
std::vector<SceneTask*> EngineSystem::GetAllOtherScenes() const
{
	return this->_sceneManager->GetOtherAllTask();
}
void EngineSystem::TaskApplication()
{
	//登録予定のものを登録する
	for (int id = 0; id < this->addGameObjects.size(); ++id)
	{
		GameObject* d;
		d = this->addGameObjects[id];
		this->nowGameObjects.push_back(d);
	}
	addGameObjects.clear();
}
void EngineSystem::TaskKillCheck()
{
	//削除予定のタスクを削除する
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end();)
	{
		if ((*id)->ModeCheck(GO::Mode::KILL))
		{
			delete *id;
			id = this->nowGameObjects.erase(id);
		}
		else
		{
			++id;
		}
	}
}
bool EngineSystem::CheckAddTask()
{
	return this->addGameObjects.size() > 0;
}
bool EngineSystem::CheckKillTask()
{
	for (int i = 0; i < this->nowGameObjects.size(); ++i)
	{
		if (this->nowGameObjects[i]->ModeCheck(GO::Mode::KILL))
		{
			return true;
		}
	}
	return false;
}
void EngineSystem::AllGameObjectsDelete()
{
	//全削除
	{
		auto id = this->nowGameObjects.begin();
		while (id != this->nowGameObjects.end())
		{
			delete *id;
			this->nowGameObjects.erase(id);
			id = this->nowGameObjects.begin();
		}
	}
	{
		auto id = this->addGameObjects.begin();
		while (id != this->addGameObjects.end())
		{
			delete *id;
			this->addGameObjects.erase(id);
			id = this->addGameObjects.begin();
		}
	}
}
void EngineSystem::AllObjectPause(const bool flag)
{
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
	{
		if (*id)
		{
			(*id)->SetPause(flag);
		}
	}
	for (auto id = this->addGameObjects.begin(); id != this->addGameObjects.end(); ++id)
	{
		if ((*id))
		{
			(*id)->SetPause(flag);
		}
	}
}
void EngineSystem::AllScenePause(const bool flag)
{
	this->_sceneManager->GetNowTask()->SetPause(flag);
	for (auto& id : this->_sceneManager->GetOtherAllTask())
	{
		id->SetPause(flag);
	}
}
void EngineSystem::AllPause(const bool flag)
{
	this->AllScenePause(flag);
	this->AllObjectPause(flag);
}
void EngineSystem::SetWindowPos(const Vec2& pos)
{
	//Windowの位置を返す
	this->w_pos = pos;
}
void EngineSystem::SetDeleteEngine(const bool flag)
{
	//エンジンの終了を登録
	this->deleteEngine = flag;
}
bool EngineSystem::GetDeleteEngine()
{
	//エンジン終了を返す
	return this->deleteEngine;
}
void EngineSystem::ShowNameAddedObject()
{
	std::cout << this->_sceneManager->GetNowTask()->GetTaskName() << ":";
	auto is = this->_sceneManager->GetOtherAllTask();
	for (auto id = is.begin(); id != is.end(); ++id)
	{
		std::cout << (*id)->GetTaskName() << ":";
	}
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
	{
		std::cout << (*id)->GetTag() << ":";
	}
	std::cout << std::endl;
}
void EngineSystem::AllObjectStop(const bool flag)
{
	for (auto id = nowGameObjects.begin(); id != nowGameObjects.end(); ++id)
	{
		if (*id)
		{
			(*id)->SetStop(flag);
		}
	}
	for (auto id = addGameObjects.begin(); id != addGameObjects.end(); ++id)
	{
		if ((*id))
		{
			(*id)->SetStop(flag);
		}
	}
}
void EngineSystem::AllSceneStop(const bool flag)
{
	this->_sceneManager->GetNowTask()->SetStop(flag);
	for (auto& id : this->_sceneManager->GetOtherAllTask())
	{
		id->SetStop(flag);
	}
}
void EngineSystem::AllStop(const bool flag)
{
	this->AllSceneStop(flag);
	this->AllObjectStop(flag);
}
void EngineSystem::AllObjectKill()
{
	for (auto id = nowGameObjects.begin(); id != nowGameObjects.end(); ++id)
	{
		if (*id)
		{
			(*id)->Kill();
		}
	}
	for (auto id = this->addGameObjects.begin(); id != this->addGameObjects.end(); ++id)
	{
		if (*id)
		{
			(*id)->Kill();
		}
	}
}
void EngineSystem::AllSceneKill()
{
	this->_sceneManager->GetNowTask()->Kill();
	for (auto& id : this->_sceneManager->GetOtherAllTask())
	{
		id->Kill();
	}
}
void EngineSystem::AllKill()
{
	this->AllSceneKill();
	this->AllObjectKill();
}
//! 内部システムエンジン
EngineSystem* ge;
//! リソース管理システム
ResourceManager* rm;