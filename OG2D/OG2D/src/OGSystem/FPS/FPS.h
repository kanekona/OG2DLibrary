///フレームレートを計算,制限(未実装)するclass
///既存GameEngineを使用している場合はDEBUG時のみ自動で生成される
#pragma once
#include "OGSystem\_OGsystem.h"

class FPS {
public:
	FPS();							//コンストラクタ
	~FPS();							//デストラクタ
	void Update();					//更新処理
private:
	float lastTime;					//前フレームタイム
	int count;						//カウント数
	GLfloat fps;					//fps値
};
