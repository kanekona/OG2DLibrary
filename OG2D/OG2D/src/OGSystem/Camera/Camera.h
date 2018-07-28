///GL機能を使用し2D上でのカメラを扱うclass
///既存GameEngineを使用している場合は内部で宣言されている
///使用しない場合は2Dの描画のために１つ生成する必要がある
#pragma once
#include "OGSystem\_OGsystem.h"
class Camera2D
{
public:
	Camera2D();							//コンストラクタ
	Camera2D(const Box2D&);					//コンストラクタ
	~Camera2D();						//デストラクタ
	void Initialize(const Box2D&);			//初期化
	void CameraUpdate() const;			//更新処理
	void MovePos(const Vec2&);				//位置を加算する
	void SetPos(const Vec2&);					//位置を設定する	
	void SetSize(const Vec2&);				//サイズを設定する
	void MoveSize(const Vec2&);				//サイズを加算する
	Vec2 GetPos() const;				//位置を返す
	Vec2 GetSize() const;				//サイズを返す
private:
	Box2D cameraPos;					//実際位置
	Vec2 position;						//位置
	Vec2 Scale;							//サイズ
};