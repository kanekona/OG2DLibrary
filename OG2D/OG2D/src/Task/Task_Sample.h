#pragma once
//______________________________//
//|�T���v���^�X�N               |//
//|�����F2018/03/20���q��       |//
//|____________________________|//
#include "Win\WinMain.h"
#include "OGSystem\OGsystem.h"

class Sample
{
public:
	void Initialize();
	TaskFlag UpDate();
	void Render2D();
	void Finalize();
	//��������//
	//�ǉ��ϐ�//
	//��������//
	Sound s;
	Sound a;
	std::string file2 = "stereo.wav";
	std::string file = "playandhope.wav";
};