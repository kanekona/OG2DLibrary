#pragma once
//______________________________//
//|�^�X�N�V�X�e��               |//
//|�����F2018/03/20���q��       |//
//|____________________________|//
#include "OGSystem\_OGsystem.h"
#include "Win\WinMain.h"
//������������������//
//�ǉ��^�X�N       //
//������������������//
#include "Task\Task_Sample.h"
#include "Task\Task_Sample2.h"

class _OGTK
{
public:
	//������������������//
	//�^�X�Nclass�̐錾//
	//������������������//
	//�^�X�Nclass�̒ǉ��͂�����
	//cpp�ɂ����l�ɋL�q
	Sample s;
	Sample2 s2;

	////////////////////////////
	//�������牺�͕ύX���Ȃ�����//
	///////////////////////////
	//�^�X�N�ϐ�
	TaskFlag nowTask, nextTask;
	//�����E�B���h�E
	Window _window;
	//�^�X�N�V�X�e���֐�
	void _myGameInitialize();
	void _myGameUpDate();
	void _myGameRender2D();
	void _myGameRender3D();
	void _myGameFinalize();
};