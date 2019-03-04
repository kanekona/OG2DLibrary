#include "ResourceManager\ResourceManager.h"
#include "Input\Input.h"
#include "Engine\Engine.h"
#if !defined (_DEBUG)
// Degub�ł̂݃R���\�[����\������ݒ�
#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
#endif
//���������[�N���m
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
*@brief	�G���g���[�|�C���g
*/
int main() {
	//���������[�N���m
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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