#pragma once
#include "OGSystem\Collision\Collision.h"
/**
*enum Objform
*@brief	�I�u�W�F�N�g�̌`�̐ݒ�
*/
enum Objform
{
	//! ��
	Non,
	//!	�~
	Circle,
	//! ��`
	Box,
	//! �_
	Pointer,
	//! ��
	Line,
};
/**
*namespace	GO
*@brief	GameObject�Ɋւ���f�[�^
*/
namespace GO
{
	/**
	*enum Mode
	*@brief	��Ԃ̐ݒ�
	*/
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
/**
*@brief	GameObject
*�����蔻���X�V�A�`�揈�����s�����Ƃ��o����
*/
class GameObject :private NonCopyable
{
	//! Position
	Vec2 _position;
	//! Scale
	Vec2 _scale;
	//! DistanceScale
	Vec2 _distanceScale;
	//! Radius
	Vec2 _radius;
	//! Angle
	float _angle;
	//! CollisionData
	CollisionBase* _collision;
	//! ObjectTag
	std::string _tag;
	//! Mass
	float _mass;
	//! DistanceCollision
	CollisionCircle* _distanceCollision;
	//! isCollisionCheck
	bool enableCollision;
	//! Mode
	GO::Mode _mode;
	//! ObjectForm
	Objform _form;
	//! �`�揇
	/*?unsigned int�̃o�C�g���K�v���ǂ����^��ł͂���*/
	unsigned int _order;
	/**
	*@brief	�f�[�^�^�̒l�̃��Z�b�g
	*/
	void ResetData();
	/**
	*@brief	Collision�̐���
	*���݂�form�󋵂ɉ�����Collision�𐶐�����
	*/
	void CreateCollision();
public:
	/**
	*@brief	constructor
	*/
	explicit GameObject();
	/**
	*@brief constructor
	*@param[in]	Objform form �I�u�W�F�N�g�̏��
	*@param[in]	string tag �I�u�W�F�N�g�^�O��
	*@param[in]	Vec2 pos �ʒu
	*@param[in]	Vec2 scale �g�k
	*@param[in] float angle ��]�l
	*/
	explicit GameObject(
		const Objform& form,
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.0f);
	/**
	*@brief	destructor
	*/
	virtual ~GameObject();
	/**
	*@brief	�I�u�W�F�N�g������
	*@param[in]	Objform form �I�u�W�F�N�g�̏��
	*@param[in]	string tag �I�u�W�F�N�g�^�O��
	*@param[in]	Vec2 pos �ʒu
	*@param[in]	Vec2 scale �g�k
	*@param[in] float angle ��]�l
	*/
	void Init(
		const Objform& form,
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.0f);
	/**
	*@brief	�����蔻��
	*@param[in]	GameObjet* object ����̃I�u�W�F�N�g
	*@return bool hit true
	*/
	bool Hit(GameObject* object);
	/**
	*@brief	�����蔻��
	*@param[in]	CollisionBase* object ����̃I�u�W�F�N�g
	*@return bool hit true
	*/
	bool Hit(CollisionBase* object);
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
	*@brief	�����蔻��m�F
	*@param[in]	float lineWidth Line�̑���
	*/
	void LineDraw(const float lineWidth = 1.0f);
	/**
	*@brief	��܂��Ȕ͈͂̔����Ԃ�
	*@param[in]	GameObject* object ����̃I�u�W�F�N�g
	*@return bool ������ł����true
	*/
	bool IsObjectDistanceCheck(GameObject* object);
	/**
	*@brief	��܂��Ȕ͈͂̔����Ԃ�
	*@param[in]	CollisionCircle* object ����̃I�u�W�F�N�g
	*@return bool ������ł����true
	*/
	bool IsObjectDistanceCheck(CollisionCircle* object);
	/**
	*@brief	�傫�Ȕ���͈͂�\������
	*@param[in]	float lineWidth Line�̑���
	*/
	void LineDistanceDraw(const float lineWidth = 1.0f);
	/**
	*@brief	�����蔻��ݒ�
	*@param[in]	bool flag ����L��
	*/
	void CollisionConfig(const bool flag);
	/**
	*@brief	�����蔻��ݒ�̊m�F
	*@return bool ����L��
	*/
	bool IsCollision() const;
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
	Vec2 GetPosition() const;
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
	*@brief	 ��]�ݒ�
	*@param[in] float angle ��]�p�x
	*/
	void SetRotate(const float angle);
	/**
	*@brief	��]���擾
	*@return float angle
	*/
	float GetRotate() const;
	/**
	*@brief	����{��
	*@param[in] Vec2 radius �{��
	*/
	void SetRadius(const Vec2& radius);
	/**
	*@brief	����{��
	*@param[in] float x x���W�{��
	*@param[in]	float y y���W�{��
	*/
	void SetRadius(const float x, const float y);
	/**
	*@brief	����{�����擾
	*@return[in] Vec2 radius
	*/
	Vec2 GetRadius() const;
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
	*@brief	���ʐݒ�
	*@param[in]	float mass ����
	*/
	void SetMass(const float mass);
	/**
	*@brief	���ʏ��擾
	*@return float mass
	*/
	float GetMass() const;
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
	GO::Mode GetMode() const;
	/**
	*@brief	���[�h�m�F
	*@parma[in]	Mode mode ��r�Ώ�
	*@return bool ��r�ΏۂƓ����Ȃ�true
	*/
	bool ModeCheck(const GO::Mode& mode) const;
	/**
	*@brief	���݂�form��Ԃ�
	*@return Objform ���݂�form
	*/
	Objform Getform() const;
	/**
	*@brief	�`�揇�w��
	*���������O�ɕ`�悳���
	*@param[in] unsigned int order �`�揇�l
	*/
	void SetDrawOrder(const unsigned int order);
	/**
	*@brief	�`�揇���擾
	*/
	unsigned int GetDrawOrder() const;
};