//_____________________________
//|メインシステム               
//|履歴：2018/03/20       
//|履歴：2018/03/23
//|履歴：2018/04/26
//|____________________________
//数値演算定数
#define _USE_MATH_DEFINES
//小数点誤差修正
#define _OX_EPSILON_ 0.0000001f
#include "OGSystem\OGTask.h"
#include "OGSystem\System.h"
//メモリリーク検知
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

OGTK* ogtk;
OGSystem* System;
//------------------
//メイン
//------------------
int main() {
	//メモリリーク検知
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	System = new OGSystem();
	ogtk = new OGTK();
	ogtk->_myGameInitialize();
	Time* timer = new Time();
	timer->Start();
	OG::DataClear("Time.og");
	if (!System->Create())
	{
		if (System)
		{
			delete System;
		}
		if (ogtk)
		{
			delete ogtk;
		}
		return -1;
	}
	ogtk->StartTaskObject();
	while (System->LibConfirmation()) 
	{
		OG::OutDebugData("TIme.og", std::to_string(timer->GetTime()) + "\n");
	}
	delete ogtk;
	delete System;
	delete timer;
}