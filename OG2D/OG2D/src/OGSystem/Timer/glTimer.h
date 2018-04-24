#pragma once

#include "OGSystem\_OGsystem.h"

class Time
{
public:
	Time();
	~Time();
	//�v���J�n
	void Start();
	//�v����~
	void Stop();
	//�ꎞ��~
	void Pause();
	//���݃^�C��
	float GetTime();
	//�J�n�^�C���̕ύX
	void InitTime(const float time_);
	//�v������
	bool isplay() const;
private:
	//�����^�C��
	float initTime;
	//���݃^�C��
	float nowTime;
	//��~���̃^�C���̕ۑ�
	float saveTime;
	//�ǉ��^�C��
	float addTime;
	//�v��������
	bool isPlay;
	//���쒆����
	bool behavior;
};