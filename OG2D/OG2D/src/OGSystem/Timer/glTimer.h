/**
*�����Ԃ𓱂����߂�class
*/
#pragma once
#include "OGSystem\_OGsystem.h"

class Time
{
public:
	/**
	*@brief	:constructor
	*/
	Time();
	/**
	*@brief	:destructor
	*/
	~Time();
	/**
	*@brief	:�v���J�n
	*/
	void Start();
	/**
	*@brief	:�v����~
	*/
	void Stop();
	/**
	*@brief	:�ꎞ��~
	*/
	void Pause();
	/**
	*@brief	:���݃^�C����Ԃ�
	*@return:float ���݂̃^�C��
	*/
	float GetTime();
	/**
	*@brief	:�J�n�^�C���̕ύX
	*@param	:float time_ �������̃^�C��
	*/
	void InitTime(const float time_);
	/**
	*@brief	:�v������
	*@return:bool �v�����s���Ă��邩���ׂ�
	*/
	bool isplay() const;
private:
	//! �����^�C��
	float initTime;
	//! ���݃^�C��
	float nowTime;
	//! ��~���̃^�C���̕ۑ�
	float saveTime;
	//! �ǉ��^�C��
	float addTime;
	//! �v��������
	bool isPlay;
	//! ���쒆����
	bool behavior;
};