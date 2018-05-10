#pragma once
//_____________________________
//|�V�X�e���N���X�Q             
//|�����F2018/03/20       
//|�����F2018/03/23		   
//|____________________________
#include "Camera\Camera.h"
#include "Window\Window.h"
#include "FPS\FPS.h"
#include "Input\Input.h"
#include "Texture\Texture.h"
#include "Collision\Collision.h"
#include "Font\Font.h"
#include "Audio\SoundManager.h"
#include "Timer\glTimer.h"
#include "Easing\easing.hpp"
#include "Audio\StreamingSound.h"
#include "Random\Random.h"
#include "TaskObject.h"

class OrderCheck
{
public:
	OrderCheck()
	{
		this->id = -1;
		this->order_s = -1.f;
	}
	int id;
	float order_s;
};

class EngineSystem
{
private:
	bool end;			//�I����
	int w_wi;			//WindowSize
	int w_he;			//WindowSize
	char* w_na;			//WindowName
	bool w_sc;			//WindowMode
	bool isPause;		//PauseCheck
	bool Cursor_on;		//�J�[�\������
	const std::string path = "./data/image/";	//�t�@�C���p�X
	std::string file;	//�t�@�C����
	Vec2 w_pos;			//WindowPosition
	std::vector<OrderCheck> Orders;	//�`�揇
	bool DeleteEngine;	//Engine�I����
public:
	EngineSystem();			//�R���X�g���N�^
	EngineSystem(			//�R���X�g���N�^
		int,
		int,
		char*,
		bool = false);
	~EngineSystem();		//�f�X�g���N�^
	//Camera2D::SP camera;	//�J����2D
	Camera2D* camera;
	//Window::SP window;		//Window
	Window* window;
	//FPS::SP fps;			//fps
	FPS* fps;
	//Audio::SP audiodevice;//Audio
	Audio* audiodevice;
	//SoundManager::SP soundManager;//Sound�Ǘ�
	SoundManager* soundManager;
	//Input in;				//���͏�
	Input* in;
	
	bool Initialize();		//����������
	void Update();			//�X�V����
	void SetWindow(			//Window���o�^
		int,
		int,
		char*,
		bool = false);
	void SetWindowPos(Vec2&);	//Window�����ʒu�ݒ�
	void SetCursorOn(const bool);	//�J�[�\�������L��
	void SetIcon(std::string&);	//�A�C�R���g�p�摜�ݒ�
	bool DebugFunction;			//�f�o�b�O�@�\
	void SetPause(const bool);	//�|�[�Y�ݒ�
	bool GetPause() const;		//�|�[�Y��Ԃ�
	void GameEnd();				//�A�v���P�[�V�����I���o�^
	bool GetEnd() const;		//�A�v���P�[�V�����I����Ԃ�
	void ChengeTask();			//�^�X�N�ύX������
	void TaskGameUpDate();		//�^�X�N�B�̍X�V����
	void SetTaskObject(			//�^�X�N��o�^
		const TaskObject::SP&);
	bool GetDeleteEngine();		//�G���W���I����Ԃ�
	void SetDeleteEngine(bool);	//�G���W���I���o�^
	//template <class T>std::shared_ptr<T> GetTask(const std::string&);
	//�^�X�N����(�ŏ��̓����̃^�X�N��Ԃ�)
	template <class T> std::shared_ptr<T> GetTask(const std::string& taskName)
	{
		for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
		{
			if ((*id).second->GetTaskName() == taskName)
			{
				return std::static_pointer_cast<T>((*id).second);
			}
		}
		return nullptr;
	}
private:
	void TaskApplication();	//�^�X�N�o�^�\���o�^����
	void ConfigDrawOrder();	//�`�揇��ݒ肷��
	bool CheckAddTask();	//�o�^�\��̃^�X�N�̗L��
	bool CheckKillTask();	//�폜�\��̃^�X�N�̗L��
	void Task_UpDate();			//�^�X�N�X�V����
	void Task_Render_AF();		//�^�X�N�`�揈��
	void TaskKillCheck();		//�폜�\��̃^�X�N���폜
	void AllTaskDelete();		//�o�^�^�X�N�S�폜
	std::vector<std::pair<DWORD, TaskObject::SP>> taskobjects;	//�^�X�N�I�u�W�F�N�g�B
	std::vector<TaskObject::SP> addTaskObjects;	//�o�^�\��^�X�N�B
};

extern EngineSystem* OGge;