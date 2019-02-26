#pragma once
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
#include "Object\GameObject.h"
#include "Object\SceneTask.h"
#include "Object\UITask.h"
#include "Shader\shader.h"
#include "Order\Order.h"
#include "Texture\LayerTexture.h"
/**
*@brief	scene���Ǘ�����class
*/
class SceneManager_
{
	//! ���݃^�X�N
	SceneTask* nowScene;
	//! ���̃^�X�N
	SceneTask* nextScene;
	//! ���^�X�N
	std::vector<SceneTask*> otherScene;
public:
	/**
	*@brief	constructor
	*/
	explicit SceneManager_();
	/**
	*@brief	destructor
	*/
	virtual ~SceneManager_();
	/**
	*@brief	�^�X�N��o�^����
	*@param[in]	SceneTask* ���݂ɓo�^�������^�X�N
	*/
	void SetNowTask(SceneTask* task);
	/**
	*@brief	�^�X�N��o�^����
	*@param[in]	SceneTask* ���ɓo�^�������^�X�N
	*/
	void SetNextTask(SceneTask* task);
	/**
	*@brief	�^�X�N��o�^����
	*@param[in]	SceneTask* �o�^�������^�X�N
	*/
	void SetOtherTask(SceneTask* task);
	/**
	*@brief	�^�X�N���ڍs����
	*/
	void SceneMigration();
	/**
	*@brief	���^�X�N�̍폜�Ǘ�
	*/
	void OrtherSceneKillCheck();
	/**
	*@brief	���݃^�X�N���擾
	*@return SceneTask* ���݂̃^�X�N
	*/
	SceneTask* GetNowTask() const;
	/**
	*@brief	���^�X�N���擾
	*@return SceneTask* ���̃^�X�N
	*/
	SceneTask* GetNextTask() const;
	/**
	*@brief	���^�X�N��S�擾
	*@return vector<SceneTask*> ���^�X�N�B
	*/
	std::vector<SceneTask*> GetOtherAllTask() const;
};
/**
*@brief	�Q�[���G���W��
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
	//! Object�`�揇
	std::vector<OrderCheck> object_orders;
	//! UI�`�揇
	std::vector<OrderCheck> ui_orders;
	//! Engine�I����
	bool deleteEngine;
	//! �o�^�ς�GameObject
	std::vector<GameObject*> nowGameObjects;
	//! �o�^�\��GameObject
	std::vector<GameObject*> addGameObjects;
	//! �o�^�ς�UI
	std::vector<UIObject*> nowUIs;
	//! �o�^�\��UI
	std::vector<UIObject*> addUIs;
	//! �^�X�N�Ǘ�
	SceneManager_* _sceneManager;
	//! nextWindowCreate
	bool nextWindowCreateEnable;
	//! �f�o�C�X�Ǘ�
	Audio* audiodevice;
	/**
	*@brief	�o�^�\��^�X�N��o�^����
	*/
	void ObjectApplication();
	/**
	*@brief	Object�`�揇��ݒ肷��
	*/
	void ConfigObjectDrawOrder();
	/**
	*@brief	�o�^�\��^�X�N�̗L��
	*@return �o�^�\��^�X�N�����݂����true
	*/
	bool CheckAddObject();
	/**
	*@brief	�폜�\��^�X�N�̗L��
	*@return �폜�\��^�X�N�����݂����true
	*/
	bool CheckKillObject();
	/**
	*@brief	�폜�\��^�X�N���폜����
	*/
	void ObjectKillCheck();
	/**
	*@brief	�o�^�\��UI��o�^����
	*/
	void UIApplication();
	/**
	*@brief	UI�`�揇��ݒ肷��
	*/
	void ConfigUIDrawOrder();
	/**
	*@brief	�o�^�\��UI�̗L��
	*@return �o�^�\��UI�����݂����true
	*/
	bool CheckAddUI();
	/**
	*@brief	�폜�\��UI�̗L��
	*@return �폜�\��UI�����݂����true
	*/
	bool CheckKillUI();
	/**
	*@brief	�폜�\��UI���폜����
	*/
	void UIKillCheck();
	/**
	*@brief	�^�X�N�X�V����
	*/
	void Task_Update();
	/**
	*@brief	�^�X�N�`�揈��
	*/
	void Task_Render_2D();
	/**
	*@brief	�o�^�^�X�N�S�폜
	*/
	void AllObjectsDelete();
	/**
	*@brief	Scene�̏�ԃ`�F�b�N
	*/
	void SceneStateCheck();
	/**
	*@brief	GameObjects�̏�ԃ`�F�b�N
	*/
	void GameObjectsStateCheck();
	/**
	*@brief	UIs�̏�ԃ`�F�b�N
	*/
	void UIsStateCheck();
public:
	//! �J����2D
	Camera2D* camera;
	//! window
	Window* window;
	//! �t���[�����[�g
	FPS* fps;
	//! �T�E���h�Ǘ�
	SoundManager* soundManager;
	//! ���͊Ǘ�
	Input* in;
	//! �f�o�b�O�@�\
	bool DebugFunction;
	/**
	*@brief	constructor
	*/
	explicit EngineSystem();
	/**
	*@brief	constructor
	*@param[in]	int x WindowSizeX
	*@param[in]	int y WindowSizeY
	*@param[in]	char* name WindowName
	*@param[in]	bool flag ScreenMode
	*/
	explicit EngineSystem(
		const int x,
		const int y,
		const char* name,
		const bool flag = false);
	/**
	*@brief	destructor
	*/
	virtual ~EngineSystem();
	/**
	*@brief	����������
	*@return ������true
	*/
	bool Initialize();
	/**
	*@brief	System�X�V����
	*/
	void Update();
	/**
	*@brief	Window���o�^
	*@param[in]	int x WindowSizeX
	*@param[in]	int y WindowSizeY
	*@param[in]	char* name WindowName
	*@param[in]	bool flag ScreenMode
	*/
	void SetWindow(
		const int x,
		const int y,
		const char* name,
		const bool flag = false);
	/**
	*@brief	Window���擾
	*@param[out]	int* x WindowSizeX
	*@param[out]	int* y WindowSizeY
	*@param[out]	bool* flag ScreenMode
	*@param[out]	Vec2* pos WindowPosition
	*/
	void GetWindow(
		int& x,
		int& y,
		bool& flag,
		Vec2& pos);
	/**
	*@brief	Window�����ʒu�o�^
	*@param[in]	Vec2 pos �ʒu���
	*/
	void SetWindowPos(const Vec2& pos);
	/**
	*@brief	�J�[�\�������ݒ�
	*@param[in]	bool flag �����ݒ�
	*/
	void SetCursorOn(const bool flag);
	/**
	*@brief	�A�C�R���摜�ݒ�
	*@param[in]	string path �t�@�C���p�X�t�@�C���p�X
	*/
	void SetIcon(const std::string& path);
	/**
	*@brief	Window�ݒ菈��
	*/
	void WindowConfig();
	/**
	*@brief	�S�I�u�W�F�N�g�̒�~�ݒ�
	*@param[in]	bool flag ��~�ݒ�
	*/
	void AllObjectStop(const bool flag = true);
	/**
	*@brief	�SUI�̒�~�ݒ�
	*@param[in]	bool flag ��~�ݒ�
	*/
	void AllUIStop(const bool flag = true);
	/**
	*@brief	�S�V�[���̒�~�ݒ�
	*@param[in]	bool flag ��~�ݒ�
	*/
	void AllSceneStop(const bool flag = true);
	/**
	*@brief	�S�^�X�N�̒�~�ݒ�
	*@param[in]	bool flag ��~�ݒ�
	*/
	void AllStop(const bool flag = true);
	/**
	*@brief	�S�I�u�W�F�N�g�̃|�[�Y�ݒ�
	*@param[in]	bool flag �|�[�Y�ݒ�
	*/
	void AllObjectPause(const bool flag = true);
	/**
	*@brief	�S�V�[���̃|�[�Y�ݒ�
	*@param[in]	bool flag �|�[�Y�ݒ�
	*/
	void AllScenePause(const bool flag = true);
	/**
	*@brief	�SUI�̃|�[�Y�ݒ�
	*@param[in]	bool flag �|�[�Y�ݒ�
	*/
	void AllUIPause(const bool flag = true);
	/**
	*@brief	�S�^�X�N�̃|�[�Y�ݒ�
	*@param[in]	bool flag �|�[�Y�ݒ�
	*/
	void AllPause(const bool flag = true);
	/**
	*@brief	�S�I�u�W�F�N�g�̍폜����
	*/
	void AllObjectKill();
	/**
	*@brief	�SUI�̍폜����
	*/
	void AllUIKill();
	/**
	*@brief	�S�V�[���̍폜����
	*/
	void AllSceneKill();
	/**
	*@brief	�S�^�X�N�폜����
	*/
	void AllKill();
	/**
	*@brief	�A�v���P�[�V�����I��
	*/
	void GameEnd();
	/**
	*@brief	�I���ݒ��Ԃ�
	*@return bool �I���ݒ�
	*/
	bool GetEnd() const;
	/**
	*@brief	��Window�������s������Ԃ�
	*@return bool true�Ȃ�Ă�Window�𐶐�����
	*/
	bool GetNextWindowCreateEnable() const;
	/**
	*@brief	�^�X�N�ύX������
	*/
	void ChengeTask();
	/**
	*@brief	�^�X�N�B�̍X�V����
	*/
	void TaskGameUpdate();
	/**
	*@brief	�^�X�N��o�^����
	*@param[in]	SceneTask* task �^�X�N
	*/
	void SetScene(
		SceneTask* task);
	/**
	*@brief	GameObject��o�^����
	*@param[in]	GameObject* object GameObject
	*/
	void SetGameObject(
		GameObject* object);
	/**
	*@brief	UI��o�^����
	*@param[in]	UIObject* ui UI
	*/
	void SetUI(UIObject* ui);
	/**
	*@brief	��Scene��o�^����
	*@param[in]	SceneTask* task Task
	*/
	void SetOtherScene(SceneTask* task);
	/**
	*@brief	�J�n�^�X�N��o�^����
	*@param[in]	SceneTask* task �^�X�N
	*/
	void SetStartTask(
		SceneTask* task);
	/**
	*@brief	�l���Z�b�g
	*/
	void Reset();
	/**
	*@brief	WindowChenge
	*@param[in]	const Vec2& pos WindowPosition
	*@param[in]	const Vec2& size WindowSize
	*@param[in]	char* name WindowTitleName
	*@param[in]	bool screen WindowMode
	*/
	void WindowChenge(const Vec2& pos, const Vec2& size, const char* name, const bool screen);
	/**
	*@brief	WindowChenge
	*@param[in]	int x WindowPosition_x
	*@param[in]	int y WindowPosition_y
	*@param[in]	int w WindowSize_w
	*@param[in] int h WindowSize_h
	*@param[in]	char* name WindowTitleName
	*@param[in]	bool screen WindowMode
	*/
	void WindowChenge(const int x, const int y, const int w, const int h, const char* name, const bool screen);
	/**
	*@brief	�o�^����Ă���I�u�W�F�N�g���ׂĂ��擾����
	*@return vector<GameObject*> �o�^�S�I�u�W�F�N�g
	*/
	std::vector<GameObject*> GetAllObject() const;
	/**
	*@brief	�o�^�\��I�u�W�F�N�g���ׂĂ��擾����
	*@return vector<GameObject*> �o�^�\��S�I�u�W�F�N�g
	*/
	std::vector<GameObject*> GetAllAddObject() const;
	/**
	*@brief	�o�^����Ă���UI���ׂĂ��擾����
	*@return vector<UIObject*> �o�^�SUI
	*/
	std::vector<UIObject*> GetAllUI() const;
	/**
	*@brief	�o�^�\��UI���ׂĂ��擾����
	*@return vector<UIObject*> �o�^�\��SUI
	*/
	std::vector<UIObject*> GetAllAddUI() const;
	/**
	*@brief	��Scene��S�Ď擾����
	*@return vector<SceneTask*> ��Scene�B
	*/
	std::vector<SceneTask*> GetAllOtherScenes() const;
	/**
	*@brief	�G���W���I����Ԃ�
	*@return bool �G���W���I���ݒ�
	*/
	bool GetDeleteEngine();
	/**
	*@brief	�G���W���I����o�^
	*@param[in]	bool falg �I���ݒ�
	*/
	void SetDeleteEngine(const bool flag);
	/**
	*@brief	�o�^����Ă���^�X�N��\������
	*/
	void ShowNameAddedObject();
	/**
	*@brief	�I�u�W�F�N�g����(�ŏ��̓����̃I�u�W�F�N�g��Ԃ�)
	*@param[in]	string objectName �I�u�W�F�N�g��
	*@return template<class*> �w��P�̃^�X�Nclass
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
	*@brief	�I�u�W�F�N�g����(�������ׂĂ�Ԃ�)
	*@param[in]	string objectName �I�u�W�F�N�g��
	*@return vector<template<class*>> �w�蕡���^�X�Nclass
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
					w.emplace_back((T*)(*id));
				}
			}
		}
		for (auto id = this->addGameObjects.begin(); id != this->addGameObjects.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == objectName)
				{
					w.emplace_back((T*)(*id));
				}
			}
		}
		return w;
	}
	/**
	*@brief	UI����(�ŏ��̓�����UI��Ԃ�)
	*@param[in]	string tag UITag
	*@return template<class*> �w��P�̃^�X�Nclass
	*/
	template <class T> T* GetUI(const std::string& tag) const
	{
		for (auto id = this->nowUIs.begin(); id != this->nowUIs.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == tag)
				{
					return (T*)(*id);
				}
			}
		}
		for (auto id = this->addUIs.begin(); id != this->addUIs.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == tag)
				{
					return (T*)(*id);
				}
			}
		}
		return nullptr;
	}
	/**
	*@brief	UI����(�������ׂĂ�Ԃ�)
	*@param[in]	string tag UItag
	*@return vector<template<class*>> �w�蕡���^�X�Nclass
	*/
	template <class T> std::vector<T*> GetUIs(const std::string& tag) const
	{
		std::vector<T*> w;
		for (auto id = this->nowUIs.begin(); id != this->nowUIs.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == tag)
				{
					w.emplace_back((T*)(*id));
				}
			}
		}
		for (auto id = this->addUIs.begin(); id != this->addUIs.end(); ++id)
		{
			if (*id)
			{
				if ((*id)->GetTag() == tag)
				{
					w.emplace_back((T*)(*id));
				}
			}
		}
		return w;
	}
	/**
	*@brief	NowScene�擾
	*@return template<class*> ����Scene
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
	*@brief	NextScene�擾
	*@return template<class*> ��Scene
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
	*@brief	OtherScene����
	*@param[in]	std::string name Scene��
	*@return vector<template class*> �Y��Scene�B
	*/
	template <class T> std::vector<T*> GetSceneOthers(const std::string& name) const
	{
		std::vector<T*> w;
		auto id = this->_sceneManager->GetOtherAllTask();
		for (auto is = id.begin(); is != id.end(); ++is)
		{
			if ((*is)->GetTaskName() == name)
			{
				w.emplace_back((T*)(*is));
			}
		}
		return w;
	}
};

extern EngineSystem* ge;
extern ResourceManager* rm;