#pragma once
#include "OGSystem\_OGsystem.h"
class CollisionBase;
class CollisionBox;
class CollisionCircle;
class CollisionPointer;
class CollisionLine;
class CollisionCapsule;

/**
*namespace CT 
*@brief	��������Ƃ��Ɏg�p����^
*/
namespace CT
{
	enum CollisionType
	{
		//! ��`
		BOX,
		//! �~
		CIRCLE,
		//! �_
		POINTER,
		//! �J�v�Z��
		CAPSULE,
		//! ��
		LINE,
		//! ��
		NON,
	};
}

/**
*@brief	����̌�
*/
class CollisionBase
{
public:
	/**
	*@brief	constructor
	*@param[in]	unsigned short vertex ���_��
	*/
	explicit CollisionBase(const unsigned short vertex);
	/**
	*@brief	�����蔻��𐶐�����
	*@param[in]	Vec2* pos Position
	*@param[in]	Vec2* scale Scale
	*@param[in]	Vec2* radius Radius
	*@param[in] float* angle Angle
	*/
	virtual void CreateHitBase(Vec2* pos, Vec2* scale, Vec2* radius, float* angle);
	/**
	*@brief	�����蔻���Ԃ�
	*@param[in] CollisionBase* collision ���葊��
	*@return bool true hit
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
	*@brief	��`�Ƃ̔���
	*@param[in] CollisionBox* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) = 0;
	/**
	*@brief	�~�Ƃ̔���
	*@param[in] CollisionCircle* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle*b) = 0;
	/**
	*@brief	�_�Ƃ̔���
	*@param[in] CollisionPointer* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) = 0;
	/**
	*@brief	�J�v�Z���Ƃ̔���
	*@param[in]	CollisionCapsule* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCapsule* b) = 0;
	/**
	*@brief	���Ƃ̔���
	*@param[in]	CollisionLine* b ����̃I�u�W�F�N�g
	*@returnbool �������Ă����true
	*/
	virtual bool GetHit(CollisionLine* b) = 0;
};
/**
*@brief	��`����
*/
class CollisionBox : public CollisionBase
{
	//! ��]�l
	float angle;
public:
	/**
	*@brief	constructor
	*/
	explicit CollisionBox();
	//!	�����蔻��
	Box2D hitBase;
	/**
	*@brief	��]�l��ύX����
	*@param[in] float _angle ��]�l
	*/
	void Rotate(const float _angle);
	/**
	*@brief	��]�l���擾����
	*@return float ��]�l
	*/
	float Rotate() const;
	/**
	*@brief	�����蔻��𐶐�����
	*/
	void CreateCollision();
	/**
	*@brief	�����蔻���Ԃ�
	*@param[in]	CollisionBase* collision ���葊��
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	��`�Ƃ̔���
	*@param[in] CollisionBox* b ����̃I�u�W�F�N�g
	*@return  bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	�~�Ƃ̔���
	*@param[in] CollisionCircle* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	�_�Ƃ̔���
	*@param[in] CollisionPointer* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	�_�Ƃ̔���(������)
	*@param[in] CollisionLine* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	�J�v�Z���Ƃ̔���(������)
	*@param[in] CollisionCapsule* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};
/**
*@brief	�~����
*/
class CollisionCircle : public CollisionBase
{
public:
	//! �����蔻��
	Circle hitBase;
	/**
	*@brief	constructor
	*/
	explicit CollisionCircle();
	/**
	*@brief	�����蔻��𐶐�����
	*/
	void CreateCollision();
	/**
	*@brief	�����蔻���Ԃ�
	*@param[in]	CollisionBase* collision ���葊��
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	��`�Ƃ̔���
	*@param[in] CollisionBox* b ����̃I�u�W�F�N�g
	*@return  bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	�~�Ƃ̔���
	*@param[in] CollisionCircle* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	�_�Ƃ̔���
	*@param[in] CollisionPointer* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	���Ƃ̔���(������)
	*@param[in] CollisionLine* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	�J�v�Z���Ƃ̔���(������)
	*@param[in] CollisionCapsule* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};
/**
*@brief	�_����
*/
class CollisionPointer : public CollisionBase
{
public:
	//! �����蔻��
	Vec2 hitBase;
	/**
	*@brief	constructor
	*/
	explicit CollisionPointer();
	/**
	*@brief	�����蔻��𐶐�����
	*/
	void CreateCollision();
	/**
	*@brief	�����蔻���Ԃ�
	*@param[in]	CollisionBase* collision ���葊��
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	��`�Ƃ̔���
	*@param[in] CollisionBox* b ����̃I�u�W�F�N�g
	*@return  bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	�~�Ƃ̔���
	*@param[in] CollisionCircle* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	�_�Ƃ̔���
	*@param[in] CollisionPointer* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	���Ƃ̔���
	*@param[in] CollisionLine* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	�J�v�Z���Ƃ̔���(������)
	*@param[in] CollisionCapsule* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};
/**
*@brief	������
*/
class CollisionLine : public CollisionBase
{
public:
	//! �����蔻��
	Vec2 hitBase[2];
	/**
	*@brief	constructor
	*/
	explicit CollisionLine();
	/**
	*@brief	�����蔻��𐶐�����
	*/
	void CreateCollision();
	/**
	*@brief	�����蔻���Ԃ�
	*@param[in]	CollisionBase* collision ���葊��
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	��`�Ƃ̔���
	*@param[in] CollisionBox* b ����̃I�u�W�F�N�g
	*@return  bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	�~�Ƃ̔���
	*@param[in] CollisionCircle* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	�_�Ƃ̔���
	*@param[in] CollisionPointer* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	���Ƃ̔���
	*@param[in] CollisionLine* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	�J�v�Z���Ƃ̔���
	*@param[in] CollisionCapsule* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};
/**
*@brief	�J�v�Z������
*! ������
*/
class CollisionCapsule : public CollisionBase
{
public:
	//! �����蔻��
	Vec2 hitBase[2];
	/**
	*@brief	constructor
	*/
	explicit CollisionCapsule();
	/**
	*@brief	�����蔻���Ԃ�
	*@param[in]	CollisionBase* collision ���葊��
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	��`�Ƃ̔���
	*@param[in] CollisionBox* b ����̃I�u�W�F�N�g
	*@return  bool �������Ă����true
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	�~�Ƃ̔���
	*@param[in] CollisionCircle* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	�_�Ƃ̔���
	*@param[in] CollisionPointer* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	���Ƃ̔���
	*@param[in] CollisionLine* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	�J�v�Z���Ƃ̔���
	*@param[in] CollisionCapsule* b ����̃I�u�W�F�N�g
	*@return bool �������Ă����true
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};