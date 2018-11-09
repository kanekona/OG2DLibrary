#pragma once
#include "OG\OGsystem.h"
enum class Mode
{
	//1���ڃ_�E��2���ڃA�b�v
	DOWN_0,
	//2���ڃ_�E��3���ڃA�b�v
	DOWN_1,
	//�ҋ@
	WAIT,
	//3���ڃ_�E��2���ڃA�b�v
	UP_0,
	//2���ڃ_�E��1���ڃA�b�v
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