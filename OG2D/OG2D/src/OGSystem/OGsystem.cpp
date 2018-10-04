#include "OGsystem.h"
//--------------------------------------------------
//@:SceneManager
//--------------------------------------------------
SceneManager::SceneManager()
{
	this->nowScene = nullptr;
	this->nextScene = nullptr;
}
SceneManager::~SceneManager()
{
	OG::Destroy<SceneTask>(this->nowScene);
	OG::Destroy<SceneTask>(this->nextScene);
}
void SceneManager::SetNowTask(SceneTask* task)
{
	OG::Destroy<SceneTask>(this->nowScene);
	this->nowScene = task;
}
void SceneManager::SetNextTask(SceneTask* task)
{
	OG::Destroy<SceneTask>(this->nextScene);
	this->nextScene = task;
}
void SceneManager::SceneMigration()
{
	OG::Destroy<SceneTask>(this->nowScene);
	this->nowScene = this->nextScene;
	this->nextScene = nullptr;
}
SceneTask* SceneManager::GetNowTask() const
{
	return this->nowScene;
}
SceneTask* SceneManager::GetNextTask() const
{
	return this->nextScene;
}
//--------------------------------------------------
//@:GameEngineclass									
//--------------------------------------------------
EngineSystem::EngineSystem()
	:path("./data/image/")
{
	//Window��񂪃Z�b�g����Ȃ��������̂��߂̏����ݒ�
	this->w_wi = 960;
	this->w_he = 540;
	this->w_na = "NoName";
	this->w_sc = false;
	this->cursor_on = true;
	this->file = "testicon.png";
	this->w_pos = { 1920 - this->w_wi, 50 };
	this->deleteEngine = false;
}
EngineSystem::EngineSystem(const int widht,const int height, const char* name, const bool screen)
{
	this->w_he = widht;
	this->w_he = height;
	this->w_na = name;
	this->w_sc = screen;
}
bool EngineSystem::Initialize()
{
	//����������
	//Window�̐���
	this->window = new Window(w_wi, w_he, w_na, w_sc, w_pos);
	//Window�ݒ�
	this->window->LimitsWindow();
	this->window->InMouseMode(this->cursor_on);
	this->window->SetIcon(this->path + this->file);
	//�J����2D�̐���
	this->camera = new Camera2D(Box2D(0, 0, w_wi, w_he));
	//fps�̐ݒ�
	this->fps = new FPS();
	//���͊֘A�̏�����
	this->in = new Input();
	this->in->Inputinit(this->window->GetWindow());
	//�T�E���h�Ǘ��̏�����
	this->soundManager = new SoundManager();
	//�I�[�f�B�I�f�o�C�X�̏������Ɛݒ�
	this->audiodevice = new Audio();
	//�V�[���Ǘ��𐶐�
	this->_sceneManager = new SceneManager();
	//�e�l�̏�����
	DebugFunction = false;
	this->end = false;
	return true;
}
void EngineSystem::SetWindow(const int width, const int height, const char* name, const bool screen)
{
	//Window����o�^����
	this->w_wi = width;
	this->w_he = height;
	this->w_na = name;
	this->w_sc = screen;
}
void EngineSystem::SetCursorOn(const bool on)
{
	//�J�[�\���̉����L��
	this->cursor_on = on;
}
void EngineSystem::SetIcon(const std::string& filepath_)
{
	//�A�C�R���Ɏg�p����摜�̐ݒ�
	this->file = filepath_;
}
void EngineSystem::Update()
{
	//���͏󋵂̍X�V
	this->in->Update();
#if(_DEBUG)
	this->fps->Update();
#endif
}
void EngineSystem::Task_Update()
{
	//SceneManager��Update���Ă�
	if (this->_sceneManager->GetNowTask())
	{
		this->_sceneManager->GetNowTask()->UpdateManager();
	}
	//GameObjects��Update���Ă�
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
	{
		(*id)->UpdateManager();
	}
}
void EngineSystem::Task_Render_AF()
{
	//GameObjects��Render���Ă�
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
	{
		(*id)->RenderManager();
	}
}
void EngineSystem::TaskGameUpdate()
{
	this->Task_Update();		//�X�V����
	this->camera->Update();	//�J��������
	this->Task_Render_AF();		//�`�揈��
	this->SceneStateCheck();		//�V�[���̏�ԊǗ�
	this->GameObjectsStateCheck();	//�Q�[���I�u�W�F�N�g�̏�Ԋm�F
}
void EngineSystem::SceneStateCheck()
{
	if (this->_sceneManager->GetNowTask())
	{
		if (this->_sceneManager->GetNowTask()->ModeCheck(Scene::KILL))
		{
			//�I�u�W�F�N�g�̍폜���w�肳��Ă���Ȃ��
			if (this->_sceneManager->GetNowTask()->GetGameObjectDestroy())
			{
				this->AllObjectKill();
			}
			this->_sceneManager->SceneMigration();
			if (!this->_sceneManager->GetNowTask())
			{
				this->GameEnd();
			}
		}
	}
}
void EngineSystem::GameObjectsStateCheck()
{
	//GameObject�̓o�^
	if (this->CheckAddTask() || this->CheckKillTask())
	{
		this->TaskApplication();	//�o�^�\��̃^�X�N��o�^����
		this->TaskKillCheck();		//�폜�\��̃^�X�N���폜����
		this->ConfigDrawOrder();	//�^�X�N�̏W���̂̕ύX��ɕ`�揇��ݒ肷��
	}
}
void EngineSystem::ConfigDrawOrder()
{
	//�`�揇�̐ݒ�
	//�o�^�^�X�N���̕`�揇�����Ă���class������Ă���
	this->orders.resize(this->nowGameObjects.size());
	//������Ԃ��R�s�[����
	for (int i = 0; i < this->nowGameObjects.size(); ++i)
	{
		this->orders[i].id = i;
		this->orders[i].order_s = this->nowGameObjects[i]->GetDrawOrder();
	}
	//�`�揇�ɍ��킹��id��order����ёւ���
	for (int i = 0; i < this->nowGameObjects.size(); ++i)
	{
		for (int j = i; j < this->nowGameObjects.size(); ++j)
		{
			if (this->orders[i].order_s > this->orders[j].order_s)
			{
				OrderCheck kari = this->orders[i];
				this->orders[i] = this->orders[j];
				this->orders[j] = kari;
			}
		}
	}
}
EngineSystem::~EngineSystem()
{
	//�o�^���Ă���^�X�N�����ׂĔj������
	delete this->_sceneManager;
	this->AllTaskDelete();
	//��������class��delete����
	delete this->audiodevice;
	delete this->soundManager;
	delete this->fps;
	delete this->in;
	delete this->window;
	delete this->camera;
}
void EngineSystem::GameEnd()
{
	//�A�v���P�[�V�����̏I���\��ݒ�
	this->end = true;
}
bool EngineSystem::GetEnd() const
{
	//�A�v���P�[�V�������I���̗L����Ԃ�
	return this->end;
}
void EngineSystem::ChengeTask()
{
	//�^�X�N��ύX����ۂɌ��ɖ߂���������
	this->camera->SetPos(Vec2(0.f, 0.f));
	this->camera->SetSize(this->window->GetSize());
	//this->soundManager->AllDelete();
}
void EngineSystem::SetTask(SceneTask* to)
{
	this->_sceneManager->SetNextTask(to);
}
void EngineSystem::SetStartTask(SceneTask* to)
{
	this->_sceneManager->SetNowTask(to);
}
void EngineSystem::SetGameObject(GameObject* object)
{
	this->addGameObjects.push_back(object);
}
std::vector<GameObject*> EngineSystem::GetAllObject() const
{
	return this->nowGameObjects;
}
std::vector<GameObject*> EngineSystem::GetAllAddObject() const
{
	return this->addGameObjects;
}
void EngineSystem::TaskApplication()
{
	//�o�^�\��̂��̂�o�^����
	for (int id = 0; id < this->addGameObjects.size(); ++id)
	{
		GameObject* d;
		d = this->addGameObjects[id];
		this->nowGameObjects.push_back(d);
	}
	addGameObjects.clear();
}
void EngineSystem::TaskKillCheck()
{
	//�폜�\��̃^�X�N���폜����
	auto id = this->nowGameObjects.begin();
	while (id != this->nowGameObjects.end())
	{
		if (*id)
		{
			if ((*id)->ModeCheck(GO::Mode::KILL))
			{
				delete *id;
				this->nowGameObjects.erase(id);
				this->TaskApplication();
				id = this->nowGameObjects.begin();
			}
			else
			{
				++id;
			}
		}
		else
		{
			++id;
		}
	}
}
bool EngineSystem::CheckAddTask()
{
	return this->addGameObjects.size() > 0;
}
bool EngineSystem::CheckKillTask()
{
	for (int i = 0; i < this->nowGameObjects.size(); ++i)
	{
		if (this->nowGameObjects[i]->ModeCheck(GO::Mode::KILL))
		{
			return true;
		}
	}
	return false;
}
void EngineSystem::AllTaskDelete()
{
	//�S�폜
	{
		auto id = this->nowGameObjects.begin();
		while (id != this->nowGameObjects.end())
		{
			delete *id;
			this->nowGameObjects.erase(id);
			id = this->nowGameObjects.begin();
		}
	}
	{
		auto id = this->addGameObjects.begin();
		while (id != this->addGameObjects.end())
		{
			delete *id;
			this->addGameObjects.erase(id);
			id = this->addGameObjects.begin();
		}
	}
}
void EngineSystem::AllPause(const bool flag)
{
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
	{
		if (*id)
		{
			(*id)->SetPause(flag);
		}
	}
	for (auto id = this->addGameObjects.begin(); id != this->addGameObjects.end(); ++id)
	{
		if ((*id))
		{
			(*id)->SetPause(flag);
		}
	}
}
void EngineSystem::SetWindowPos(const Vec2& pos)
{
	//Window�̈ʒu��Ԃ�
	this->w_pos = pos;
}
void EngineSystem::SetDeleteEngine(const bool flag)
{
	//�G���W���̏I����o�^
	this->deleteEngine = flag;
}
bool EngineSystem::GetDeleteEngine()
{
	//�G���W���I����Ԃ�
	return this->deleteEngine;
}
void EngineSystem::ShowNameAddedObject()
{
	for (auto id = this->nowGameObjects.begin(); id != this->nowGameObjects.end(); ++id)
	{
		std::cout << (*id)->GetTag() << ":";
	}
	std::cout << std::endl;
}
void EngineSystem::AllStop(const bool flag)
{
	for (auto id = nowGameObjects.begin(); id != nowGameObjects.end(); ++id)
	{
		if (*id)
		{
			(*id)->SetStop(flag);
		}
	}
	for (auto id = addGameObjects.begin(); id != addGameObjects.end(); ++id)
	{
		if ((*id))
		{
			(*id)->SetStop(flag);
		}
	}
}
void EngineSystem::AllObjectKill()
{
	for (auto id = nowGameObjects.begin(); id != nowGameObjects.end(); ++id)
	{
		if (*id)
		{
			(*id)->Kill();
		}
	}
}
//! �����V�X�e���G���W��
EngineSystem* ge;
//! ���\�[�X�Ǘ��V�X�e��
ResourceManager* rm;