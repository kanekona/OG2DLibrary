#pragma once
/**
*@brief	�R�s�[���֎~����class
*
*����class���p������class�̓R�s�[�R���X�g���N�^�Ƒ�����Z���֎~����܂�
*/
class NonCopyable
{
	void operator=(const NonCopyable&) = delete;
	NonCopyable(const NonCopyable&) = delete;
protected:
	explicit NonCopyable()
	{

	}
	virtual ~NonCopyable()
	{

	}
};