#pragma once
#include "OGSystem\_OGsystem.h"

class Texture {
public:
	Texture();							//コンストラクタ
	~Texture();							//デストラクタ	
	bool Create(const std::string&);	//画像データの生成
	void Draw(							//描画処理
		const Box2D&, 
		const Box2D&,
		const Color = { 1.0f,1.0f,1.0f,1.0f });
	bool Finalize();					//解放処理
	void Rotate(const float);			//回転の適応
	Vec2 GetTextureSize() const;
private:
	GLuint _TexId;						//テクスチャのID
	Vec2 TextureSize;					//画像サイズ
	Vec2 _materix[4];					//頂点情報
	const std::string FileName;			//画像ファイルパス
	void _Rotate(const float,			//頂点座標を回転させる
				GLfloat*);
	float angle;						//回転値
};