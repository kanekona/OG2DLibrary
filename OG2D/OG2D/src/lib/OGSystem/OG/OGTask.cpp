#include "OGTask.h"
#include "Task\WinConfig.h"
#include "Event\Event.h"
void OGTK::Init()
{
	//生成するWindow情報
	ge->SetWindow(1280, 720, "Is it full screen?", false);
}

void OGTK::StartTaskObject()
{
	EventTask ev;
	ev.Load(Event::RESOURCE_LOAD, "./data/event/sampleLoad.og");
	//タスクの初期化
	ge->SetStartTask(ConfigTask::Create());
	OG::BackColor(1.f, 1.f, 1.f, 0.f);
}

OGTK::~OGTK()
{

}