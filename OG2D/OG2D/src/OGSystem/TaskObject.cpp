#include "TaskObject.h"
SceneTask::SceneTask()
{
	this->taskName = "";
	this->NextTask = true;
	this->enableDestroyGameObjectWhenExitng = false;
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
	case Mode::NORMAL:
		this->Update();
		break;
	case Mode::PAUSE:
		this->Pause();
		break;
	default:
		break;
	}
}
void SceneTask::Kill(const bool on)
{
	this->NextTask = on;
	this->_mode = Mode::KILL;
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
	if (this->ModeCheck(Mode::KILL))
	{
		return;
	}
	if (flag)
		this->_mode = Mode::PAUSE;
	else
		this->_mode = Mode::NORMAL;
}
void SceneTask::SetStop(const bool flag)
{
	if (this->ModeCheck(Mode::KILL))
	{
		return;
	}
	if (flag)
		this->_mode = Mode::STOP;
	else
		this->_mode = Mode::NORMAL;
}
Mode SceneTask::GetMode() const
{
	return this->_mode;
}
bool SceneTask::ModeCheck(const Mode& mode) const
{
	return this->_mode == mode ? true : false;
}
void SceneTask::EnableGameObjectDestroy(const bool flag)
{
	this->enableDestroyGameObjectWhenExitng = flag;
}
bool SceneTask::GetGameObjectDestroy() const
{
	return this->enableDestroyGameObjectWhenExitng;
}