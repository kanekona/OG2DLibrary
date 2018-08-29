#pragma once
#include "_OGsystem.h"
///KillCount 0 : �ʏ�X�V
///			 1~: �I���\��
///			 -1: �X�V��~
/**
*TaskObject
*/
class TaskObject
{
private:
	//! �I�����Ɏ��̃^�X�N�𐶐��ł��邩
	bool NextTask;
	//! �폜���邩�ǂ����̔��f�p
	int KillCount;
	//! �^�X�N�ɖ�������
	std::string taskName;
	//! �`�揇��
	float order;
	//! �Ă΂��X�V����
	bool isPause;
public:
	//! �q�I�u�W�F�N�g�̏��
	std::vector<TaskObject*> Child;
	/**
	*@brief	:constructor
	*/
	TaskObject();
	/**
	*@brief	:destructor
	*/
	virtual ~TaskObject();
	/**
	*@brief	:����������
	*@param	:string name �^�X�N��
	*@return:bool ������true
	*/
	bool Init(const std::string& name);
	/**
	*@brief	:�X�V����
	*/
	void T_UpDate();
	/**
	*@brief	:�X�V����
	*/
	virtual void UpDate();
	/**
	*@brief	:�`�揈��
	*/
	virtual void Render2D();
	/**
	*@brief	:�|�[�Y����
	*/
	virtual void PauseUpDate();
	/**
	*@brief	:�폜����
	*@param :bool flag ���^�X�N�̐������s�����̐ݒ�
	*/
	void Kill(const bool flag = true);
	/**
	*@brief	:�폜�󋵂�Ԃ�
	*@return:int �폜�J�E���g
	*/
	int GetKillCount() const;
	/**
	*@brief	:���^�X�N�̐����̋���Ԃ�
	*@return:bool ��������
	*/
	bool GetNextTask() const;
	/**
	*@brief	:�L���J�E���g�����Z�b�g����
	*/
	void ResetKillCount();
	/**
	*@brief	:�`�揇���w�肷��
	*@param	:float order �`�揇
	*/
	void SetDrawOrder(const float order);
	/**
	*@brief	:�`�揇��Ԃ�
	*@return:�`�揇
	*/
	float GetDrawOrder() const;
	/**
	*@brief	:�o�^����Ă���^�X�N����Ԃ�
	*@return:string �^�X�N��
	*/
	std::string GetTaskName() const;
	/**
	*@brief	:�|�[�Y������Ԃ�
	*@return:bool �^�X�N�̏��
	*/
	bool GetPause() const;
	/**
	*@brief	:�|�[�Y�ݒ���s��
	*@param	:bool flag �|�[�Y�ݒ�
	*/
	void SetPause(const bool flag);
	/**
	*@brief	:��~�������s��
	*@param	:bool flag ��~�����ݒ�
	*/
	void Stop(const bool flag = true);
	/**
	*@brief	:��~�����ݒ��Ԃ�
	*@return:bool ��~�ݒ�
	*/
	bool GetIsStop() const;
private:
};