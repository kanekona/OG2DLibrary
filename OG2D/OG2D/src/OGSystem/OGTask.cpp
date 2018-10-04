#include "OGSystem\OGTask.h"
#include "Task\Task_Sample.h"
#include "Event\Event.h"

void OGTK::Init()
{
	//生成するWindow情報
	ge->SetWindow(960, 540, "WindowName", false);	
}

void OGTK::StartTaskObject()
{
	EventTask ev;
	ev.Load(Event::RESOURCE_LOAD, "./data/event/sampleLoad.og");
	//タスクの初期化
	ge->SetStartTask(Sample::Create());
}

OGTK::~OGTK()
{

}