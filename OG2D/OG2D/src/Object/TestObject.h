#pragma once
#include "OG\OGsystem.h"
enum class Mode
{
	//1枚目ダウン2枚目アップ
	DOWN_0,
	//2枚目ダウン3枚目アップ
	DOWN_1,
	//待機
	WAIT,
	//3枚目ダウン2枚目アップ
	UP_0,
	//2枚目ダウン1枚目アップ
	UP_1,
};
class TestObject : public GameObject
{
	unsigned int timeCnt;
	unsigned int maxTime;
	LayerTexture tex;
	Mode mode;
	Mode premode;
	void Update() override;
	void Render2D() override;
public:
	explicit TestObject(const std::string& tag);
	virtual ~TestObject();
};