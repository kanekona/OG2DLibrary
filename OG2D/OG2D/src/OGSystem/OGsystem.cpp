#include "OGsystem.h"
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
	this->Cursor_on = true;
	this->file = "testicon.png";
	this->w_pos = { 1920 - this->w_wi, 50 };
	this->DeleteEngine = false;
}
EngineSystem::EngineSystem(const int widht,const int height, char* name, const bool screen)
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
	this->window->InMouseMode(this->Cursor_on);
	this->window->setIcon(this->path + this->file);
	//�J����2D�̐���
	this->camera = new Camera2D(Box2D(0, 0, w_wi, w_he));
	//fps�̐ݒ�
	//���f�o�b�O���̂ݎg�p����
#if(_DEBUG)
	this->fps = new FPS();
#endif
	//���͊֘A�̏�����
	this->in = new Input();
	this->in->Inputinit(this->window->GetWindow());
	//�T�E���h�Ǘ��̏�����
	this->soundManager = new SoundManager();
	//�I�[�f�B�I�f�o�C�X�̏������Ɛݒ�
	this->audiodevice = new Audio();
	//�e�l�̏�����
	DebugFunction = false;
	this->isPause = false;
	this->end = false;
	return true;
}
void EngineSystem::SetWindow(const int width, const int height, char* name, const bool screen)
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
	this->Cursor_on = on;
}
void EngineSystem::SetIcon(const std::string& filepath_)
{
	//�A�C�R���Ɏg�p����摜�̐ݒ�
	this->file = filepath_;
}
void EngineSystem::Update()
{
	//���͏󋵂̍X�V
	this->in->upDate();
#if(_DEBUG)
	this->fps->Update();
#endif
}
void EngineSystem::Task_UpDate()
{
	//�o�^�^�X�N�̍X�V�������Ă�
	for (int id = 0; id < this->taskobjects.size();++id)
	{
		if (this->taskobjects[id].second->GetKillCount() == 0) 
		{
			if (!this->GetPause())
			{
				this->taskobjects[id].second->T_UpDate();
			}
			else
			{
				this->taskobjects[id].second->T_Pause();
			}
		}
	}
}
void EngineSystem::Task_Render_AF()
{
	//�`�揇��Draw2D�����s����
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		if (this->taskobjects[this->Orders[i].id].second->GetKillCount() == 0)
		{
			this->taskobjects[this->Orders[i].id].second->T_Render();
		}
	}
}
void EngineSystem::TaskGameUpDate()
{
	this->Task_UpDate();		//�X�V����
	this->camera->CameraUpdate();	//�J��������
	this->Task_Render_AF();		//�`�揈��
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
	this->Orders.resize(this->taskobjects.size());
	//������Ԃ��R�s�[����
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		this->Orders[i].id = i;
		this->Orders[i].order_s = this->taskobjects[i].second->GetDrawOrder();
	}
	//�`�揇�ɍ��킹��id��order����ёւ���
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		for (int j = i; j < this->taskobjects.size(); ++j)
		{
			if (this->Orders[i].order_s > this->Orders[j].order_s)
			{
				OrderCheck kari = this->Orders[i];
				this->Orders[i] = this->Orders[j];
				this->Orders[j] = kari;
			}
		}
	}
}
EngineSystem::~EngineSystem()
{
	//�o�^���Ă���^�X�N�����ׂĔj������
	this->AllTaskDelete();
	//��������class��delete����
	delete this->audiodevice;
	delete this->soundManager;
#if(_DEBUG)
	delete this->fps;
#endif
	delete this->in;
	delete this->window;
	delete this->camera;
}
void EngineSystem::SetPause(const bool ispause_)
{
	//�|�[�Y�ݒ�
	this->isPause = ispause_;
}
bool EngineSystem::GetPause() const
{
	//�|�[�Y�󋵂�Ԃ�
	return this->isPause;
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
	this->SetPause(false);
	//this->soundManager->AllDelete();
}
void EngineSystem::SetTaskObject(const TaskObject::SP& To)
{
	//�^�X�N��o�^�\��ɓo�^
	this->addTaskObjects.push_back(To);
}
void EngineSystem::TaskApplication()
{
	//�o�^�\��̂��̂�o�^����
	for (int i = 0; i < this->addTaskObjects.size(); ++i)
	{
		std::pair<DWORD, TaskObject::SP> d;
		d.second = this->addTaskObjects[i];
		if (d.second->GetNextTask())
		{
			this->taskobjects.push_back(d);
		}
	}
	addTaskObjects.clear();
}
void EngineSystem::TaskKillCheck()
{
	//�폜�\��̃^�X�N���폜����
	auto id = this->taskobjects.begin();
	while (id != this->taskobjects.end())
	{
		if (id->second)
		{
			if (id->second->GetKillCount() > 0)
			{
				this->taskobjects.erase(id);
				this->TaskApplication();
				id = this->taskobjects.begin();
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
	return this->addTaskObjects.size() > 0;
}
bool EngineSystem::CheckKillTask()
{
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		if (taskobjects[i].second->GetKillCount() > 0)
		{
			return true;
		}
	}
	return false;
}
void EngineSystem::AllTaskDelete()
{
	//�S�폜
	auto id = this->taskobjects.begin();
	while (id != this->taskobjects.end())
	{
		this->taskobjects.erase(id);
		id = this->taskobjects.begin();
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
	this->DeleteEngine = flag;
}
bool EngineSystem::GetDeleteEngine()
{
	//�G���W���I����Ԃ�
	return this->DeleteEngine;
}
EngineSystem* OGge;
ResourceManager* rm;