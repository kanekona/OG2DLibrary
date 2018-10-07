#pragma once
#include "OG\_OGsystem.h"
/**
*enum Event
*@brief	�ǂݍ��ރC�x���g�̎��
*/
enum Event
{
	//! ���\�[�X�ǂݍ��݃C�x���g
	RESOURCE_LOAD,
};
/**
*@brief	�C�x���g�^�X�N
*/
class EventTask
{
	//! �t�@�C�����
	std::ifstream ifs;
public:
	/**
	*@brief	constructor
	*/
	explicit EventTask();
	/**
	*@brief	destructor
	*/
	virtual ~EventTask();
	/**
	*@brief	�C�x���g��ǂݍ���
	*@param[in]	Event eventType ��������Event�̎��
	*@param[in]	string path �ǂݍ���Event�t�@�C���̃p�X
	*@return	bool ����true
	*/
	bool Load(const Event& eventType, const std::string& path);
};