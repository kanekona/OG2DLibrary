#pragma once
#include "OG\OGsystem.h"
#include "Object\GameObject.h"
/**
*@brief	�}�E�X�ɔ�������Buttonclass
*�}�E�X�Ɠ������Ă��ăN���b�N����Ă��锻����s���Ă����
*/
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
	//! Font
	Font font;
	/**
	*@brief	constructor
	*@param[in]	Vec2 pos �����ʒu
	*@param[in]	Vec2 size �����T�C�Y
	*@param[in]	string name �o�^��
	*/
	explicit Button(const Vec2& pos, const Vec2& size,const std::string& name);
	/**
	*@brief	�X�V����
	*/
	void Update() override;
	/**
	*@brief	�`�揈��
	*/
	void Render2D() override;
public:
	/**
	*@brief	destructor
	*/
	virtual ~Button();
	/**
	*@brief	Button����
	*@param[in]	const Vec2& pos �ʒu
	*@param[in] const Vec2& size �傫��
	*@param[in]	const string& name �o�^��
	*@return Button* ��������Button
	*/
	static Button* Create(const Vec2& pos, const Vec2& size,const std::string& name);
	/**
	*@brief	�}�E�X�|�C���^�Ƃ̔����Ԃ�
	*@return bool Hit true
	*/
	bool IsMouseHit() const;
	/**
	*@brief	Button�ɐݒu����Text
	*@param[in]	const string& text
	*/
	void SetText(const std::string& text);
};