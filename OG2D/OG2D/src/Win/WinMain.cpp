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
//#include "ft2build.h"
//#include FT_FREETYPE_H
//���������[�N���m
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

OGTK* ogtk;
OGSystem* System;
//------------------
//���C��
//------------------
int main() {
	//���������[�N���m
#if(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	System = new OGSystem();
	ogtk = new OGTK();
	ogtk->_myGameInitialize();
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
	delete ogtk;
	while (System->LibConfirmation()) 
	{
		
	}
	delete System;
}