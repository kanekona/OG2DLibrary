#include "OG\System.h"
//メモリリーク検知
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
/**
*@brief	エントリーポイント
*/
int main() {
	//メモリリーク検知
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	OGSystem* system = new OGSystem();
	if (!system->Create())
	{
		OG::Destroy<OGSystem>(system);
		return -1;
	}
	while (system->LibConfirmation()) 
	{

	}
	OG::Destroy<OGSystem>(system);
}