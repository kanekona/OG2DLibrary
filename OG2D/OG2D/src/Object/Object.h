#pragma once
//_____________________________
//|�Q�[���I�u�W�F�N�g            
//|�����F2018/03/20   
//|____________________________
#include "OGSystem\OGlib.h"
#include "OGSystem\Collision\Collision.h"
#include "OGSystem\TaskObject.h"

class GameObject
{
	//! �ʒu
	Vec2 position;
	//! �K��
	Vec2 scale;
	//! �p�x
	float angle;
public:
	/**
	*@brief	:constructor
	*/
	explicit GameObject();
	/**
	*@brief	:destructor
	*/
	virtual ~GameObject();
};

///**
//*enum Objform
//*�I�u�W�F�N�g�̌`
//*/
//enum Objform
//{
//	//! ��
//	Non,
//	//!	�~
//	Ball,
//	//! ��`
//	Cube,
//};
///**
//*@brief	:�Q�[���Ŏg�p����I�u�W�F�N�g�pclass
//*/
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