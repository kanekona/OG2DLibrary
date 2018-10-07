
#pragma once
#include "OGsystem.h"
/**
*@brief	System
*����GameEngineClass���g�p����ꍇOGSystem
*�g�p���Ȃ��ꍇ_OGSystem(������p�͖�����)
*/
class OGSystem : private NonCopyable
{
public:
	/**
	*@brief	constructor
	*/
	explicit OGSystem();
	/**
	*@brief	�V�X�e������
	*@return bool ����true
	*/
	bool Create();
	/**
	*@brief	�X�V�`�F�b�N
	*@return bool ���strue
	*/
	bool LibConfirmation();
	/**
	*@brief	destructor
	*/
	virtual ~OGSystem();
};