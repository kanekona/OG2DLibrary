#pragma once
#include "State.h"

class TestState : public StateParam
{
public:
	void Enter() override;
	void Exit() override;
	void Update() override;
	void Param() override;
};