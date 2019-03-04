
#pragma once
#include "NonCopyable\NonCopyable.hpp"
#include "System\System_.h"
/**
*@brief	�t���[�����[�g���v�Z,��������class
*
*����GameEngine���g�p���Ă���ꍇ��Update��DEBUG���̂ݍs��
*/
class FPS : private NonCopyable 
{
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
	//! FrameCount
	unsigned int frameCount;
	//! StartDeltaTime
	const float startDeltaTime;
	//! DeltaTime
	float delta;
public:
	/**
	*@brief	constructor
	*/
	explicit FPS();				
	/**
	*@brief	destructor
	*/
	virtual ~FPS();
	/**
	*@brief	�X�V����
	*/
	void Update();
	/**
	*@bried	�t���[�����[�g�w��
	*@param[in]	int rate frame rate
	*/
	void SetFrameRate(const int rate);
	/**
	*@brief	�t���[���`�F�b�N
	*@return �b�ԃt���[���ɒB���Ă���Ȃ�true
	*/
	bool FrameCheck();
	/**
	*@brief Get DeltaTime
	*@return float DeltaTime
	*/
	float DeltaTime();
};
