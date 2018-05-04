#include "OGsystem.h"
//--------------------------------------------------
//@:GameEngineclass									
//--------------------------------------------------
EngineSystem::EngineSystem()
{
	this->w_wi = 960;
	this->w_he = 540;
	this->w_na = "NoName";
	this->w_sc = false;
	this->Cursor_on = true;
	this->file = "testicon.png";
	this->w_pos = { 1920 - this->w_wi, 50 };
	this->DeleteEngine = false;
}
EngineSystem::EngineSystem(int widht, int height, char* name, bool screen)
{
	this->w_he = widht;
	this->w_he = height;
	this->w_na = name;
	this->w_sc = screen;
}
void EngineSystem::Initialize()
{
	this->camera = Camera2D::Create(Box2D(0, 0, 960, 540));
	this->window = Window::Create(w_wi, w_he, w_na, w_sc, w_pos);
	this->window->LimitsWindow();
	this->window->InMouseMode(this->Cursor_on);
	this->fps = FPS::Create();
	this->window->setIcon(this->path + this->file);
	this->in.Inputinit(this->window->window);
	this->soundManager = SoundManager::Create();
	this->audiodevice = Audio::Create();
	DebugFunction = false;
	this->isPause = false;
	this->end = false;
}
void EngineSystem::SetWindow(int width, int height, char* name, bool screen)
{
	this->w_wi = width;
	this->w_he = height;
	this->w_na = name;
	this->w_sc = screen;
}
void EngineSystem::SetCursorOn(const bool on)
{
	this->Cursor_on = on;
}
void EngineSystem::SetIcon(std::string filepath_)
{
	this->file = filepath_;
}
void EngineSystem::Update()
{
	this->camera->CameraUpdate();
	this->in.upDate();
	this->fps->Update();
}
void EngineSystem::Task_UpDate()
{
	for (int id = 0; id < this->taskobjects.size();++id)
	{
		if (this->taskobjects[id].second->GetKillCount() == 0) 
		{
			this->taskobjects[id].second->T_UpDate();
		}
	}
}
void EngineSystem::Task_Render_AF()
{
	for (int id = 0; id < this->taskobjects.size(); ++id)
	{
		if (this->taskobjects[id].second->GetKillCount() == 0) 
		{
			this->taskobjects[id].second->Draw2D();
		}
	}
}
void EngineSystem::TaskGameUpDate()
{
	this->Task_UpDate();
	this->Task_Render_AF();
	this->TaskApplication();
	this->TaskKillCheck();
}
EngineSystem::~EngineSystem()
{
	this->AllTaskDelete();
}
void EngineSystem::SetPause(const bool ispause_)
{
	this->isPause = ispause_;
}
bool EngineSystem::GetPause() const
{
	return this->isPause;
}
void EngineSystem::GameEnd()
{
	this->end = true;
}
bool EngineSystem::GetEnd() const
{
	return this->end;
}
void EngineSystem::ChengeTask()
{
	this->camera->SetPos(Vec2(0.f, 0.f));
	this->camera->SetSize(Vec2(this->window->_widht, this->window->_height));
	this->SetPause(false);
	this->soundManager->AllDelete();
}
void EngineSystem::SetTaskObject(const TaskObject::SP& To)
{
	this->addTaskObjects.push_back(To);
}
void EngineSystem::TaskApplication()
{
	for (int i = 0; i < this->addTaskObjects.size(); ++i)
	{
		std::pair<DWORD, TaskObject::SP> d;
		d.second = this->addTaskObjects[i];
		if (d.second->GetNextTask())
		{
			this->taskobjects.push_back(d);
		}
	}
	addTaskObjects.clear();
}
void EngineSystem::KillTask(const TaskObject::SP& To)
{
	for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
	{
		if (id->second == To)
		{
			this->taskobjects.erase(id);
		}
	}
}
void EngineSystem::TaskKillCheck()
{
	auto id = this->taskobjects.begin();
	while (id != this->taskobjects.end())
	{
		if (id->second->GetKillCount() > 0)
		{
			this->taskobjects.erase(id);
			this->TaskApplication();
			id = this->taskobjects.begin();
		}
		else
		{
			++id;
		}
	}
}
void EngineSystem::AllTaskDelete()
{
	this->taskobjects.clear();
}
void EngineSystem::SetWindowPos(Vec2& pos)
{
	this->w_pos = pos;
}
void EngineSystem::SetDeleteEngine(bool flag)
{
	this->DeleteEngine = flag;
}
bool EngineSystem::GetDeleteEngine()
{
	return this->DeleteEngine;
}
EngineSystem* OGge;