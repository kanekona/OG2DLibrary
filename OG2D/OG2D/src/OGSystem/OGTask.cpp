#include "OGSystem\OGTask.h"
#include "Task\Task_Sample.h"
#include "Event\Event.h"

void OGTK::_myGameInitialize()
{
	//生成するWindow情報
	OGge->SetWindow(960, 540, "WindowName", false);	
}

void OGTK::StartTaskObject()
{
	EventTask ev;
	ev.Load(Event::RESOURCE_LOAD, "./data/event/sampleLoad.og");
	//タスクの初期化
	OGge->SetStartTask(Sample::Create());
	OG::BackColor(1, 1, 1, 1);
}

OGTK::~OGTK()
{

}