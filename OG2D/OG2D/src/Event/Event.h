#pragma once
#include "OGSystem\OGsystem.h"
enum Event
{
	RESOURCE_LOAD,
};
class EventTask
{
	//! �t�@�C�����
	std::ifstream ifs;
public:
	/**
	*@brief	:constructor
	*@param	:Event eventType ��������Event�̎��
	*@param	:string path �ǂݍ���Event�t�@�C���̃p�X
	*/
	explicit EventTask();
	/**
	*@brief	:destructor
	*/
	virtual ~EventTask();
	/**
	*@brief	:�C�x���g��ǂݍ���
	*@param	:Event eventType ��������Event�̎��
	*@param	:string path �ǂݍ���Event�t�@�C���̃p�X
	*@return:bool ����true
	*/
	bool Load(const Event& eventType, const std::string& path);
};