#pragma once
#include <random>
#include <iostream>
//�����_���������O���
namespace random
{
	static std::mt19937_64 engine;				//�����Z���k�c�C�X�^�[64bit
	void Init();								//������
	int GetRand(const int min_,const int max_);				//�����̃����_��
	float GetRand(const float min_,const float max_);		//���������_�̃����_��
	std::string GetRand(						//������̃����_��
		const std::string& text, 
		const std::size_t size
	);											
}
