#pragma once
#include "_OGsystem.h"

class TaskObject
{
public:
	typedef std::shared_ptr<TaskObject> SP;	//�X�}�[�g�|�C���^
	typedef std::weak_ptr<TaskObject> WP;	//�T�u�I�[�o�[
	WP me;									//�����̏��
	std::string taskName;					//�^�X�N�ɖ�������
private:
	bool NextTask;							//�I�����Ɏ��̃^�X�N�𐶐��ł��邩
	int KillCount;							//�폜���邩�ǂ����̔��f�p
public:
	bool Init(std::string&);				//����������
	void T_UpDate();						//�X�V����
	void Draw2D();							//�`�揈��
	void Delete();							//�폜����
	virtual void UpDate() = 0;				//�q�B�̍X�V����
	virtual void Render2D() = 0;			//�q�B�̕`�揈��
	virtual bool Finalize() = 0;			//�q�B�̉������
	void Kill(bool = true);					//�폜����
	int GetKillCount();						//�폜�󋵂�Ԃ�
	bool GetNextTask();						//���̃^�X�N�����邩�ǂ�����Ԃ�
	void ResetKillCount();					//�폜�󋵂����Z�b�g����
private:
};