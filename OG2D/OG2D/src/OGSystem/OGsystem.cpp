#include "OGsystem.h"
//--------------------------------------------------
//@:GameEngineclass									
//--------------------------------------------------
EngineSystem::EngineSystem()
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
EngineSystem::EngineSystem(int widht, int height, char* name, bool screen)
{
	this->w_he = widht;
	this->w_he = height;
	this->w_na = name;
	this->w_sc = screen;
}
void EngineSystem::Initialize()
{
	//����������
	//�J����2D�̐���
	this->camera = Camera2D::Create(Box2D(0, 0, 960, 540));
	//Window�̐���
	this->window = Window::Create(w_wi, w_he, w_na, w_sc, w_pos);
	//Window�ݒ�
	this->window->LimitsWindow();
	this->window->InMouseMode(this->Cursor_on);
	this->window->setIcon(this->path + this->file);
	//fps�̐ݒ�
	//���f�o�b�O���̂ݎg�p����
#if(_DEBUG)
	this->fps = FPS::Create();
#endif
	//���͊֘A�̏�����
	this->in.Inputinit(this->window->window);
	//�T�E���h�Ǘ��̏�����
	this->soundManager = SoundManager::Create();
	//�I�[�f�B�I�f�o�C�X�̏������Ɛݒ�
	this->audiodevice = Audio::Create();
	//�e�l�̏�����
	DebugFunction = false;
	this->isPause = false;
	this->end = false;
}
void EngineSystem::SetWindow(int width, int height, char* name, bool screen)
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
void EngineSystem::SetIcon(std::string filepath_)
{
	//�A�C�R���Ɏg�p����摜�̐ݒ�
	this->file = filepath_;
}
void EngineSystem::Update()
{
	//�J�����Ɠ��͏󋵂̍X�V
	this->camera->CameraUpdate();
	this->in.upDate();
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
			this->taskobjects[id].second->T_UpDate();
		}
	}
}
void EngineSystem::Task_Render_AF()
{
	//�o�^�^�X�N�̕`�揈�����Ă�
	for (int id = 0; id < this->taskobjects.size(); ++id)
	{
		if (this->taskobjects[id].second->GetKillCount() == 0) 
		{
			this->taskobjects[id].second->Draw2D();
		}
	}
}
void EngineSystem::TaskGameUpDate()
{
	this->Task_UpDate();		//�X�V����
	this->Task_Render_AF();		//�`�揈��
	this->TaskApplication();	//�o�^�\��̃^�X�N��o�^����
	this->TaskKillCheck();		//�폜�\��̃^�X�N���폜����
}
EngineSystem::~EngineSystem()
{
	//�o�^���Ă���^�X�N�����ׂĔj������
	this->AllTaskDelete();
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
	this->camera->SetSize(Vec2(this->window->_widht, this->window->_height));
	this->SetPause(false);
	this->soundManager->AllDelete();
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
void EngineSystem::KillTask(const TaskObject::SP& To)
{
	//�폜�\��̃^�X�N���폜����
	for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
	{
		if (id->second == To)
		{
			this->taskobjects.erase(id);
		}
	}
}
void EngineSystem::TaskKillCheck()
{
	//�폜�\��̃^�X�N���폜����
	auto id = this->taskobjects.begin();
	while (id != this->taskobjects.end())
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
}
void EngineSystem::AllTaskDelete()
{
	//�S�폜
	this->taskobjects.clear();
}
void EngineSystem::SetWindowPos(Vec2& pos)
{
	//Window�̈ʒu��Ԃ�
	this->w_pos = pos;
}
void EngineSystem::SetDeleteEngine(bool flag)
{
	//�G���W���̏I����o�^
	this->DeleteEngine = flag;
}
bool EngineSystem::GetDeleteEngine()
{
	//�G���W���I����Ԃ�
	return this->DeleteEngine;
}
//template <class T> std::shared_ptr<T> EngineSystem::GetTask(const std::string& taskName)
//{
//	for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
//	{
//		if ((*id).second->taskName == taskName)
//		{
//			return std::static_pointer_cast<T>((*id).second);
//		}
//	}
//	return nullptr;
//}
EngineSystem* OGge;