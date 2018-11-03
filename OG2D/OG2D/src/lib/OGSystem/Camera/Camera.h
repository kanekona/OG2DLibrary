#pragma once
#include "OG\_OGsystem.h"
#include "Collision\Collision.h"
/**
*@brief	2DCamera
*
*GL�@�\���g�p��2D��ł̃J����������class
*
*����GameEngine���g�p���Ă���ꍇ�͓����Ő錾����Ă���
*
*�g�p���Ȃ��ꍇ��2D�̕`��̂��߂ɂP��������K�v������
*/
class Camera2D : private NonCopyable
{
	//!	���ۈʒu
	Box2D cameraPos;
	//!	�ʒu
	Vec2 position;
	//! �T�C�Y
	Vec2 Scale;
	//! ���e�s���ۑ����Ă����z��
	GLfloat projectionMatrix[16];
	//! ����p
	CollisionCircle collision;
	//! Collision�p�ϐ�
	Vec2 radius;
	//! Collision�p�ϐ�
	float angle;
	//! Collision�pPos
	Vec2 centerPos;
	//! Collision�pScale
	Vec2 direScale;
public:
	/**
	*@brief	constructor
	*/
	explicit Camera2D();
	/**
	*@brief	constructor
	*@param[in]	const Box2D& b �ʒu�ƃT�C�Y
	*/
	explicit Camera2D(const Box2D& b);
	/**
	*@brief	destructor
	*/
	virtual ~Camera2D();
	/**
	*@brief	����������
	*@param[in]	const Box2D& b �ʒu�ƃT�C�Y
	*/
	void Initialize(const Box2D& b);
	/**
	*@brief	�X�V����
	*/
	void Update();
	/**
	*@brief	�ʒu���ړ�������
	*@param[in] const Vec2& move �ړ��l
	*/
	void MovePos(const Vec2& move);
	/**
	*@brief	�ʒu��ݒ肷��
	*@param[in]	const Vec2& pos �ʒu
	*/
	void SetPos(const Vec2& pos);
	/**
	*@brief	�T�C�Y��ݒ肷��
	*@param[in]	const Vec2& size �傫��
	*/
	void SetSize(const Vec2& size);
	/**
	*@brief	�T�C�Y�𓮂���
	*@param[in]	const Vec2& move �ړ��l
	*/
	void MoveSize(const Vec2& move);
	/**
	*@brief	�J�����ʒu��X���W��ݒ肷��
	*@param[in]	float x ���W�l
	*/
	void SetPos_x(const float& x);
	/**
	*@brief	�J�����ʒu��Y���W��ݒ肷��
	*@param[in]	float y ���W�l
	*/
	void SetPos_y(const float& y);
	/**
	*@brief	�J�����̉��T�C�Y��ς���
	*@param[in]	float w ���T�C�Y
	*/
	void SetSize_w(const float& w);
	/**
	*@brief	�J�����̏c�T�C�Y��ς���
	*@param[in]	float w �c�T�C�Y
	*/
	void SetSize_h(const float& h);
	/**
	*@brief	�J�����̈ʒu��Ԃ�
	*@return Vec2 �J�����ʒu
	*/
	Vec2 GetPos() const;
	/**
	*@brief	�J�����̃T�C�Y��Ԃ�
	*@return Vec2 �J�����̑傫��
	*/
	Vec2 GetSize() const;
	/**
	*@brief	���e�s���o�^����
	*@param[in] float left ��
	*@param[in] float right �E
	*@param[in] float buttom ��
	*@param[in] float top ��
	*@param[in] float nearVal ��O
	*@param[in] float farVal ��
	*/
	void SetProjectionMatrix(
		const float left, const float right,
		const float buttom, const float top,
		const float nearVal, const float farVal);
	/**
	*@brief	���e�s����擾����
	*@return GLfloat* ���e�s��
	*/
	GLfloat* GetProjectionMatrix();
	/**
	*@brief Camera������擾
	*@return CollisionCircle* ����
	*/
	CollisionCircle* GetCollision();
};