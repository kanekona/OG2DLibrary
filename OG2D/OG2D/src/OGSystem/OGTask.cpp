#include "OGSystem\OGTask.h"
void _OGTK::_myGameInitialize()
{
	//生成するWindow情報
	OGge->SetWindow(960, 540, "WindowName", false);	
}

void _OGTK::StartTaskObject()
{
	//タスクの初期化
	auto TopTask = Sample::Create(true);
}