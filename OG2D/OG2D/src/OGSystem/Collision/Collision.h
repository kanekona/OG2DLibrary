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
*/
class CollisionCapsule;

class CollisionBase
{
public:
	/**
	*@brief	:�����蔻��̌�
	*@param :CollisionBase b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(const CollisionBase& b);
	/**
	*@brief	:��`�Ƃ̔���
	*@param :CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(const CollisionBox& b);
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(const CollisionCircle& b);
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(const CollisionPointer& b);
	/**
	*@brief	:�J�v�Z���Ƃ̔���
	*@param	:CollisionCapsule b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(const CollisionCapsule& b);
	/**
	*@brief	:���Ƃ̔���
	*@param	:CollisionLine b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool Hit(const CollisionLine& b);
	/**
	*@brief	:�����蔻��𐶐�����
	*@param	:Vec2 pos Position
	*@param	:Vec2 scale Scale
	*/
	virtual void CreateHitBase(const Vec2& pos, const Vec2& scale);
	/**
	*@brief	:constructor
	*@param	:unsigned short vertex ���_��
	*/
	explicit CollisionBase(const unsigned short vertex);
	//! ���_��
	const unsigned short VERTEX_NUM;
	//! Position
	Vec2* pos;
	//! Scale
	Vec2* scale;
	//! Radius
	Vec2* radius;
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
	bool Hit(const CollisionBox& b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool Hit(const CollisionCircle& b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool Hit(const CollisionPointer& b) override;
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
	bool Hit(const CollisionBox& b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool Hit(const CollisionCircle& b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool Hit(const CollisionPointer& b) override;
private:
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
	bool Hit(const CollisionBox& b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param	:CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool Hit(const CollisionPointer& b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param	:CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool Hit(const CollisionCircle& b) override;
	/**
	*@brief	:���Ƃ̔���
	*@param	:CollisionLine b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool Hit(const CollisionLine& b) override;
};
class CollisionLine : public CollisionBase
{
public:
	Vec2 hitBase[2];
	/**
	*@brief	:constructor
	*/
	explicit CollisionLine();
};
class CollisionCapsule : public CollisionBase
{
public:
	Vec2 hitBase[2];
	/**
	*@brief	:constructor
	*/
	explicit CollisionCapsule();
	bool Hit(const CollisionCapsule& b) override;
	bool Hit(const CollisionBox& b) override;
	bool Hit(const CollisionCircle& b) override;
	bool Hit(const CollisionPointer& b) override;
};