//_____________________________
//|���C���V�X�e��               
//|�����F2018/03/20       
//|�����F2018/03/23
//|�����F2018/04/26
//|____________________________
//���l���Z�萔
#define _USE_MATH_DEFINES
//�����_�덷�C��
#define _OX_EPSILON_ 0.0000001f
#include "OGSystem\OGTask.h"
#include "OGSystem\System.h"
//���������[�N���m
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
//------------------
//���C��
//------------------
int main() {
	//���������[�N���m
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	OGSystem* System = new OGSystem();
	OGTK* ogtk = new OGTK();
	ogtk->_myGameInitialize();
	Time* timer = new Time();
	timer->Start();
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
		if (timer)
		{
			delete timer;
		}
		return -1;
	}
	ogtk->StartTaskObject();
	while (System->LibConfirmation()) 
	{

	}
	delete ogtk;
	delete System;
	delete timer;
	system("pause");
}