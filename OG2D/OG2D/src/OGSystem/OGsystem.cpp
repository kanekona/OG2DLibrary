#include "OGsystem.h"
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
	this->Cursor_on = true;
	this->file = "testicon.png";
	this->w_pos = { 1920 - this->w_wi, 50 };
	this->DeleteEngine = false;
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
	this->window->InMouseMode(this->Cursor_on);
	this->window->setIcon(this->path + this->file);
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
	this->Cursor_on = on;
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
	//登録タスクの更新処理を呼ぶ
	for (int id = 0; id < this->taskObjects.size(); ++id)
	{
		if (this->taskObjects[id].second->GetKillCount() == 0)
		{
			this->taskObjects[id].second->T_Update();
		}
	}
}
void EngineSystem::Task_Render_AF()
{
	//描画順にDraw2Dを実行する
	for (int id = 0; id < this->taskObjects.size(); ++id)
	{
		if (this->taskObjects[this->Orders[id].id].second->GetKillCount() <= 0)
		{
			this->taskObjects[this->Orders[id].id].second->Render2D();
		}
	}
}
void EngineSystem::TaskGameUpdate()
{
	this->Task_Update();		//更新処理
	this->camera->Update();	//カメラ処理
	this->Task_Render_AF();		//描画処理
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
	this->Orders.resize(this->taskObjects.size());
	//初期状態をコピーする
	for (int i = 0; i < this->taskObjects.size(); ++i)
	{
		this->Orders[i].id = i;
		this->Orders[i].order_s = this->taskObjects[i].second->GetDrawOrder();
	}
	//描画順に合わせてidとorderを並び替える
	for (int i = 0; i < this->taskObjects.size(); ++i)
	{
		for (int j = i; j < this->taskObjects.size(); ++j)
		{
			if (this->Orders[i].order_s > this->Orders[j].order_s)
			{
				OrderCheck kari = this->Orders[i];
				this->Orders[i] = this->Orders[j];
				this->Orders[j] = kari;
			}
		}
	}
}
EngineSystem::~EngineSystem()
{
	//登録しているタスクをすべて破棄する
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
void EngineSystem::SetTaskObject(TaskObject* To)
{
	this->addTaskObjects.push_back(To);
}
void EngineSystem::TaskApplication()
{
	//登録予定のものを登録する
	for (int id = 0; id < this->addTaskObjects.size(); ++id)
	{
		std::pair<unsigned short, TaskObject*> d;
		d.first = 0;
		d.second = this->addTaskObjects[id];
		if (d.second->GetNextTask())
		{
			this->taskObjects.push_back(d);
		}
	}
	addTaskObjects.clear();
}
void EngineSystem::TaskKillCheck()
{
	//削除予定のタスクを削除する
	auto id = this->taskObjects.begin();
	while (id != this->taskObjects.end())
	{
		if (id->second)
		{
			if (id->second->GetKillCount() > 0)
			{
				delete id->second;
				this->taskObjects.erase(id);
				this->TaskApplication();
				id = this->taskObjects.begin();
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
	return this->addTaskObjects.size() > 0;
}
bool EngineSystem::CheckKillTask()
{
	for (int i = 0; i < this->taskObjects.size(); ++i)
	{
		if (this->taskObjects[i].second->GetKillCount() > 0)
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
		auto id = this->taskObjects.begin();
		while (id != this->taskObjects.end())
		{
			delete id->second;
			this->taskObjects.erase(id);
			id = this->taskObjects.begin();
		}
	}
}
void EngineSystem::AllPause(const bool flag)
{
	for (auto id = taskObjects.begin(); id != taskObjects.end(); ++id)
	{
		if (id->second)
		{
			id->second->SetPause(flag);
		}
	}
	for (auto id = addTaskObjects.begin(); id != addTaskObjects.end(); ++id)
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
	this->DeleteEngine = flag;
}
bool EngineSystem::GetDeleteEngine()
{
	//エンジン終了を返す
	return this->DeleteEngine;
}
void EngineSystem::ShowNameAddedObject()
{
	for (auto id = this->taskObjects.begin(); id != this->taskObjects.end(); ++id)
	{
		std::cout << (*id).second->GetTaskName() << ":";
	}
	std::cout << std::endl;
}
void EngineSystem::AllStop(const bool flag)
{
	for (auto id = taskObjects.begin(); id != taskObjects.end(); ++id)
	{
		if (id->second)
		{
			id->second->Stop(flag);
		}
	}
	for (auto id = addTaskObjects.begin(); id != addTaskObjects.end(); ++id)
	{
		if ((*id))
		{
			(*id)->Stop(flag);
		}
	}	
}
//! 内部システムエンジン
EngineSystem* OGge;
//! リソース管理システム
ResourceManager* rm;