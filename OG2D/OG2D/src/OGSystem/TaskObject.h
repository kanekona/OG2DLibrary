#pragma once
#include "_OGsystem.h"

class TaskObject
{
public:
	typedef std::shared_ptr<TaskObject> SP;	//�X�}�[�g�|�C���^
	typedef std::weak_ptr<TaskObject> WP;	//�T�u�I�[�o�[
	WP me;									//�����̏��
private:
	bool NextTask;							//�I�����Ɏ��̃^�X�N�𐶐��ł��邩
	int KillCount;							//�폜���邩�ǂ����̔��f�p
	std::string taskName;					//�^�X�N�ɖ�������
	float order;							//�`�揇��
	bool isPause;							//�Ă΂��X�V����
public:
	TaskObject();
	bool Init(const std::string&);			//����������
	void T_UpDate();						//�X�V����
	void T_Render();						//�`�揈��
	void T_Pause();							//��~����
	virtual void UpDate();					//�q�B�̍X�V����
	virtual void Render2D();				//�q�B�̕`�揈��
	virtual void PauseUpDate();				//�q�B�̒�~����
	void Kill(const bool = true);			//�폜����
	int GetKillCount();						//�폜�󋵂�Ԃ�
	bool GetNextTask();						//���̃^�X�N�����邩�ǂ�����Ԃ�
	void ResetKillCount();					//�폜�󋵂����Z�b�g����
	void SetDrawOrder(const float);			//�`�揇��o�^����
	float GetDrawOrder() const;				//�`�揇��Ԃ�
	std::string GetTaskName() const;		//�^�X�N����Ԃ�
	bool GetPause() const;
	void SetPause(const bool);
private:
};