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
	/**
	*@brief	:��`�Ƃ̔���
	*@param :CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool hitBox(const CollisionBox& b);
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool hitCircle(const CollisionCircle& b);
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool hitPointer(const CollisionPointer& b);
	/**
	*@brief	:�J�v�Z���Ƃ̔���
	*@param	:CollisionCapsule b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool hitCapsule(const CollisionCapsule& b);
	/**
	*@brief	:���Ƃ̔���
	*@param	:CollisionLine b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	virtual bool hitLine(const CollisionLine& b);
public:
	/**
	*@brief	:constructor
	*@param	:unsigned short vertex ���_��
	*/
	explicit CollisionBase(const unsigned short vertex);
	//! ���_��
	const unsigned short VERTEX_NUM;
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
	bool hitBox(const CollisionBox& b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitCircle(const CollisionCircle& b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitPointer(const CollisionPointer& b) override;
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
	bool hitBox(const CollisionBox& b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitCircle(const CollisionCircle& b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitPointer(const CollisionPointer& b) override;
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
	bool hitBox(const CollisionBox& b) override;
	/**
	*@brief	:�~�Ƃ̔���
	*@param	:CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitPointer(const CollisionPointer& b) override;
	/**
	*@brief	:�_�Ƃ̔���
	*@param	:CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitCircle(const CollisionCircle& b) override;
	/**
	*@brief	:���Ƃ̔���
	*@param	:CollisionLine b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitLine(const CollisionLine& b) override;
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
	bool hitCapsule(const CollisionCapsule& b) override;
	bool hitBox(const CollisionBox& b) override;
	bool hitCircle(const CollisionCircle& b) override;
	bool hitPointer(const CollisionPointer& b) override;
};