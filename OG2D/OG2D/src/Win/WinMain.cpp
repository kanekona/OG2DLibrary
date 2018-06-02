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
//#include "ft2build.h"
//#include FT_FREETYPE_H
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
#if(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	System = new OGSystem();
	ogtk = new OGTK();
	ogtk->_myGameInitialize();
	if (!System->Create())
	{
		return -1;
	}
	ogtk->StartTaskObject();
	delete ogtk;
	while (System->LibConfirmation()) 
	{
		
	}
	delete System;
}