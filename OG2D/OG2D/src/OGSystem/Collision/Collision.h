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
	/**
	*@brief	:�����蔻���Ԃ�
	*@param	:CollisionBase* collision ���葊��
	*@return:bool true hit
	*/
	virtual bool Hit(CollisionBase* collision) = 0;
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
	/**
	*@brief	:��`�Ƃ̔���
	*@param :CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) = 0;
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle*b) = 0;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionPointer b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) = 0;
	/**
	*@brief	:�J�v�Z���Ƃ̔���
	*@param	:CollisionCapsule b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCapsule* b) = 0;
	/**
	*@brief	:���Ƃ̔���
	*@param	:CollisionLine b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionLine* b) = 0;
};

class CollisionBox : CollisionBase
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
	/**
	*@brief	:�����蔻���Ԃ�
	*@param	:CollisionBase* collision ���葊��
	*@return:bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	:��`�Ƃ̔���
	*@param :CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionPointer b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionLine b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionLine* b) override;
};

class CollisionCircle : CollisionBase
{
public:
	//! �����蔻��
	Circle hitBase;
	/**
	*@brief	:constructor
	*/
	explicit CollisionCircle();
	/**
	*@brief	:�����蔻��𐶐�����
	*/
	void CreateCollision();
	/**
	*@brief	:�����蔻���Ԃ�
	*@param	:CollisionBase* collision ���葊��
	*@return:bool true hit
	*/
	virtual bool Hit(CollisionBase* collision);
	/**
	*@brief	:��`�Ƃ̔���
	*@param :CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) override;
};

class CollisionPointer : CollisionBase
{
public:
	//! �����蔻��
	Vec2 hitBase;
	/**
	*@brief	:constructor
	*/
	explicit CollisionPointer();
	/**
	*@brief	:�����蔻��𐶐�����
	*/
	void CreateCollision();
	/**
	*@brief	:�����蔻���Ԃ�
	*@param	:CollisionBase* collision ���葊��
	*@return:bool true hit
	*/
	virtual bool Hit(CollisionBase* collision);
	/**
	*@brief	:��`�Ƃ̔���
	*@param	:CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param	:CollisionPointer b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param	:CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	:���Ƃ̔���
	*@param	:CollisionLine b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool GetHit(CollisionLine* b) override;
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
	/**
	*@brief	:�����蔻���Ԃ�
	*@param	:CollisionBase* collision ���葊��
	*@return:bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	bool GetHit(CollisionCapsule* b) override;
	bool GetHit(CollisionBox* b) override;
	bool GetHit(CollisionCircle* b) override;
	bool GetHit(CollisionPointer* b) override;
};