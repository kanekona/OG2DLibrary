#pragma once
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
class Button : public SceneTask
{
	//! Button�̓����蔻��
	GameObject* collision;
	//! ���݂̔����
	bool hitFlag;
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
	*@beief	:Object����Ԃ�
	*@return:GameObject* Button�̔���
	*/
	GameObject* GetObject() const;
};