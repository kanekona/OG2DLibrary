#pragma once
#include "_OGsystem.h"
///KillCount 0 : �ʏ�X�V
///			 1~: �I���\��
///			 -1: �X�V��~
/**
*enum Mode
*��Ԃ̐ݒ�
*/
namespace Scene
{
	enum Mode
	{
		//! �ʏ폈��
		NORMAL,
		//! �|�[�Y�p����
		PAUSE,
		//! �X�V��~
		STOP,
		//! �폜
		KILL,
	};
}
/**
*TaskObject
*/
class SceneTask : private NonCopyable
{
private:
	//! �I�����Ɏ��̃^�X�N�𐶐��ł��邩
	bool NextTask;
	//! �^�X�N�ɖ�������
	std::string taskName;
	//! ��ԊǗ�
	Scene::Mode _mode;
	//! �I������GameObject��j�����邩
	bool enableDestroyGameObjectWhenExitng;
public:
	/**
	*@brief	:constructor
	*/
	explicit SceneTask();
	/**
	*@brief	:destructor
	*/
	virtual ~SceneTask();
	/**
	*@brief	:����������
	*@param	:string name �^�X�N��
	*@return:bool ������true
	*/
	bool Init(const std::string& name);
	/**
	*@brief	:�X�V����
	*/
	void UpdateManager();
	/**
	*@brief	:�X�V����
	*/
	virtual void Update();
	/**
	*@brief	:�|�[�Y����
	*/
	virtual void Pause();
	/**
	*@brief	:�폜����
	*@param :bool flag ���^�X�N�̐������s�����̐ݒ�
	*/
	void Kill(const bool flag = true);
	/**
	*@brief	:���^�X�N�̐����̋���Ԃ�
	*@return:bool ��������
	*/
	bool GetNextTask() const;
	/**
	*@brief	:�o�^����Ă���^�X�N����Ԃ�
	*@return:string �^�X�N��
	*/
	std::string GetTaskName() const;
	/**
	*@brief	:�|�[�Y�ݒ���s��
	*@param	:bool flag �|�[�Y�ݒ�
	*/
	void SetPause(const bool flag = true);
	/**
	*@brief	:��~�������s��
	*@param	:bool flag ��~�����ݒ�
	*/
	void SetStop(const bool flag = true);
	/**
	*@brief	:����̏�Ԃ�Ԃ�
	*@return:Mode ���
	*/
	Scene::Mode GetMode() const;
	/**
	*@brief	:���[�h�m�F
	*@parma	:Mode mode ��r�Ώ�
	*@return:bool ��r�ΏۂƓ����Ȃ�true
	*/
	bool ModeCheck(const Scene::Mode& mode) const;
	/**
	*@brief	:�I������GameObject���폜������ݒ�
	*@param	:bool flag true�Ȃ�폜������
	*/
	void EnableGameObjectDestroy(const bool flag);
	/**
	*@brief	:�I������GameObject���폜������ݒ���擾
	*@return:bool true�Ȃ�폜������
	*/
	bool GetGameObjectDestroy() const;
};