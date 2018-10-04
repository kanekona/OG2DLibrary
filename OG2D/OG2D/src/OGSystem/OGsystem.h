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
#include "Object\Object.h"
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
class SceneManager
{
	//! ���݃^�X�N
	SceneTask* nowScene;
	//! ���̃^�X�N
	SceneTask* nextScene;
	//! ���^�X�N
	std::vector<SceneTask*> otherScene;
public:
	/**
	*@brief	:constructor
	*/
	explicit SceneManager();
	/**
	*@brief	:destructor
	*/
	virtual ~SceneManager();
	/**
	*@brief	:�^�X�N��o�^����
	*@param	:SceneTask* ���݂ɓo�^�������^�X�N
	*/
	void SetNowTask(SceneTask* task);
	/**
	*@brief	:�^�X�N��o�^����
	*@param	:SceneTask* ���ɓo�^�������^�X�N
	*/
	void SetNextTask(SceneTask* task);
	/**
	*@brief	:�^�X�N��o�^����
	*@param	:SceneTask* �o�^�������^�X�N
	*/
	void SetOtherTask(SceneTask* task);
	/**
	*@brief	:�^�X�N���ڍs����
	*/
	void SceneMigration();
	/**
	*@brief	:���^�X�N�̍폜�Ǘ�
	*/
	void OrtherSceneKillCheck();
	/**
	*@brief	:���݃^�X�N���擾
	*@return:SceneTask* ���݂̃^�X�N
	*/
	SceneTask* GetNowTask() const;
	/**
	*@brief	:���^�X�N���擾
	*@return:SceneTask* ���̃^�X�N
	*/
	SceneTask* GetNextTask() const;
	/**
	*@brief	:���^�X�N��S�擾
	*@return:vector<SceneTask*> ���^�X�N�B
	*/
	std::vector<SceneTask*> GetOtherAllTask() const;
};
/**
*@brief	:���C���V�X�e������
*/
class EngineSystem : private NonCopyable
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
	bool cursor_on;
	//! �t�@�C���p�X
	const std::string path;
	//! �t�@�C����
	std::string file;
	//! WindowPosition
	Vec2 w_pos;	
	//! �`�揇
	std::vector<OrderCheck> orders;
	//! Engine�I����
	bool deleteEngine;
	//! �o�^�ς�GameObject
	std::vector<GameObject*> nowGameObjects;
	//! �o�^�\��GameObject
	std::vector<GameObject*> addGameObjects;
	//! �^�X�N�Ǘ�
	SceneManager* _sceneManager;
public:
	//! �J����2D
	Camera2D* camera;
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
	explicit EngineSystem();
	/**
	*@brief	:constructor
	*@param	:int x WindowSizeX
	*@param	:int y WindowSizeY
	*@param	:char* name WindowName
	*@param	:bool flag ScreenMode
	*/
	explicit EngineSystem(
		const int x,
		const int y,
		const char* name,
		const bool flag = false);
	/**
	*@brief	:destructor
	*/
	virtual ~EngineSystem();
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
	*@brief	:�S�I�u�W�F�N�g�̍폜����
	*/
	void AllObjectKill();
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
	void TaskGameUpdate();
	/**
	*@brief	:�^�X�N��o�^����
	*@param	:SceneTask* task �^�X�N
	*/
	void SetTask(
		SceneTask* task);
	/**
	*@brief	:�^�X�N��o�^����
	*@param	:GameObject* object GameObject
	*/
	void SetGameObject(
		GameObject* object);
	/**
	*@brief	:�J�n�^�X�N��o�^����
	*@param	:SceneTask* task �^�X�N
	*/
	void SetStartTask(
		SceneTask* task);
	/**
	*@brief	:�o�^����Ă���I�u�W�F�N�g���ׂĂ��擾����
	*@return:vector<GameObject*> �o�^�S�I�u�W�F�N�g
	*/
	std::vector<GameObject*> GetAllObject() const;
	/**
	*@brief	:�o�^�\��I�u�W�F�N�g���ׂĂ��擾����
	*@return:vector<GameObject*> �o�^�\��S�I�u�W�F�N�g
	*/
	std::vector<GameObject*> GetAllAddObject() const;
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
	*@brief	:�I�u�W�F�N�g����(�ŏ��̓����̃I�u�W�F�N�g��Ԃ�)
	*@param	:string objectName �I�u�W�F�N�g��
	*@return:�w��P�̃^�X�Nclass
	*/
	template <class T> T* GetObject(const std::string& objectName) const
	{
		for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == objectName)
				{
					return (T*)(*id);
				}
			}
		}
		for (auto id = this->addGameObjects.begin(); id != this->addGameObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == objectName)
				{
					return (T*)(*id);
				}
			}
		}
		return nullptr;
	}
	/**
	*@brief	:�I�u�W�F�N�g����(�������ׂĂ�Ԃ�)
	*@param	:string objectName �I�u�W�F�N�g��
	*@return:�w�蕡���^�X�Nclass
	*/
	template <class T> std::vector<T*> GetObjects(const std::string& objectName) const
	{
		std::vector<T*> w;
		for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == objectName)
				{
					w.push_back((T*)(*id));
				}
			}
		}
		for (auto id = this->addGameObjects.begin(); id != this->addGameObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == objectName)
				{
					w.push_back((T*)(*id));
				}
			}
		}
		return w;
	}
	/**
	*@brief	:NowScene�擾
	*@return:template class* ����Scene
	*/
	template <class T> T* GetNowScene() const
	{
		if (this->_sceneManager->GetNowTask())
		{
			return (T*)(this->_sceneManager->GetNowTask());
		}
		return nullptr;
	}
	/**
	*@brief	:NextScene�擾
	*@return:template class* ��Scene
	*/
	template <class T> T* GetNextScene() const
	{
		if (this->_sceneManager->GetNextTask())
		{
			return (T*)(this->_sceneManager->GetNextTask());
		}
		return nullptr;
	}
	/**
	*@brief	:OtherScene����
	*@param	:std::string name Scene��
	*@return:vector<template class*> �Y��Scene�B
	*/
	template <class T> std::vector<T*> GetSceneOthers(const std::string& name) const
	{
		std::vector<T*> w;
		auto id = this->_sceneManager->GetOtherAllTask();
		for (auto is = id.begin(); is != id.end(); ++is)
		{
			if ((*is)->GetTaskName() == name)
			{
				w.push_back((T*)(*is));
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
	void Task_Update();
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
	/**
	*@brief	:Scene�̏�ԃ`�F�b�N
	*/
	void SceneStateCheck();
	/**
	*@brief	:GameObjects�̏�ԃ`�F�b�N
	*/
	void GameObjectsStateCheck();
};

extern EngineSystem* ge;
extern ResourceManager* rm;