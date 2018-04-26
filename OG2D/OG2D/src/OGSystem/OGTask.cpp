#include "OGSystem\OGTask.h"
void _OGTK::_myGameInitialize()
{
	//生成するWindow情報
	gameEngine->SetWindow(960, 540, "WindowName", false);
	//タスクの初期化
	nowTask = NON;
	nextTask = Task_Title;
}
//タスクシステム処理
void _OGTK::_myGameUpdate()
{
	if (nowTask != nextTask)
	{
		//解放処理
		switch (nowTask)
		{
		case Task_Title:
		
			break;
		case Task_Game:
			
			break;
		}
		nowTask = nextTask;
		//タスクが変わるときにリセットするゲームエンジンの処理
		gameEngine->ChengeTask();
		//初期化処理
		switch (nowTask)
		{
		case Task_Title:
			
			break;
		case Task_Game:
			
			break;
		}
	}
	if (!gameEngine->GetPause()) {
		//通常更新処理
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
	//描画処理
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
	//描画処理
}

void _OGTK::_myGameFinalize()
{
	//解放処理※こちらはアプリケーションが終了するときに呼び出される
	switch (nowTask)
	{
	case Task_Title:
		break;
	case Task_Game:
		break;
	}
}