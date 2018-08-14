/**
*GL�@�\���g�p��2D��ł̃J����������class
*����GameEngine���g�p���Ă���ꍇ�͓����Ő錾����Ă���
*�g�p���Ȃ��ꍇ��2D�̕`��̂��߂ɂP��������K�v������
*/
#pragma once
#include "OGSystem\_OGsystem.h"
/**
*@brief	:�J����2D
*/
class Camera2D
{
public:
	/**
	*@brief	:constructor
	*/
	Camera2D();
	/**
	*@brief	:constructor
	*@param	:Box2D b �ʒu�ƃT�C�Y
	*/
	Camera2D(const Box2D& b);	
	/**
	*@brief	:destructor
	*/
	~Camera2D();
	/**
	*@brief	:����������
	*@param	:Box2D b �ʒu�ƃT�C�Y
	*/
	void Initialize(const Box2D& b);
	/**
	*@brief	:�X�V����
	*/
	void UpDate() const;
	/**
	*@brief	:�ʒu���ړ�������
	*@param :Vec2 move �ړ��l
	*/
	void MovePos(const Vec2& move);
	/**
	*@brief	:�ʒu��ݒ肷��
	*@param	:Vec2 pos �ʒu
	*/
	void SetPos(const Vec2& pos);
	/**
	*@brief	:�T�C�Y��ݒ肷��
	*@param	:Vec2 size �傫��
	*/
	void SetSize(const Vec2& size);
	/**
	*@brief	:�T�C�Y�𓮂���
	*@param	:Vec2 move �ړ��l
	*/
	void MoveSize(const Vec2& move);
	/**
	*@brief	:�J�����ʒu��X���W��ݒ肷��
	*@param	:float x ���W�l
	*/
	void SetPos_x(const float& x);
	/**
	*@brief	:�J�����ʒu��Y���W��ݒ肷��
	*@param	:float y ���W�l
	*/
	void SetPos_y(const float& y);
	/**
	*@brief	:�J�����̉��T�C�Y��ς���
	*@param	:float w ���T�C�Y
	*/
	void SetSize_w(const float& w);
	/**
	*@brief	:�J�����̏c�T�C�Y��ς���
	*@param	:float w �c�T�C�Y
	*/
	void SetSize_h(const float& h);
	/**
	*@brief	:�J�����̈ʒu��Ԃ�
	*@return:Vec2 �J�����ʒu
	*/
	Vec2 GetPos() const;
	/**
	*@brief	:�J�����̃T�C�Y��Ԃ�
	*@return:Vec2 �J�����̑傫��
	*/
	Vec2 GetSize() const;
private:
	//!	���ۈʒu
	Box2D cameraPos;				
	//!	�ʒu
	Vec2 position;
	//! �T�C�Y
	Vec2 Scale;
};