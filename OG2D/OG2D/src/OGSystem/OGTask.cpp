#include "OGSystem\OGTask.h"
void OGTK::_myGameInitialize()
{
	//��������Window���
	OGge->SetWindow(960, 540, "WindowName", false);	
	OGge->window->createWindow(50, 50, "", false, Vec2(0, 0));
}

void OGTK::StartTaskObject()
{
	//�^�X�N�̏�����
	auto TopTask = Sample::Create(true);
}