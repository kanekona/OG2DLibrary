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
#include "Font\TextureFont.h"
#include "TaskObject.h"
/**
*@brief	:�`�揇���Ǘ�����class
*/
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
/**
*@brief	:���C���V�X�e������
*/
class EngineSystem
{
	//! �I����
	bool end;
	//! WindowSize_W
	int w_wi;
	//! WindowSize_H
	int w_he;
	//! WindowName
	const char* w_na;
	//! WindowMode
	bool w_sc;
	//! �J�[�\������
	bool Cursor_on;
	//! �t�@�C���p�X
	const std::string path;
	//! �t�@�C����
	std::string file;
	//! WindowPosition
	Vec2 w_pos;	
	//! �`�揇
	std::vector<OrderCheck> Orders;
	//! Engine�I����
	bool DeleteEngine;
	//! �o�^�^�X�N
	std::vector<std::pair<unsigned short, TaskObject*>> taskObjects;
	//! �o�^�\��^�X�N
	std::vector<TaskObject*> addTaskObjects;
public:
	//! �J����2D
	Camera2D * camera;
	//! window
	Window* window;
	//! �t���[�����[�g
	FPS* fps;
	//! �f�o�C�X�Ǘ�
	Audio* audiodevice;
	//! �T�E���h�Ǘ�
	SoundManager* soundManager;
	//! ���͊Ǘ�
	Input* in;
	//! �f�o�b�O�@�\
	bool DebugFunction;
	/**
	*@brief	:constructor
	*/
	EngineSystem();
	/**
	*@brief	:constructor
	*@param	:int x WindowSizeX
	*@param	:int y WindowSizeY
	*@param	:char* name WindowName
	*@param	:bool flag ScreenMode
	*/
	EngineSystem(
		const int x,
		const int y,
		const char* name,
		const bool flag = false);
	/**
	*@brief	:destructor
	*/
	~EngineSystem();
	/**
	*@brief	:����������
	*@return:������true
	*/
	bool Initialize();
	/**
	*@brief	:System�X�V����
	*/
	void Update();
	/**
	*@brief	:Window���o�^
	*@param	:int x WindowSizeX
	*@param	:int y WindowSizeY
	*@param	:char* name WindowName
	*@param	:bool flag ScreenMode
	*/
	void SetWindow(
		const int x,
		const int y,
		const char* name,
		const bool flag = false);
	/**
	*@brief	:Window�����ʒu�o�^
	*@param	:Vec2 pos �ʒu���
	*/
	void SetWindowPos(const Vec2& pos);
	/**
	*@brief	:�J�[�\�������ݒ�
	*@param	:bool flag �����ݒ�
	*/
	void SetCursorOn(const bool flag);
	/**
	*@brief	:�A�C�R���摜�ݒ�
	*@param	:string path �t�@�C���p�X�t�@�C���p�X
	*/
	void SetIcon(const std::string& path);
	/**
	*@brief	:�S�^�X�N�̒�~�ݒ�
	*@param	:bool flag ��~�ݒ�
	*/
	void AllStop(const bool flag = true);
	/**
	*@brief	:�S�^�X�N�̃|�[�Y�ݒ�
	*@param	:bool flag �|�[�Y�ݒ�
	*/
	void AllPause(const bool flag = true);
	/**
	*@brief	:�A�v���P�[�V�����I��
	*/
	void GameEnd();
	/**
	*@brief	:�I���ݒ��Ԃ�
	*@return:bool �I���ݒ�
	*/
	bool GetEnd() const;
	/**
	*@brief	:�^�X�N�ύX������
	*/
	void ChengeTask();
	/**
	*@brief	:�^�X�N�B�̍X�V����
	*/
	void TaskGameUpDate();
	/**
	*@brief	:�^�X�N��o�^����
	*@param	:TaskObject* task �^�X�N
	*/
	void SetTaskObject(
		TaskObject* task);
	/**
	*@brief	:�G���W���I����Ԃ�
	*@return:bool �G���W���I���ݒ�
	*/
	bool GetDeleteEngine();
	/**
	*@brief	:�G���W���I����o�^
	*@param	:bool falg �I���ݒ�
	*/
	void SetDeleteEngine(const bool flag);
	/**
	*@brief	:�o�^����Ă���^�X�N��\������
	*/
	void ShowNameAddedObject();
	/**
	*@brief	:�^�X�N����(�ŏ��̓����̃^�X�N��Ԃ�)
	*@param	:string taskName �^�X�N��
	*@return:�w��P�̃^�X�Nclass
	*/
	template <class T> T* GetTask(const std::string& taskName)
	{
		for (auto id = this->taskObjects.begin(); id != this->taskObjects.end(); ++id)
		{
			if (id->second)
			{
				if (id->second->GetTaskName() == taskName)
				{
					return (T*)id->second;
				}
			}
		}
		for (auto id = this->addTaskObjects.begin(); id != this->addTaskObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTaskName() == taskName)
				{
					return (T*)(*id);
				}
			}
		}
		return nullptr;
	}
	/**
	*@brief	:�^�X�N����(�������ׂĂ�Ԃ�)
	*@param	:string taskName �^�X�N��
	*@return:�w�蕡���^�X�Nclass
	*/
	template <class T> std::vector<T*> GetTasks(const std::string& taskName)
	{
		std::vector<T*> w;
		for (auto id = this->taskObjects.begin(); id != this->taskObjects.end(); ++id)
		{
			if (id->second)
			{
				if (id->second->GetTaskName() == taskName)
				{
					w.push_back((T*)id->second);
				}
			}
		}
		for (auto id = this->addTaskObjects.begin(); id != this->addTaskObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTaskName() == taskName)
				{
					w.push_back((T*)(*id));
				}
			}
		}
		return w;
	}
private:
	/**
	*@brief	:�o�^�\��^�X�N��o�^����
	*/
	void TaskApplication();
	/**
	*@brief	:�`�揇��ݒ肷��
	*/
	void ConfigDrawOrder();
	/**
	*@brief	:�o�^�\��^�X�N�̗L��
	*@return:�o�^�\��^�X�N�����݂����true
	*/
	bool CheckAddTask();
	/**
	*@brief	:�폜�\��^�X�N�̗L��
	*@return:�폜�\��^�X�N�����݂����true
	*/
	bool CheckKillTask();
	/**
	*@brief	:�^�X�N�X�V����
	*/
	void Task_UpDate();
	/**
	*@brief	:�^�X�N�`�揈��
	*/
	void Task_Render_AF();
	/**
	*@brief	:�폜�\��^�X�N���폜����
	*/
	void TaskKillCheck();
	/**
	*@brief	:�o�^�^�X�N�S�폜
	*/
	void AllTaskDelete();
};

extern EngineSystem* OGge;
extern ResourceManager* rm;