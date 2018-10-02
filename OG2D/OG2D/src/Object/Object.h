#pragma once
//_____________________________
//|�Q�[���I�u�W�F�N�g            
//|�����F2018/03/20   
//|____________________________
#include "OGSystem\_OGsystem.h"
#include "OGSystem\Collision\Collision.h"
/**
*enum Objform
*�I�u�W�F�N�g�̌`�̐ݒ�
*/
enum Objform
{
	//! ��
	Non,
	//!	�~
	Ball,
	//! ��`
	Cube,
	//! �_
	Pointer,
	//! ��
	Line,
};
/**
*enum Mode
*��Ԃ̐ݒ�
*/
namespace GO
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
	Collision* _collision;
	CollisionBase* base;
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
	*@brief	:�f�[�^�^�̒l�̃��Z�b�g
	*/
	void ResetData();
	/**
	*@brief	:Collision�̐���
	*���݂�form�󋵂ɉ�����Collision�𐶐�����
	*/
	void CreateCollision();
public:
	/**
	*@brief	:constructor
	*/
	explicit GameObject();
	/**
	*@brief	:constructor
	*@param	:Objform form �I�u�W�F�N�g�̏��
	*@param	:string tag �I�u�W�F�N�g�^�O��
	*@param	:Vec2 pos �ʒu
	*@param	:Vec2 scale �g�k
	*@param :float angle ��]�l
	*/
	explicit GameObject(
		const Objform& form,
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.0f);
	/**
	*@brief	:destructor
	*/
	virtual ~GameObject();
	/**
	*@brief	:�I�u�W�F�N�g������
	*@param	:Objform form �I�u�W�F�N�g�̏��
	*@param	:string tag �I�u�W�F�N�g�^�O��
	*@param	:Vec2 pos �ʒu
	*@param	:Vec2 scale �g�k
	*@param :float angle ��]�l
	*/
	void Init(
		const Objform& form,
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.0f);
	/**
	*@brief	:�����蔻��
	*@param	:GameObjet* object ����̃I�u�W�F�N�g
	*@return:bool hit true
	*/
	bool Hit(GameObject* object);
	/**
	*@brief	:�����蔻��
	*@param	:CollisionBase* object ����̃I�u�W�F�N�g
	*@return:bool hit true
	*/
	bool Hit(CollisionBase* object);
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
	*@brief	:�����蔻��m�F
	*@param	:float lineWidth Line�̑���
	*/
	void LineDraw(const float lineWidth = 1.0f);
	/**
	*@brief	:��܂��Ȕ͈͂̔����Ԃ�
	*@param	:GameObject* object ����̃I�u�W�F�N�g
	*@return:bool ������ł����true
	*/
	bool IsObjectDistanceCheck(GameObject* object);
	/**
	*@brief	:��܂��Ȕ͈͂̔����Ԃ�
	*@param	:CollisionCircle* object ����̃I�u�W�F�N�g
	*@return:bool ������ł����true
	*/
	bool IsObjectDistanceCheck(CollisionCircle* object);
	/**
	*@brief	:�傫�Ȕ���͈͂�\������
	*@param	:float lineWidth Line�̑���
	*/
	void LineDistanceDraw(const float lineWidth = 1.0f);
	/**
	*@brief	:�����蔻��ݒ�
	*@param	:bool flag ����L��
	*/
	void CollisionConfig(const bool flag);
	/**
	*@brief	:�����蔻��ݒ�̊m�F
	*@return:bool ����L��
	*/
	bool IsCollision() const;
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
	*@brief	:����{��
	*@param :Vec2 radius �{��
	*/
	void SetRadius(const Vec2& radius);
	/**
	*@brief	:����{��
	*@param :float x x���W�{��
	*@param	:float y y���W�{��
	*/
	void SetRadius(const float x, const float y);
	/**
	*@brief	:����{�����擾
	*@return:Vec2 radius
	*/
	Vec2 GetRadius() const;
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
	*@brief	:���ʐݒ�
	*@param	:float mass ����
	*/
	void SetMass(const float mass);
	/**
	*@brief	:���ʏ��擾
	*@return:float mass
	*/
	float GetMass() const;
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
	GO::Mode GetMode() const;
	/**
	*@brief	:���[�h�m�F
	*@parma	:Mode mode ��r�Ώ�
	*@return:bool ��r�ΏۂƓ����Ȃ�true
	*/
	bool ModeCheck(const GO::Mode& mode) const;
	/**
	*@brief	:���݂�form��Ԃ�
	*@return:Objform ���݂�form
	*/
	Objform Getform() const;
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

/**
*enum Objform
*�I�u�W�F�N�g�̌`
*/
//enum Objform
//{
//	//! ��
//	Non,
//	//!	�~
//	Ball,
//	//! ��`
//	Cube,
//	//! �_
//	Pointer,
//	//! ��
//	Line,
//};
/**
*@brief	:�Q�[���Ŏg�p����I�u�W�F�N�g�pclass
*/
//class GameObject : public TaskObject
//{
//	//! �����蔻����s���L��
//	bool isCheck;
//public:
//	//! �I�u�W�F�N�g�̏��
//	Objform objform;
//	//! �ʒu
//	Vec2 position;
//	//! �T�C�Y
//	Vec2 Scale;
//	//! ���a
//	Vec2 Radius;
//	//! ��]�x
//	float angle;
//	//! ��`�����蔻��
//	CollisionBox collisionCube;
//	//! �~�����蔻��
//	CollisionCircle collisionBall;
//	//! �d�̗͂L��
//	bool isGravity;
//	//! ����
//	float mass;
//	//! �I�u�W�F�N�g�̃^�O��
//	std::string objectTag;
//	/**
//	*@brief	:GameObject���m�̓����蔻��
//	*@param	:GameObject o ����̃I�u�W�F�N�g
//	*@return:bool �������Ă����true
//	*/
//	bool hit(GameObject& o);
//	/**
//	*@fn
//	*��]���s��Ȃ������蔻��
//	*@brief	:��`Object���m�̊ȈՓ����蔻��
//	*@param	:GameObject o ����̃I�u�W�F�N�g
//	*@return:bool �������Ă����true
//	*/
//	bool CubeHit(GameObject& o);
//	/**
//	*@brief	:constructor
//	*/
//	GameObject();
//	/**
//	*@brief	:constructor
//	*@param	:Objform form �I�u�W�F�N�g�̌`
//	*@param	:Vec2 _posi �ʒu
//	*@param	:Vec2 _Sca �傫��
//	*@param	:float _ang	��]�l
//	*/
//	GameObject(
//		const Objform& form, 
//		const Vec2& _posi, 
//		const Vec2& _Sca, 
//		float _ang = 0.0f
//	);
//	/**
//	*@brief	:destructor
//	*/
//	~GameObject();
//	/**
//	*@brief	:�I�u�W�F�N�g�̏���o�^����
//	*@param	:Objform form �I�u�W�F�N�g�̌`
//	*@param	:Vec2 _posi �ʒu
//	*@param	:Vec2 _Sca �傫��
//	*@param	:float _ang	��]�l
//	*/
//	void CreateObject(
//		const Objform& form,
//		const Vec2& _posi,
//		const Vec2& _Sca,
//		const float _ang = 0.0f
//	);
//	/**
//	*@brief	:�����蔻��ɐ�������
//	*/
//	void LineDraw();
//	/**
//	*@brief	:�����蔻���t����
//	*@param	:bool flag �����蔻����s���ݒ�
//	*/
//	void HitCheck(bool flag = true);
//	/**
//	*@brief	:�����蔻����s���͈͂���Ԃ�
//	*@param	:Vec2 pos ����̈ʒu
//	*@param	:Vec2 size ����̑傫��
//	*@return:bool ������ł����true
//	*/
//	bool IsObjectDistanceCheck(const Vec2& pos, const Vec2& size);
//	/**
//	*@brief	:�傫�Ȕ���͈͂�\������
//	*/
//	void LineDistanceDraw();
//	/**
//	*@brief	:�����ݒ�ړ�����(������)
//	*/
//	virtual void Move();
//	/**
//	*@brief	:�����ݒ�d�͏���(������)
//	*/
//	virtual void Friction();
//private:
//};