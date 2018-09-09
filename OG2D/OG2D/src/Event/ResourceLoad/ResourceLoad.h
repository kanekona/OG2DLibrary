#pragma once
#include "OGSystem\OGsystem.h"


class ResourceLoad
{
	//!	�t�@�C���̒��g�̃f�[�^
	std::string textData;
	//! ��������f�[�^���
	std::string dataPath;
	//! �f�[�^�̃t�@�C����
	std::string dataName;
	/**
	*@brief	:�f�[�^�𐶐�����
	*@param	:string text �������邽�߂̃f�[�^
	*/
	void DataCreate(const std::string& text);
public:
	/**
	*@brief	:constructor
	*@param	:ifstream ifs �t�@�C���f�[�^
	*/
	explicit ResourceLoad(std::ifstream& ifs);
	/**
	*@brief	:destructor
	*/
	virtual ~ResourceLoad();
};