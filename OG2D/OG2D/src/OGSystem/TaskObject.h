#pragma once
#include "_OGsystem.h"
/**
*namespace ST
*@brief	SceneTask�Ɋւ���f�[�^
*/
namespace ST
{
	/**
	*enum Mode
	*��Ԃ̐ݒ�
	*/
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
*@brief	Scene������class
*�X�V�����݂̂������Ă���
*�j�����ɑS�I�u�W�F�N�g�̍폜�����������Ă���
*/
class SceneTask : private NonCopyable
{
	//! �I�����Ɏ��̃^�X�N�𐶐��ł��邩
	bool NextTask;
	//! �^�X�N�ɖ�������
	std::string taskName;
	//! ��ԊǗ�
	ST::Mode _mode;
	//! �I������GameObject��j�����邩
	bool enableDestroyAllObjectWhenExitng;
public:
	/**
	*@brief	constructor
	*/
	explicit SceneTask();
	/**
	*@brief	destructor
	*/
	virtual ~SceneTask();
	/**
	*@brief	����������
	*@param[in]	string name �^�X�N��
	*@return bool ������true
	*/
	bool Init(const std::string& name);
	/**
	*@brief	�X�V����
	*/
	void UpdateManager();
	/**
	*@brief	�X�V����
	*/
	virtual void Update();
	/**
	*@brief	�|�[�Y����
	*/
	virtual void Pause();
	/**
	*@brief	�폜����
	*@param[in] bool flag ���^�X�N�̐������s�����̐ݒ�
	*/
	void Kill(const bool flag = true);
	/**
	*@brief	���^�X�N�̐����̋���Ԃ�
	*@return bool ��������
	*/
	bool GetNextTask() const;
	/**
	*@brief	�o�^����Ă���^�X�N����Ԃ�
	*@return string �^�X�N��
	*/
	std::string GetTaskName() const;
	/**
	*@brief	�|�[�Y�ݒ���s��
	*@param[in]	bool flag �|�[�Y�ݒ�
	*/
	void SetPause(const bool flag = true);
	/**
	*@brief	��~�������s��
	*@param[in]	bool flag ��~�����ݒ�
	*/
	void SetStop(const bool flag = true);
	/**
	*@brief	����̏�Ԃ�Ԃ�
	*@return Mode ���
	*/
	ST::Mode GetMode() const;
	/**
	*@brief	���[�h�m�F
	*@parma[in]	Mode mode ��r�Ώ�
	*@return bool ��r�ΏۂƓ����Ȃ�true
	*/
	bool ModeCheck(const ST::Mode& mode) const;
	/**
	*@brief	�I������GameObject���폜������ݒ�
	*@param[in]	bool flag true�Ȃ�폜������
	*/
	void EnableGameObjectDestroy(const bool flag);
	/**
	*@brief	������GameObject���폜������ݒ���擾
	*@return bool true�Ȃ�폜������
	*/
	bool GetAllObjectDestroy() const;
};