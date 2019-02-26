
#pragma once
#include <random>
#include <iostream>
/**
*namespace random
*@brief �����_���������O���
*
*����GameEngine���g�p���Ă���ꍇ�͎����Ő����A�����������
*/
namespace Random
{
	//! �����Z���k�c�C�X�^�[64bit
	static std::mt19937_64 engine;
	//! ������
	void Init();
	/**
	*@brief	�����̃����_��
	*@param[in]	int min_ �Œ�l
	*@param[in]	int max_ �ő�l
	*@return int �����_���l
	*/
	int GetRand(const int min_,const int max_);
	/**
	*@brief	���������_�̃����_��
	*@param[in]	float min_ �Œ�l
	*@param[in]	float max_ �ő�l
	*@return float �����_���l
	*/
	float GetRand(const float min_,const float max_);
	/**
	*@brief	������̃����_��
	*@param[in]	string text �g�p���镶������
	*@param[in]	size_t size �Ԃ������̃T�C�Y
	*@return string �����_��������
	*/
	std::string GetRand(
		const std::string& text, 
		const std::size_t size
	);
	/**
	*@brief	�w�芄����true��Ԃ�
	*@param[in]	float proportion ����
	*@return bool true or false
	*/
	bool GetProportion(const float proportion);
	/**
	*@brief	���������_�̐��K���z
	*@param[in]	float mu ����
	*@param[in]	float sig �W���͍�
	*@return float �����_���l
	*/
	float GetRand_Normal(const float mu, const float sig);
}
