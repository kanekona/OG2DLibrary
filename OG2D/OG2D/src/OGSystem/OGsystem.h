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
#include "ResourceManager\ResourceManager.h"
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
	bool end;			//�I����
	int w_wi;			//WindowSize
	int w_he;			//WindowSize
	char* w_na;			//WindowName
	bool w_sc;			//WindowMode
	bool isPause;		//PauseCheck
	bool Cursor_on;		//�J�[�\������
	const std::string path;	//�t�@�C���p�X
	std::string file;	//�t�@�C����
	Vec2 w_pos;			//WindowPosition
	std::vector<OrderCheck> Orders;	//�`�揇
	bool DeleteEngine;	//Engine�I����
	std::vector<std::pair<DWORD, TaskObject::SP>> taskobjects;	//�^�X�N�I�u�W�F�N�g�B
	std::vector<TaskObject::SP> addTaskObjects;	//�o�^�\��^�X�N�B
public:
	Camera2D * camera;		//�J����2D
	Window* window;			//window
	FPS* fps;				//�t���[�����[�g
	Audio* audiodevice;		//�f�o�C�X�Ǘ�
	SoundManager* soundManager;	//�T�E���h�Ǘ�
	Input* in;				//���͊Ǘ�
	bool DebugFunction;			//�f�o�b�O�@�\
	EngineSystem();			//�R���X�g���N�^
	EngineSystem(			//�R���X�g���N�^
		const int,
		const int,
		char*,
		const bool = false);
	~EngineSystem();		//�f�X�g���N�^
	
	bool Initialize();		//����������
	void Update();			//�X�V����
	void SetWindow(			//Window���o�^
		const int,
		const int,
		char*,
		const bool = false);
	void SetWindowPos(const Vec2&);	//Window�����ʒu�ݒ�
	void SetCursorOn(const bool);	//�J�[�\�������L��
	void SetIcon(const std::string&);	//�A�C�R���g�p�摜�ݒ�
	void SetPause(const bool);	//�|�[�Y�ݒ�
	bool GetPause() const;		//�|�[�Y��Ԃ�
	void GameEnd();				//�A�v���P�[�V�����I���o�^
	bool GetEnd() const;		//�A�v���P�[�V�����I����Ԃ�
	void ChengeTask();			//�^�X�N�ύX������
	void TaskGameUpDate();		//�^�X�N�B�̍X�V����
	void SetTaskObject(			//�^�X�N��o�^
		const TaskObject::SP&);
	bool GetDeleteEngine();		//�G���W���I����Ԃ�
	void SetDeleteEngine(const bool);	//�G���W���I���o�^
	//�^�X�N����(�ŏ��̓����̃^�X�N��Ԃ�)
	template <class T> std::shared_ptr<T> GetTask(const std::string& taskName)
	{
		for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
		{
			if ((*id).second)
			{
				if ((*id).second->GetTaskName() == taskName)
				{
					return std::static_pointer_cast<T>((*id).second);
				}
			}
		}
		for (auto id = this->addTaskObjects.begin(); id != this->addTaskObjects.end(); ++id)
		{
			if ((*id))
			{
				if ((*id)->GetTaskName() == taskName)
				{
					return std::static_pointer_cast<T>(*id);
				}
			}
		}
		return nullptr;
	}
	template <class T> std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks(const std::string& taskName)
	{
		std::shared_ptr<std::vector<std::shared_ptr<T>>> w = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>> ());
		for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
		{
			if ((*id).second)
			{
				if ((*id).second->GetTaskName() == taskName)
				{
					w->push_back(std::static_pointer_cast<T>((*id).second));
				}
			}
		}
		for (auto id = this->addTaskObjects.begin(); id != this->addTaskObjects.end(); ++id)
		{
			if ((*id))
			{
				if ((*id)->GetTaskName() == taskName)
				{
					w->push_back(std::static_pointer_cast<T>((*id)));
				}
			}
		}
		return w;
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
};

extern EngineSystem* OGge;
extern ResourceManager* rm;