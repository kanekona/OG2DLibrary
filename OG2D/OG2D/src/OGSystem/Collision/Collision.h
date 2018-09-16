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

class CollisionBase
{
	virtual bool hitBox(const CollisionBox& b);
	virtual bool hitCircle(const CollisionCircle& b);
	virtual bool hitPointer(const CollisionPointer& b);
public:
	explicit CollisionBase(const unsigned short vertex);
	const unsigned short VERTEX_NUM;
};

class CollisionBox : public CollisionBase
{
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
	bool hitBox(const CollisionBox& b);
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitCircle(const CollisionCircle& b);
	/**
	*@brief	:�_�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitPointer(const CollisionPointer& b);
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
private:
	//! ��]�l
	float angle;
};
class CollisionCircle : public CollisionBase
{
public:
	/**
	*@brief	:constructor
	*/
	explicit CollisionCircle();
	//! �����蔻��
	Circle hitBase;
	/**
	*@brief	:��`�Ƃ̔���
	*@param :CollisionBox b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitBox(const CollisionBox& b);
	/**
	*@brief	:�~�Ƃ̔���
	*@param :CollisionCircle b ����̃I�u�W�F�N�g
	*@return:bool �������Ă����true
	*/
	bool hitCircle(const CollisionCircle& b);
private:
};

class CollisionPointer : public CollisionBase
{
public:
	explicit CollisionPointer();
	Vec2 hitBase;
	/*bool hitBox(const CollisionBox& b) override;
	bool hitPointer(const CollisionPointer& b) override;
	bool hitCircle(const CollisionCircle& b) override;*/
};