/**�����_���̐��l�A��������擾���邽�߂�class
*����GameEngine���g�p���Ă���ꍇ�͎����Ő����A�����������
*/
#pragma once
#include <random>
#include <iostream>
/**
*namespace random
*�����_���������O���
*/
namespace random
{
	//! �����Z���k�c�C�X�^�[64bit
	static std::mt19937_64 engine;
	//! ������
	void Init();
	/**
	*@brief	:�����̃����_��
	*@param	:int min_ �Œ�l
	*@param	:int max_ �ő�l
	*@return:int �����_���l
	*/
	int GetRand(const int min_,const int max_);
	/**
	*@brief	:���������_�̃����_��
	*@param	:float min_ �Œ�l
	*@param	:float max_ �ő�l
	*@return:float �����_���l
	*/
	float GetRand(const float min_,const float max_);
	/**
	*@brief	:������̃����_��
	*@param	:string text �g�p���镶������
	*@param	:size_t size �Ԃ������̃T�C�Y
	*@return:string �����_��������
	*/
	std::string GetRand(
		const std::string& text, 
		const std::size_t size
	);											
}
