#include "OGSystem\OGTask.h"
void _OGTK::_myGameInitialize()
{
	//生成するWindow情報
	gameEngine->SetWindow(960, 540, "WindowName", false);
	//タスクの初期化
	nowTask = NON;
	nextTask = Task_Title;
}

void _OGTK::_myGameUpdate()
{
	if (nowTask != nextTask)
	{
		switch (nowTask)
		{
		case Task_Title:
		
			break;
		case Task_Game:
			
			break;
		}
		nowTask = nextTask;
		gameEngine->ChengeTask();
		switch (nowTask)
		{
		case Task_Title:
			
			break;
		case Task_Game:
			
			break;
		}
	}
	if (!gameEngine->GetPause()) {
		switch (nowTask)
		{
		case Task_Title:
			
			break;
		case Task_Game:
			
			break;
		}
	}
	else
	{
		//Pause処理をここに記述
		switch (nowTask)
		{
		case Task_Title:
			break;
		case Task_Game:
			break;
		}
	}
}

void _OGTK::_myGameRender2D()
{
	switch (nowTask)
	{
	case Task_Title:
		break;
	case Task_Game:
		break;
	}
}

void _OGTK::_myGameRender3D()
{

}

void _OGTK::_myGameFinalize()
{
	switch (nowTask)
	{
	case Task_Title:
		break;
	case Task_Game:
		break;
	}
}