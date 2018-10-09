#include "OGTask.h"
#include "Task\WinConfig.h"
#include "Event\Event.h"
void OGTK::Init()
{
	//¶¬‚·‚éWindowî•ñ
	ge->SetWindow(1280, 720, "Is it full screen?", false);
}

void OGTK::StartTaskObject()
{
	EventTask ev;
	ev.Load(Event::RESOURCE_LOAD, "./data/event/sampleLoad.og");
	//ƒ^ƒXƒN‚Ì‰Šú‰»
	ge->SetStartTask(ConfigTask::Create());
	OG::BackColor(1.f, 1.f, 1.f, 0.f);
}

OGTK::~OGTK()
{

}