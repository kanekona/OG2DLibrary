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
SceneTask* SceneManager::GetNowTask() const
{
	return this->nowScene;
}
SceneTask* SceneManager::GetNextTask() const
{
	return this->nextScene;
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
	this->w_pos = { 1920 - this->w_wi, 50 };
	this->deleteEngine = false;
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
	//Window設定
	this->window->LimitsWindow();
	this->window->InMouseMode(this->cursor_on);
	this->window->SetIcon(this->path + this->file);
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
}
void EngineSystem::GameObjectsStateCheck()
{
	//GameObjectの登録
	if (this->CheckAddTask() || this->CheckKillTask())
	{
		this->TaskApplication();	//登録予定のタスクを登録する
		this->TaskKillCheck();		//削除予定のタスクを削除する
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
	//登録しているタスクをすべて破棄する
	delete this->_sceneManager;
	this->AllTaskDelete();
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
}
bool EngineSystem::GetEnd() const
{
	//アプリケーションを終了の有無を返す
	return this->end;
}
void EngineSystem::ChengeTask()
{
	//タスクを変更する際に元に戻したい処理
	this->camera->SetPos(Vec2(0.f, 0.f));
	this->camera->SetSize(this->window->GetSize());
	//this->soundManager->AllDelete();
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
	auto id = this->nowGameObjects.begin();
	while (id != this->nowGameObjects.end())
	{
		if (*id)
		{
			if ((*id)->ModeCheck(GO::Mode::KILL))
			{
				delete *id;
				this->nowGameObjects.erase(id);
				this->TaskApplication();
				id = this->nowGameObjects.begin();
			}
			else
			{
				++id;
			}
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
void EngineSystem::AllTaskDelete()
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
void EngineSystem::AllPause(const bool flag)
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
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
	{
		std::cout << (*id)->GetTag() << ":";
	}
	std::cout << std::endl;
}
void EngineSystem::AllStop(const bool flag)
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
void EngineSystem::AllObjectKill()
{
	for (auto id = nowGameObjects.begin(); id != nowGameObjects.end(); ++id)
	{
		if (*id)
		{
			(*id)->Kill();
		}
	}
}
//! 内部システムエンジン
EngineSystem* ge;
//! リソース管理システム
ResourceManager* rm;