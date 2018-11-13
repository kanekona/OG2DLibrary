#pragma once
#include "OGSystem\ResourceManager\ResourceManager.h"
#include "OG\_OGsystem.h"
class EffectManager : private NonCopyable
{
	ResourceManager* rm;
public:
	explicit EffectManager(ResourceManager* manager);
};