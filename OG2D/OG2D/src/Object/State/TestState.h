#pragma once
#include "State.h"
#include "Object\TestObject.h"
class TestState : public StateParam
{
	TestObject* object;
	unsigned int maxTime;
public:
	explicit TestState(TestObject* object,const std::string& tag);
	void Enter() override;
	void Exit() override;
	void Update() override;
	bool Param(StateManager* manager) override;
};

class Test2State : public StateParam
{
	TestObject* object;
public:
	explicit Test2State(TestObject* object, const std::string& tag);
	void Enter() override;
	void Exit() override;
	void Update() override;
	bool Param(StateManager* manager) override;
};

class Test3State : public StateParam
{
	TestObject* object;
public:
	explicit Test3State(TestObject* object, const std::string& tag);
	void Enter() override;
	void Exit() override;
	void Update() override;
	bool Param(StateManager* manager) override;
};

class Test4State : public StateParam
{
	TestObject* object;
public:
	explicit Test4State(TestObject* object, const std::string& tag);
	void Enter() override;
	void Exit() override;
	void Update() override;
	bool Param(StateManager* manager) override;
};