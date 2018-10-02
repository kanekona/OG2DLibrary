/**
*Box2D,Circle���g�p�������蔻����s��class
*/
#pragma once
#include "OGSystem\_OGsystem.h"
/**
*@brief	:����̌�
*/
class CollisionBase;
/**
*@brief	:��`����
*/
class CollisionBox;
/**
*@brief	:�~����
*/
class CollisionCircle;
/**
*@brief	:�_����
*/
class CollisionPointer;
/**
*@brief	:������
*/
class CollisionLine;
/**
*@brief	:�J�v�Z������
*! ������
*/
class CollisionCapsule;
/**
*@brief	:�ėp�^����
*/
class Collision;
/**
*namespace CT ��������Ƃ��Ɏg�p����^
*/
namespace CT
{
	enum CollisionType
	{
		BOX,
		CIRCLE,
		POINTER,
		CAPSULE,
		LINE,
		NON,
	};
}


class CollisionBase
{
public:
	/**
	*@brief	:�����蔻��̌�
	*@param :CollisionBase b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionBase& b);
	/**
	*@brief	:��`�Ƃ̔���
	*@param :CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionBox& b);
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionCircle& b);
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionPointer& b);
	/**
	*@brief	:�J�v�Z���Ƃ̔���
	*@param	:CollisionCapsule b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionCapsule& b);
	/**
	*@brief	:���Ƃ̔���
	*@param	:CollisionLine b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionLine& b);
	/**
	*@brief	:�����蔻��𐶐�����
	*@param	:Vec2* pos Position
	*@param	:Vec2* scale Scale
	*@param	:Vec2* radius Radius
	*@param :float* angle Angle
	*/
	virtual void CreateHitBase(Vec2* pos, Vec2* scale, Vec2* radius, float* angle);
	/**
	*@brief	:constructor
	*@param	:unsigned short vertex ���_��
	*/
	explicit CollisionBase(const unsigned short vertex);
	//! ���_��
	const unsigned short VERTEX_NUM;
	//! Position
	Vec2* _pos;
	//! Scale
	Vec2* _scale;
	//! Radius
	Vec2* _radius;
	//! Angle
	float* _rotate;
};

class CollisionBox : public CollisionBase
{
	//! ��]�l
	float angle;
public:
	/**
	*@brief	:constructor
	*/
	explicit CollisionBox();
	//!	�����蔻��
	Box2D hitBase;
	/**
	*@brief	:��`�Ƃ̔���
	*@param :CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionBox& b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionCircle& b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionPointer& b) override;
	/**
	*@brief	:��]�l��ύX����
	*@param :float _angle ��]�l
	*/
	void Rotate(const float _angle);
	/**
	*@brief	:��]�l���擾����
	*@return:float ��]�l
	*/
	float Rotate() const;
	/**
	*@brief	:�����蔻��𐶐�����
	*/
	void CreateCollision();
};
class CollisionCircle : public CollisionBase
{
public:
	//! �����蔻��
	Circle hitBase;
	/**
	*@brief	:constructor
	*/
	explicit CollisionCircle();
	/**
	*@brief	:��`�Ƃ̔���
	*@param :CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionBox& b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionCircle& b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionPointer& b) override;
	/**
	*@brief	:�����蔻��𐶐�����
	*/
	void CreateCollision();
};
class CollisionPointer : public CollisionBase
{
public:
	//! �����蔻��
	Vec2 hitBase;
	/**
	*@brief	:constructor
	*/
	explicit CollisionPointer();
	/**
	*@brief	:��`�Ƃ̔���
	*@param	:CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionBox& b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param	:CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionPointer& b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param	:CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionCircle& b) override;
	/**
	*@brief	:���Ƃ̔���
	*@param	:CollisionLine b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(CollisionLine& b) override;
	/**
	*@brief	:�����蔻��𐶐�����
	*/
	void CreateCollision();
};
class CollisionLine : public CollisionBase
{
public:
	Vec2 hitBase[2];
	/**
	*@brief	:constructor
	*/
	explicit CollisionLine();
	/**
	*@brief	:�����蔻��𐶐�����
	*/
	void CreateCollision();
};
class CollisionCapsule : public CollisionBase
{
public:
	Vec2 hitBase[2];
	/**
	*@brief	:constructor
	*/
	explicit CollisionCapsule();
	bool Hit(CollisionCapsule& b) override;
	bool Hit(CollisionBox& b) override;
	bool Hit(CollisionCircle& b) override;
	bool Hit(CollisionPointer& b) override;
};

class Collision
{
	CollisionBox* box;
	CollisionCircle* circle;
	CollisionPointer* pointer;
	CollisionLine* line;
	CollisionCapsule* capsule;
	CT::CollisionType _type;
	/**
	*@brief	:Collision����
	*@param	:Vec2* pos Position
	*@param	:Vec2* scale Scale
	*@param	:Vec2* radius Radius
	*@param :float* angle Angle
	*/
	void CreateCollision(Vec2* pos, Vec2* scale, Vec2* radius, float* angle);
	/**
	*@brief	:Collision���Z�b�g
	*/
	void ResetCollision();
public:
	/**
	*@brief	:constructor
	*@param	:CT::CollisionType& type ����Collision
	*@param	:Vec2* pos Position
	*@param	:Vec2* scale Scale
	*@param	:Vec2* radius Radius
	*@param :float* angle Angle
	*/
	explicit Collision(CT::CollisionType type, Vec2* pos, Vec2* scale, Vec2* radius, float* angle);
	/**
	*@brief	:destructor
	*/
	virtual ~Collision();
	/**
	*@brief	:������擾����
	*@return:CollisionBase* ����
	*/
	CollisionBase* GetCollision() const;
	/**
	*@brief	:�����蔻��
	*/
	virtual bool Hit(Collision* collision);
};

template <class T>
class CollisionTest
{
	T* collision;
public:
	explicit CollisionTest()
	{
		this->collision = new T;
	}
	virtual ~CollisionTest()
	{
		delete this->collision;
	}
	T* GetCollision() const
	{
		return this->collision;
	}
};