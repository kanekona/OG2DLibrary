#pragma once
#include "OGSystem\_OGsystem.h"

class Texture {
public:
	Texture();							//コンストラクタ
	~Texture();							//デストラクタ	
	void Create(std::string _path);		//画像データの生成
	void Draw(							//描画処理
		Box2D draw, 
		Box2D src, 
		Color color_ = { 1.0f,1.0f,1.0f,1.0f });
	void Finalize();					//解放処理
	void Rotate(float radian);			//回転の適応
private:
	GLuint _TexId;						//テクスチャのID
	Vec2 TextureSize;					//画像サイズ
	Vec2 _materix[4];					//頂点情報
	const std::string FileName = "./data/image/";//画像ファイルパス
	void _Rotate(float radian,			//頂点座標を回転させる
				GLfloat *mate);
	float angle;						//回転値
};