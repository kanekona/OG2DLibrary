#pragma once
#include <random>
#include <iostream>
//�����_���������O���
namespace random
{
	static std::mt19937_64 engine;				//�����Z���k�c�C�X�^�[64bit
	void Init();								//������
	int GetRand(int min_,int max_);				//�����̃����_��
	float GetRand(float min_,float max_);		//���������_�̃����_��
	std::string GetRand(						//������̃����_��
		const std::string& text, 
		std::size_t size
	);											
}
