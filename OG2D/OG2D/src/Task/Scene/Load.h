#pragma once
#include "OG\OGsystem.h"

/**
*@brief	��ʑJ�ڎ��Ɏg���t�F�[�h�C���A�E�g
*�A�j���[�V���������邩�ŏ������ς��
*/
class Load : public SceneTask
{
	explicit Load();
public:
	static Load* Create();
	virtual ~Load();
};