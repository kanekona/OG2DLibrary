#include "OGSystem\OGTask.h"
#include "Task\Task_Sample.h"
#include "Event\Event.h"

void OGTK::_myGameInitialize()
{
	//¶¬‚·‚éWindowî•ñ
	OGge->SetWindow(960, 540, "WindowName", false);	
}

void OGTK::StartTaskObject()
{
	EventTask ev;
	ev.Load(Event::RESOURCE_LOAD, "./data/event/sampleLoad.og");
	//ƒ^ƒXƒN‚Ì‰Šú‰»
	//Sample::Create();
}

OGTK::~OGTK()
{

}