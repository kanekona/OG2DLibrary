#include "OG\System.h"
//���������[�N���m
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
/**
*@brief	�G���g���[�|�C���g
*/
int main() {
	//���������[�N���m
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