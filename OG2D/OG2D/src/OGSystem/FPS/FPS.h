#pragma once
#include "OGSystem\_OGsystem.h"
#include <functional>
class FPS {
public:
	FPS();							//コンストラクタ
	~FPS();							//デストラクタ
	void Initialize();				//初期化	
	void Update();					//更新処理
	void SetData(void data_());		//関数登録
	void DeleteData();				//データの削除
	typedef std::shared_ptr<FPS> SP;//スマートポインタの生成
	static SP Create();				//スマートポインタを返す
private:
	float lastTime;					//前フレームタイム
	int count;						//カウント数
	GLfloat fps;					//fps値
	std::vector<std::function<void()>> data;//関数データ
	float Setfps;					//fpsを設定
	float setlast;					//前fps値
};
