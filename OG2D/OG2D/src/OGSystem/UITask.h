#pragma once
#include "_OGsystem.h"
/**
*enum Mode
*��Ԃ̐ݒ�
*/
namespace UT
{
	enum Mode
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
	UT::Mode _mode;
	//! �`�揇
	unsigned int _order;
	/**
	*@brief	:�l�̃��Z�b�g
	*/
	void ResetData();
public:
	/**
	*@brief	:constructor
	*/
	explicit UIObject();
	/**
	*@brief	:constructor
	*@param	:string& tag TaskName
	*@param	:const Vec2& pos Position
	*@param	:const Vec2& scale Scale
	*@param	:float angle Angle
	*/
	explicit UIObject(
		const std::string& tag, 
		const Vec2& pos,
		const Vec2& scale, 
		const float angle = 0.f);
	/**
	*@brief	:destructor
	*/
	virtual ~UIObject();
	/**
	*@brief	:Initialize
	*@param	:string& tag TaskName
	*@param	:const Vec2& pos Position
	*@param	:const Vec2& scale Scale
	*@param	:float angle Angle
	*/
	void Init(
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.f);
	/**
	*@brief	:�X�V����
	*/
	virtual void Update();
	/**
	*@brief	:��~����
	*/
	virtual void Pause();
	/**
	*@brief	:�`�揈��
	*/
	virtual void Render2D();
	/**
	*@brief	:�X�V�Ǘ�
	*/
	void UpdateManager();
	/**
	*@brief	:�`��Ǘ�
	*/
	void RenderManager();
	/**
	*@brief	:�ʒu�ݒ�
	*@param	:Vec2 pos �ʒu
	*/
	void SetPosition(const Vec2& pos);
	/**
	*@brief	:�ʒu�ݒ�
	*@param	:float x �ʒuX���W
	*@param	:float y �ʒuY���W
	*/
	void SetPosition(const float x, const float y);
	/**
	*@brief	:�ʒu���擾
	*@return:Vec2 Position
	*/
	Vec2 GetPosition() const;
	/**
	*@brief	:�g�k�ݒ�
	*@param	:Vec2 scale �g�k
	*/
	void SetScale(const Vec2& scale);
	/**
	*@brief	:�g�k�ݒ�
	*@param	:float x �g�kX
	*@param	:float y �g�kY
	*/
	void SetScale(const float x, const float y);
	/**
	*@brief	:�g�k���擾
	*@return:Vec2 Scale
	*/
	Vec2 GetScale() const;
	/**
	*@brief	:��]�ݒ�
	*@param	:float angle ��]�p�x
	*/
	void SetRotate(const float angle);
	/**
	*@brief	:��]���擾
	*@return:float angle
	*/
	float GetRotate() const;
	/**
	*@brief	:�^�O�ݒ�
	*@param	:string name tagname
	*/
	void SetTag(const std::string& name);
	/**
	*@brief	:�^�O���擾
	*@return:string objecttag
	*/
	std::string GetTag() const;
	/**
	*@brief	:�I�u�W�F�N�g���폜����
	*/
	void Kill();
	/**
	*@brief	:�폜���߂��L�����Z������
	*/
	void CancelKill();
	/**
	*@brief	:Pause�ݒ�
	*@param	:bool flag true��Pause��
	*/
	void SetPause(const bool flag = true);
	/**
	*@brief	:��~�ݒ�
	*@param	:bool flag true�Œ�~
	*/
	void SetStop(const bool flag = true);
	/**
	*@brief	:�S�@�\��~
	*@param	:bool flag true�őS��~
	*/
	void SetAllStop(const bool flag = true);
	/**
	*@brief	:����̏�Ԃ�Ԃ�
	*@return:Mode ���
	*/
	UT::Mode GetMode() const;
	/**
	*@brief	:���[�h�m�F
	*@parma	:Mode mode ��r�Ώ�
	*@return:bool ��r�ΏۂƓ����Ȃ�true
	*/
	bool ModeCheck(const UT::Mode& mode) const;
	/**
	*@brief	:�`�揇�w��
	*@param :unsigned int order �`�揇�l
	*���������O�ɕ`�悳���
	*/
	void SetDrawOrder(const unsigned int order);
	/**
	*@brief	:�`�揇���擾
	*/
	unsigned int GetDrawOrder() const;
};