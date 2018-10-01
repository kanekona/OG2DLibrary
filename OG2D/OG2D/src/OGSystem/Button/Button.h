#pragma once
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
class Button : public GameObject
{
	//! ���݂̔����
	bool hitFlag;
	//! �摜�f�[�^
	Texture* image;
	//! �`��ʒu
	Box2D* draw;
	//! �`��摜�ʒu
	Box2D* src;
	//! �摜�J���[
	Color* image_color;
	/**
	*@brief	:constructor
	*@param	:Vec2 pos �����ʒu
	*@param	:Vec2 size �����T�C�Y
	*/
	explicit Button(const Vec2& pos, const Vec2& size);
	/**
	*@brief	:�X�V����
	*/
	void Update() override;
	/**
	*@brief	:�`�揈��
	*/
	void Render2D() override;
public:
	/**
	*@brief	:destructor
	*/
	virtual ~Button();
	/**
	*@brief	:Button����
	*@param	:const Vec2& pos �ʒu
	*@param :const Vec2& size �傫��
	*@return:Button* ��������Button
	*/
	static Button* Create(const Vec2& pos, const Vec2& size);
};