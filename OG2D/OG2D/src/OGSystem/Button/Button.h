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
	//! Text����
	std::string _text;
	/**
	*@brief	:constructor
	*@param	:Vec2 pos �����ʒu
	*@param	:Vec2 size �����T�C�Y
	*@param	:string name �o�^��
	*/
	explicit Button(const Vec2& pos, const Vec2& size,const std::string& name);
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
	*@param	:const string& name �o�^��
	*@return:Button* ��������Button
	*/
	static Button* Create(const Vec2& pos, const Vec2& size,const std::string& name);
	/**
	*@brief	:�}�E�X�|�C���^�Ƃ̔����Ԃ�
	*@return:bool Hit true
	*/
	bool IsMouseHit() const;
	/**
	*@brief	:Button�ɐݒu����Text
	*@param	:string text
	*/
	void SetText(const std::string& text);
};