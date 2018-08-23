#pragma once
//#include "OGSystem\_OGSystem.h"
#include "OGSystem\Texture\Texture.h"
/**
*@brief	:�t�H���g�̕`��class
*/
class Font
{
	//! ���ݕ�����
	unsigned int texSize;
	//! �摜�̕����̑傫��
	const Vec2 TexFontSize;
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
	*/
	void Draw(const std::string& text, const Vec2& pos, const int fontSize);
};