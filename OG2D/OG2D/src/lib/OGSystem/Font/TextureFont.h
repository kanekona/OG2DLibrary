#pragma once
#include "OGSystem\Texture\Texture.h"
/**
*@brief	フォントの描画class
*
*現在対応しているもの
*
*アルファベット
*
*ひらがな
*
*カタカナ
*
*数字
*/
class Font
{
	//! 現在文字数
	float texSize;
	//! 画像の文字の大きさ
	const Vec2 TexFontSize;
	//! 画像の数字の大きさ
	const Vec2 TexNumberSize;
	//! 画像の半角文字の大きさ
	const Vec2 TexHalfFontSize;
	//! 指定文字と画像位置情報
	std::unordered_map<std::string, Box2D> func;
	//! 描画する文字列
	std::string drawText;
	//! 画像データのポインタ
	Texture* fontTex;
	//! 描画位置
	Box2D draw;
	//! 画像描画位置
	Box2D* src;
	/**
	*@brief	 指定文字の画像位置
	*@param[in] const string& c oneText
	*@return Box2D* 画像位置
	*/
	Box2D* CharacterCheck(const std::string& c);
	/**
	*@brief	文字データの生成
	*/
	void CreateCharacter();
public:
	/**
	*@brief	constructor
	*/
	explicit Font();
	/**
	*@brief	destructor
	*/
	virtual ~Font();
	/**
	*@brief	フォント描画
	*@param[in]	string text 描画文字列
	*@param[in]	Vec2 pos 描画位置
	*@param[in] int fontSize 描画文字サイズ
	*@param[in]	Color color 色指定
	*/
	void Draw(const std::string& text, const Vec2& pos, const int fontSize, const Color& color = { 1,1,1,1 });
	/**
	*@brief	登録画像の変更
	*@param[in]	string path ファイルパス
	*/
	void SetTexture(const std::string& path);
};