/**
*�t���[�����[�g���v�Z,��������class
*����GameEngine���g�p���Ă���ꍇ��DEBUG���̂ݎ����Ő��������
*/
#pragma once
#include "OGSystem\_OGsystem.h"

class FPS : private NonCopyable 
{
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
	/**
	*@bried	:�t���[�����[�g�w��
	*@param	:int rate frame rate
	*/
	void SetFrameRate(const int rate);
	/**
	*@brief	:�t���[���`�F�b�N
	*@return:�b�ԃt���[���ɒB���Ă���Ȃ�true
	*/
	bool FrameCheck();
private:
	//! �S�t���[���^�C��
	float lastTime;		
	//! �J�E���g��
	int count;	
	//! fps�l
	GLfloat fps;
	//! frame rate
	int framerate;
	//! oneframetime
	float oneFrameTime;
};
