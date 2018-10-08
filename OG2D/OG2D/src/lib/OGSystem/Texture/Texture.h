
#pragma once
#include "OG\_OGsystem.h"
/**
*@brief	画像の読み込み、表示を行うclass
*/
class Texture {
	//! テクスチャのID
	GLuint* _TexId;
	//! 画像サイズ
	Vec2 TextureSize;
	//! 頂点情報
	Vec2 _materix[4];
	//! 画像ファイルパス
	const std::string FileName;
	/**
	*@brief	頂点座標を回転させる
	*@param[in] float angle 回転値
	*@param[in]	GLfloat* materix 行列配列
	*/
	void _Rotate(const float angle,
		GLfloat* materix);
	//! 回転値
	float angle;
	/**
	*@brief	解放処理
	*@return 解放成功true
	*/
	bool Finalize();
	/**
	*@brief	初期化
	*@param[in]	const string& path 読み込むファイル名
	*@return bool 読み込み失敗した場合falseを返す
	*/
	bool Init(const std::string& path);
public:
	/**
	*@brief	constructor
	*/
	explicit Texture();
	/**
	*@brief	constructor
	*@param[in]	string path ファイルパス
	*/
	explicit Texture(const std::string& path);
	/**
	*@brief	destructor
	*/
	virtual ~Texture();
	/**
	*@brief	画像データの生成
	*@param[in]	string path ファイルパス
	*/
	bool Create(const std::string& path);
	/**
	*@brief	描画処理
	*@param[in]	Box2D draw 描画範囲
	*@param[in]	Box2D src 画像範囲
	*@param[in]	Color color 描画色
	*/
	void Draw(
		const Box2D& draw, 
		const Box2D& src,
		const Color& color = { 1.0f,1.0f,1.0f,1.0f });
	/**
	*@brief	回転の適用
	*@param[in]	float angle 回転値
	*/
	void Rotate(const float angle);
	/**
	*@brief	読み込んだ画像のサイズを返す
	*@return Vec2 画像の大きさ
	*/
	Vec2 GetTextureSize() const;
	/**
	*@brief	登録されているIDを返す
	*@return GLuint ID
	*/
	GLuint GetID() const;
	/**
	*@brief	テクスチャIDを生成する
	*@param[in]	GLsizei size 生成数
	*@return GLuint ID
	*/
	GLuint CreateID(const GLsizei& size);
	/**
	*@brief	テクスチャIDを削除する
	*@param[in]	GLsizei size 削除数
	*/
	void DeleteID(const GLsizei& size);
	/**
	*@brief	テクスチャをバインドする
	*@param[in]	GLuint id バインドするID
	*0指定で対象を無にする
	*/
	void Bind(const GLuint& id);
	/**
	*@brief	テクスチャデータを登録する
	*@param[in]	char* data TextureData
	*@param[in] unsigned int w TextureSize_w
	*@param[in] unsigned int h TextureSize_h
	*/
	void SetBuffer(const char* data, const unsigned int w, const unsigned int h);
};