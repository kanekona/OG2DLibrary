#pragma once
#include "OG\OGsystem.h"
#include "State\State.h"

class TestObject : public GameObject
{
	LayerTexture tex;
	void Update() override;
	void Render2D() override;
	StateManager* sm;
public:
	explicit TestObject(const std::string& tag);
	virtual ~TestObject();
	LayerTexture* GetLayerData();
};