/**
*�t���[�����[�g���v�Z,����(������)����class
*����GameEngine���g�p���Ă���ꍇ��DEBUG���̂ݎ����Ő��������
*/
#pragma once
#include "OGSystem\_OGsystem.h"

class FPS {
public:
	/**
	*@brief	:constructor
	*/
	FPS();				
	/**
	*@brief	:destructor
	*/
	~FPS();
	/**
	*@brief	:�X�V����
	*/
	void Update();
private:
	//! �S�t���[���^�C��
	float lastTime;		
	//! �J�E���g��
	int count;	
	//! fps�l
	GLfloat fps;
};
