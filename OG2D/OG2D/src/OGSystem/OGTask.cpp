#include "OGSystem\OGTask.h"
void _OGTK::_myGameInitialize()
{
	//��������Window���
	gameEngine->SetWindow(960, 540, "WindowName", false);
	//�^�X�N�̏�����
	nowTask = NON;
	nextTask = Task_Title;
}
//�^�X�N�V�X�e������
void _OGTK::_myGameUpdate()
{
	if (nowTask != nextTask)
	{
		//�������
		switch (nowTask)
		{
		case Task_Title:
		
			break;
		case Task_Game:
			
			break;
		}
		nowTask = nextTask;
		//�^�X�N���ς��Ƃ��Ƀ��Z�b�g����Q�[���G���W���̏���
		gameEngine->ChengeTask();
		//����������
		switch (nowTask)
		{
		case Task_Title:
			
			break;
		case Task_Game:
			
			break;
		}
	}
	if (!gameEngine->GetPause()) {
		//�ʏ�X�V����
		switch (nowTask)
		{
		case Task_Title:
			
			break;
		case Task_Game:
			
			break;
		}
	}
	else
	{
		//Pause�����������ɋL�q
		switch (nowTask)
		{
		case Task_Title:
			break;
		case Task_Game:
			break;
		}
	}
}

void _OGTK::_myGameRender2D()
{
	//�`�揈��
	switch (nowTask)
	{
	case Task_Title:
		break;
	case Task_Game:
		break;
	}
}

void _OGTK::_myGameRender3D()
{
	//�`�揈��
}

void _OGTK::_myGameFinalize()
{
	//���������������̓A�v���P�[�V�������I������Ƃ��ɌĂяo�����
	switch (nowTask)
	{
	case Task_Title:
		break;
	case Task_Game:
		break;
	}
}