#include "SceneTask.h"
SceneTask::SceneTask()
{
	this->taskName = "";
	this->NextTask = true;
	this->enableDestroyAllObjectWhenExitng = false;
	this->_mode = ST::Mode::NORMAL;
}
SceneTask::~SceneTask()
{
}
bool SceneTask::Init(const std::string& name_)
{
	this->taskName = name_;
	return true;
}
void SceneTask::UpdateManager()
{
	switch (this->_mode)
	{
	case ST::Mode::NORMAL:
		this->Update();
		break;
	case ST::Mode::PAUSE:
		this->Pause();
		break;
	default:
		break;
	}
}
void SceneTask::Kill(const bool on)
{
	this->NextTask = on;
	this->_mode = ST::Mode::KILL;
}
bool SceneTask::GetNextTask() const
{
	return this->NextTask;
}
std::string SceneTask::GetTaskName() const
{
	return this->taskName;
}
void SceneTask::Update()
{

}
void SceneTask::Pause()
{

}
void SceneTask::SetPause(const bool flag)
{
	if (this->ModeCheck(ST::Mode::KILL))
	{
		return;
	}
	if (flag)
		this->_mode = ST::Mode::PAUSE;
	else
		this->_mode = ST::Mode::NORMAL;
}
void SceneTask::SetStop(const bool flag)
{
	if (this->ModeCheck(ST::Mode::KILL))
	{
		return;
	}
	if (flag)
		this->_mode = ST::Mode::STOP;
	else
		this->_mode = ST::Mode::NORMAL;
}
ST::Mode SceneTask::GetMode() const
{
	return this->_mode;
}
bool SceneTask::ModeCheck(const ST::Mode& mode) const
{
	return this->_mode == mode ? true : false;
}
void SceneTask::EnableGameObjectDestroy(const bool flag)
{
	this->enableDestroyAllObjectWhenExitng = flag;
}
bool SceneTask::GetAllObjectDestroy() const
{
	return this->enableDestroyAllObjectWhenExitng;
}