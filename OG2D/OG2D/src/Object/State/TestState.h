#pragma once
#include "State.h"
#include "Object\TestObject.h"

class BaseParam : public StateParam
{
	TestObject* object;
public:
	explicit BaseParam(TestObject* param,const std::string& tag);
};

class TestState : public BaseParam
{
	TestObject* object;
	unsigned int maxTime;
public:
	explicit TestState(TestObject* object,const std::string& tag);
	void Enter(StateManager* manager) override;
	void Exit(StateManager* manager) override;
	void Update() override;
	bool Param(StateManager* manager) override;
};

class Test2State : public BaseParam
{
	TestObject* object;
public:
	explicit Test2State(TestObject* object, const std::string& tag);
	void Enter(StateManager* manager) override;
	void Exit(StateManager* manager) override;
	void Update() override;
	bool Param(StateManager* manager) override;
};

class Test3State : public BaseParam
{
	TestObject* object;
public:
	explicit Test3State(TestObject* object, const std::string& tag);
	void Enter(StateManager* manager) override;
	void Exit(StateManager* manager) override;
	void Update() override;
	bool Param(StateManager* manager) override;
};

class Test4State : public BaseParam
{
	TestObject* object;
public:
	explicit Test4State(TestObject* object, const std::string& tag);
	void Enter(StateManager* manager) override;
	void Exit(StateManager* manager) override;
	void Update() override;
	bool Param(StateManager* manager) override;
};