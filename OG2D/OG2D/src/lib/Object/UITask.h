#pragma once
#include "OG\_OGsystem.h"
/**
*namespace UO
*@brief	UIObject�Ɋւ���f�[�^
*/
namespace UO
{
	/**
	*enum class Mode
	*@brief	��Ԃ̐ݒ�
	*/
	enum class Mode
	{
		//! �ʏ폈��
		NORMAL,
		//! �|�[�Y�p����
		PAUSE,
		//! �X�V��~
		STOP,
		//! �`��X�V���ɒ�~
		ALLSTOP,
		//! �폜
		KILL,
	};
}
/**
*@brief	UI�\���̂��߂̃I�u�W�F�N�g
*
*�X�V�ƕ`��݂̂��s����
*/
class UIObject
{
	//! Position
	Vec2 _position;
	//! Scale
	Vec2 _scale;
	//! Angle
	float _angle;
	//! TaskTag
	std::string _tag;
	//! Mode
	UO::Mode _mode;
	//! �`�揇
	unsigned int _order;
	/**
	*@brief	�l�̃��Z�b�g
	*/
	void ResetData();
public:
	/**
	*@brief	constructor
	*/
	explicit UIObject();
	/**
	*@brief	constructor
	*@param[in]	string& tag TaskName
	*@param[in]	const Vec2& pos Position
	*@param[in]	const Vec2& scale Scale
	*@param[in]	float angle Angle
	*/
	explicit UIObject(
		const std::string& tag, 
		const Vec2& pos,
		const Vec2& scale, 
		const float angle = 0.f);
	/**
	*@brief[in]	destructor
	*/
	virtual ~UIObject();
	/**
	*@brief	Initialize
	*@param[in]	string& tag TaskName
	*@param[in]	const Vec2& pos Position
	*@param[in]	const Vec2& scale Scale
	*@param[in]	float angle Angle
	*/
	void Init(
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.f);
	/**
	*@brief	�X�V����
	*/
	virtual void Update();
	/**
	*@brief	��~����
	*/
	virtual void Pause();
	/**
	*@brief	�`�揈��
	*/
	virtual void Render2D();
	/**
	*@brief	�X�V�Ǘ�
	*/
	void UpdateManager();
	/**
	*@brief	�`��Ǘ�
	*/
	void RenderManager();
	/**
	*@brief	�ʒu�ݒ�
	*@param[in]	Vec2 pos �ʒu
	*/
	void SetPosition(const Vec2& pos);
	/**
	*@brief	�ʒu�ݒ�
	*@param[in]	float x �ʒuX���W
	*@param[in]	float y �ʒuY���W
	*/
	void SetPosition(const float x, const float y);
	/**
	*@brief	�ʒu���擾
	*@return Vec2 Position
	*/
	Vec2 GetPosition();
	/**
	*@brief	�g�k�ݒ�
	*@param[in]	Vec2 scale �g�k
	*/
	void SetScale(const Vec2& scale);
	/**
	*@brief	�g�k�ݒ�
	*@param[in]	float x �g�kX
	*@param[in]	float y �g�kY
	*/
	void SetScale(const float x, const float y);
	/**
	*@brief	�g�k���擾
	*@return Vec2 Scale
	*/
	Vec2 GetScale() const;
	/**
	*@brief	��]�ݒ�
	*@param[in]	float angle ��]�p�x
	*/
	void SetRotate(const float angle);
	/**
	*@brief	��]���擾
	*@return float angle
	*/
	float GetRotate() const;
	/**
	*@brief	�^�O�ݒ�
	*@param[in]	string name tagname
	*/
	void SetTag(const std::string& name);
	/**
	*@brief	�^�O���擾
	*@return string objecttag
	*/
	std::string GetTag() const;
	/**
	*@brief	�I�u�W�F�N�g���폜����
	*/
	void Kill();
	/**
	*@brief	�폜���߂��L�����Z������
	*/
	void CancelKill();
	/**
	*@brief	Pause�ݒ�
	*@param[in]	bool flag true��Pause��
	*/
	void SetPause(const bool flag = true);
	/**
	*@brief	��~�ݒ�
	*@param[in]	bool flag true�Œ�~
	*/
	void SetStop(const bool flag = true);
	/**
	*@brief	�S�@�\��~
	*@param[in]	bool flag true�őS��~
	*/
	void SetAllStop(const bool flag = true);
	/**
	*@brief	����̏�Ԃ�Ԃ�
	*@return Mode ���
	*/
	UO::Mode GetMode() const;
	/**
	*@brief	���[�h�m�F
	*@parma[in]	Mode mode ��r�Ώ�
	*@return bool ��r�ΏۂƓ����Ȃ�true
	*/
	bool ModeCheck(const UO::Mode& mode) const;
	/**
	*@brief	�`�揇�w��
	*���������O�ɕ`�悳���
	*@param[in] unsigned int order �`�揇�l
	*/
	void SetDrawOrder(const unsigned int order);
	/**
	*@brief	�`�揇���擾
	*@return unsigned int �`�揇
	*/
	unsigned int GetDrawOrder() const;
};