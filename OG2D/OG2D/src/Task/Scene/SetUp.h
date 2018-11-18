#pragma once
#include "OG\OGsystem.h"

enum class Mode
{
	NON,
	LOADFILE,
};

class SetUp : public SceneTask
{
	Mode mode;
public:
	explicit SetUp();
	virtual ~SetUp();
	void Update() override;
};

class LOADFILE
{
public:
	explicit LOADFILE();
	virtual ~LOADFILE();
};