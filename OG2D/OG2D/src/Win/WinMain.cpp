#include "OG\System.h"
#include "Engine\Engine.h"
#if !defined (_DEBUG)
// Degub版のみコンソールを表示する設定
#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
#endif
//メモリリーク検知
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
Framework* Framework::instance = nullptr;
Input* Input::instance = nullptr;
ResourceManager* ResourceManager::instance = nullptr;
/**
*@brief	エントリーポイント
*/
int main() {
	//メモリリーク検知
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/*OGSystem* system = new OGSystem();
	if (!system->Create())
	{
		OG::Destroy<OGSystem>(system);
		return -1;
	}
	while (system->LibConfirmation()) 
	{

	}
	OG::Destroy<OGSystem>(system);*/
	Engine* engine = nullptr;
	try
	{
		engine = new Engine();
	}
	catch (int errorcode)
	{
		std::cout << errorcode << std::endl;
	}
	while (engine->SystemUpdate())
	{

	}
	OG::Destroy<Engine>(engine);
}