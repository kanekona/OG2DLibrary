#pragma once
#include "OGSystem\Texture\Texture.h"
/**
*�t�H���g�̕`��class
*���ݑΉ����Ă������
*�A���t�@�x�b�g
*�Ђ炪��
*�J�^�J�i
*����
*/
class Font
{
	//! ���ݕ�����
	unsigned int texSize;
	//! �摜�̕����̑傫��
	const Vec2 TexFontSize;
	//! �摜�̐����̑傫��
	const Vec2 TexNumberSize;
	//! �w�蕶���Ɖ摜�ʒu���
	std::unordered_map<std::string, Box2D> func;
	//! �`�悷�镶����
	std::string drawText;
	//! �摜�f�[�^�̃|�C���^
	Texture* fontTex;
	//! �`��ʒu
	Box2D draw;
	//! �摜�`��ʒu
	Box2D* src;
	/**
	*@brief	:�w�蕶���̉摜�ʒu
	*@return:Box2D* �摜�ʒu
	*/
	Box2D* CharacterCheck(const std::string& c);
	/**
	*@brief	:�����f�[�^�̐���
	*/
	void CreateCharacter();
public:
	/**
	*@brief	:constructor
	*/
	Font();
	/**
	*@brief	:destructor
	*/
	virtual ~Font();
	/**
	*@brief	:�t�H���g�`��
	*@param	:string text �`�敶����
	*@param	:Vec2 pos �`��ʒu
	*@param :int fontSize �`�敶���T�C�Y
	*@param	:Color color �F�w��
	*/
	void Draw(const std::string& text, const Vec2& pos, const int fontSize, const Color& color = { 1,1,1,1 });
	/**
	*@brief	:�o�^�摜�̕ύX
	*@param	:string path �t�@�C���p�X
	*/
	void SetTexture(const std::string& path);
};