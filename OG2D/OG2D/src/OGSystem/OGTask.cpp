#include "OGSystem\OGTask.h"
#include "Task\Task_Sample.h"
#include "Event\Event.h"

void OGTK::_myGameInitialize()
{
	//��������Window���
	OGge->SetWindow(960, 540, "WindowName", false);	
}

void OGTK::StartTaskObject()
{
	EventTask ev;
	ev.Load(Event::RESOURCE_LOAD, "./data/event/sampleLoad.og");
	//�^�X�N�̏�����
	//Sample::Create();
}

OGTK::~OGTK()
{

}