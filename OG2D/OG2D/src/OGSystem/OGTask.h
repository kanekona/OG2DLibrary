#pragma once
#include "OGSystem\OGsystem.h"
/**
*@brief	Engine�����Ɋւ��鏈�����s��class
*/
class OGTK
{
public:
	/**
	*@brief	GammeEngine�̏��������ɐݒ肵�����������s���������֐�
	*/
	void Init();
	/**
	*@brief	�J�n���ɐ����������^�X�N���w�肷��֐�
	*/
	void StartTaskObject();
	/**
	*@brief destructor
	*/
	virtual ~OGTK();
};