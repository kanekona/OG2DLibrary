#include "OGSystem\OGTask.h"
void OGTK::_myGameInitialize()
{
	//��������Window���
	OGge->SetWindow(960, 540, "WindowName", false);	
}

void OGTK::StartTaskObject()
{
	//�^�X�N�̏�����
	auto TopTask = Sample::Create(true);
}