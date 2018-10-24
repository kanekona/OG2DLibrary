#pragma once
#include "OG\OGsystem.h"

class Back : public GameObject
{
	//! �摜�f�[�^
	Texture* image;
	//! �`��ʒu
	Box2D draw;
	//! �摜�ʒu
	Box2D src;
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
	*@brief	constructor
	*@param[in]	const string& path
	*/
	explicit Back(const std::string& path);
	/**
	*@brief	destructor
	*/
	virtual ~Back();
};