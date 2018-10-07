#include "Random.h"

void random::Init()
{
	//���������G���W���̐���
	std::random_device device;
	//�V�[�h�l�ݒ�
	engine.seed(device());
}

int random::GetRand(const int min_,const int max_)
{
	std::uniform_int_distribution<int> range(min_,max_);
	return range(engine);
}

float random::GetRand(const float min_,const float max_)
{
	std::uniform_real_distribution<float> range(min_,max_);
	return range(engine);
}

std::string random::GetRand(const std::string& text, const std::size_t size)
{
	if (text.empty())
	{
		std::cout << "�����Ɏg�p���镶����f�[�^�����݂��܂���" << std::endl;
		return "";
	}
	//text�f�[�^��0�Ԗڂ���Ō�̂P��O(\0�̑O�܂�)�ŗ����𐶐�
	std::uniform_int_distribution<std::size_t> range(0, text.size() - 1);
	std::string ReturnText;
	for (std::size_t i = 0; i < size; ++i)
	{
		std::size_t index = range(engine);
		char random_char = text[index];
		ReturnText += random_char;
	}
	return ReturnText;
}