#pragma once
#include "Entity\Entity.h"
#include "State\State.h"
#include "Texture\LayerTexture.h"

class TestObject : public Entity
{
	LayerTexture tex;
	void Update() override;
	StateManager* sm;
public:
	explicit TestObject(const std::string& tag);
	virtual ~TestObject();
	LayerTexture* GetLayerData();
};