#pragma once
#include "OG\OGsystem.h"

class TestObject : public GameObject
{
	LayerTexture tex;
	void Update() override;
	void Render2D() override;
public:
	explicit TestObject();
	virtual ~TestObject();
};