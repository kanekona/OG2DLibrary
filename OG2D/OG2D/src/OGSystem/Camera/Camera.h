#pragma once
#include "OGSystem\_OGsystem.h"
class Camera2D
{
public:
	Camera2D();							//コンストラクタ
	Camera2D(Box2D pos);				//コンストラクタ
	~Camera2D();						//デストラクタ
	void Initialize(Box2D pos);			//初期化
	void CameraUpdate() const;			//更新処理
	void MovePos(Vec2 est);				//位置を加算する
	void SetPos(Vec2 est);				//位置を設定する	
	void SetSize(Vec2 size_);			//サイズを設定する
	void MoveSize(Vec2 size_);			//サイズを加算する
	Vec2 GetPos() const;				//位置を返す
	Vec2 GetSize() const;				//サイズを返す
	typedef std::shared_ptr<Camera2D> SP;//スマートポインタの生成
	static SP Create(Box2D pos);		//スマートポインタを返す
private:
	Box2D cameraPos;					//実際位置
	Vec2 position;						//位置
	Vec2 Scale;							//サイズ
};