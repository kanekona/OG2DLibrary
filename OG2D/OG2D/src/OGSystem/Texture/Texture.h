/**
*�摜�̓ǂݍ��݁A�\�����s��class
*/
#pragma once
#include "OGSystem\_OGsystem.h"

class Texture {
public:
	/**
	*@brief	:constructor
	*/
	Texture();
	/**
	*@brief	:constructor
	*@param	:string path �t�@�C���p�X
	*/
	Texture(const std::string& path);
	/**
	*@brief	:destructor
	*/
	~Texture();
	/**
	*@brief	:�摜�f�[�^�̐���
	*@param	:string path �t�@�C���p�X
	*/
	bool Create(const std::string& path);
	/**
	*@brief	:�`�揈��
	*@param	:Box2D draw �`��͈�
	*@param	:Box2D src �摜�͈�
	*@param	:Color color �`��F
	*/
	void Draw(
		const Box2D& draw, 
		const Box2D& src,
		const Color& color = { 1.0f,1.0f,1.0f,1.0f });
	/**
	*@brief	:�������
	*@return:�������true
	*/
	bool Finalize();
	/**
	*@brief	:��]�̓K�p
	*@param	:float angle ��]�l
	*/
	void Rotate(const float angle);
	/**
	*@brief	:�ǂݍ��񂾉摜�̃T�C�Y��Ԃ�
	*@return:Vec2 �摜�̑傫��
	*/
	Vec2 GetTextureSize() const;
private:
	//! �e�N�X�`����ID
	GLuint _TexId;
	//! �摜�T�C�Y
	Vec2 TextureSize;
	//! ���_���
	Vec2 _materix[4];
	//! �摜�t�@�C���p�X
	const std::string FileName;
	/**
	*@brief	:���_���W����]������
	*@param :float angle ��]�l
	*@param	:GLfloat* materix �s��z��
	*/
	void _Rotate(const float angle,
				GLfloat* materix);
	//! ��]�l
	float angle;
};