/**
*����GameEngineClass���g�p����ꍇOGSystem
*�g�p���Ȃ��ꍇ_OGSystem
*/
#pragma once
#include "OGsystem.h"
///#include "_OGsystem.h"

class OGSystem : private NonCopyable
{
public:
	/**
	*@brief	:constructor
	*/
	OGSystem();
	/**
	*@brief	:�V�X�e������
	*@return:bool ����true
	*/
	bool Create();
	/**
	*@brief	:�X�V�`�F�b�N
	*@return:bool ���strue
	*/
	bool LibConfirmation();
	/**
	*@brief	:destructor
	*/
	virtual ~OGSystem();
};