
#pragma once
#include "OG\_OGsystem.h"
/**
*@brief	�摜�̓ǂݍ��݁A�\�����s��class
*/
class Texture {
	//! �e�N�X�`����ID
	GLuint* _TexId;
	//! �摜�T�C�Y
	Vec2 TextureSize;
	//! ���_���
	Vec2 _materix[4];
	//! �摜�t�@�C���p�X
	const std::string FileName;
	/**
	*@brief	���_���W����]������
	*@param[in] float angle ��]�l
	*@param[in]	GLfloat* materix �s��z��
	*/
	void _Rotate(const float angle,
		GLfloat* materix);
	//! ��]�l
	float angle;
	/**
	*@brief	�������
	*@return �������true
	*/
	bool Finalize();
	/**
	*@brief	������
	*@param[in]	const string& path �ǂݍ��ރt�@�C����
	*@return bool �ǂݍ��ݎ��s�����ꍇfalse��Ԃ�
	*/
	bool Init(const std::string& path);
public:
	/**
	*@brief	constructor
	*/
	explicit Texture();
	/**
	*@brief	constructor
	*@param[in]	string path �t�@�C���p�X
	*/
	explicit Texture(const std::string& path);
	/**
	*@brief	destructor
	*/
	virtual ~Texture();
	/**
	*@brief	�摜�f�[�^�̐���
	*@param[in]	string path �t�@�C���p�X
	*/
	bool Create(const std::string& path);
	/**
	*@brief	�`�揈��
	*@param[in]	Box2D draw �`��͈�
	*@param[in]	Box2D src �摜�͈�
	*@param[in]	Color color �`��F
	*/
	void Draw(
		const Box2D& draw, 
		const Box2D& src,
		const Color& color = { 1.0f,1.0f,1.0f,1.0f });
	/**
	*@brief	��]�̓K�p
	*@param[in]	float angle ��]�l
	*/
	void Rotate(const float angle);
	/**
	*@brief	�ǂݍ��񂾉摜�̃T�C�Y��Ԃ�
	*@return Vec2 �摜�̑傫��
	*/
	Vec2 GetTextureSize() const;
	/**
	*@brief	�o�^����Ă���ID��Ԃ�
	*@return GLuint ID
	*/
	GLuint GetID() const;
	/**
	*@brief	�e�N�X�`��ID�𐶐�����
	*@param[in]	GLsizei size ������
	*@return GLuint ID
	*/
	GLuint CreateID(const GLsizei& size);
	/**
	*@brief	�e�N�X�`��ID���폜����
	*@param[in]	GLsizei size �폜��
	*/
	void DeleteID(const GLsizei& size);
	/**
	*@brief	�e�N�X�`�����o�C���h����
	*@param[in]	GLuint id �o�C���h����ID
	*0�w��őΏۂ𖳂ɂ���
	*/
	void Bind(const GLuint& id);
	/**
	*@brief	�e�N�X�`���f�[�^��o�^����
	*@param[in]	char* data TextureData
	*@param[in] unsigned int w TextureSize_w
	*@param[in] unsigned int h TextureSize_h
	*/
	void SetBuffer(const char* data, const unsigned int w, const unsigned int h);
};