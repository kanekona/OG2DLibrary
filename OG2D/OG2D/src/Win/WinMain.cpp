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
//------------------
//メイン
//------------------
int main() {
	//メモリリーク検知
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	OGSystem* system = new OGSystem();
	OGTK* ogtk = new OGTK();
	ogtk->Init();
	Time* timer = new Time();
	timer->Start();
	if (!system->Create())
	{
		OG::Destroy<OGSystem>(system);
		OG::Destroy<OGTK>(ogtk);
		OG::Destroy<Time>(timer);
		return -1;
	}
	ogtk->StartTaskObject();
	while (system->LibConfirmation()) 
	{

	}
	OG::Destroy<OGSystem>(system);
	OG::Destroy<OGTK>(ogtk);
	OG::Destroy<Time>(timer);
}