
#pragma once
#include "OG\_OGsystem.h"
/**
*@brief	�����Ԃ𓱂����߂�class
*/
class Time : private NonCopyable
{
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
public:
	/**
	*@brief	constructor
	*/
	explicit Time();
	/**
	*@brief	destructor
	*/
	virtual ~Time();
	/**
	*@brief	�v���J�n
	*/
	void Start();
	/**
	*@brief	�v����~
	*/
	void Stop();
	/**
	*@brief	�ꎞ��~
	*/
	void Pause();
	/**
	*@brief	���݃^�C����Ԃ�
	*@return float ���݂̃^�C��
	*/
	float GetTime();
	/**
	*@brief	�J�n�^�C���̕ύX
	*@param[in] float time_ �������̃^�C��
	*/
	void InitTime(const float time_);
	/**
	*@brief	�v������
	*@return bool �v�����s���Ă��邩���ׂ�
	*/
	bool IsPlay() const;
};