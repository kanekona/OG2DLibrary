#include "TestState.h"
BaseParam::BaseParam(TestObject* obj, const std::string& tag)
	:StateParam(tag)
{
	this->object = obj;
}
TestState::TestState(TestObject* obj,const std::string& tag)
	:BaseParam(obj,tag)
{
	this->object = obj;
}
void TestState::Enter(StateManager* manager)
{
	this->ResetTime();
	this->maxTime = random::GetRand(50, 150);
}
void TestState::Exit(StateManager* manager)
{
	this->object->GetLayerData()->Get("kiri1")->color.alpha = 0.0f;
	this->object->GetLayerData()->Get("kiri2")->color.alpha = 1.0f;
}
void TestState::Update()
{
	this->TimeUp(1);
}
bool TestState::Param(StateManager* manager)
{
	if (this->GetTime() > this->maxTime)
	{
		manager->NextState("test1");
		return true;
	}
	return false;
}

Test2State::Test2State(TestObject* obj, const std::string& tag)
	:BaseParam(obj, tag)
{
	this->object = obj;
}
void Test2State::Enter(StateManager* manager)
{
	this->ResetTime();
}
void Test2State::Exit(StateManager* manager)
{
	this->object->GetLayerData()->Get("kiri2")->color.alpha = 0.0f;
	this->object->GetLayerData()->Get("kiri3")->color.alpha = 1.0f;
}
void Test2State::Update()
{
	this->TimeUp(1);
}
bool Test2State::Param(StateManager* manager)
{
	if (this->GetTime() > 5)
	{
		manager->NextState("test2");
		return true;
	}
	return false;
}

Test3State::Test3State(TestObject* obj, const std::string& tag)
	:BaseParam(obj, tag)
{
	this->object = obj;
}
void Test3State::Enter(StateManager* manager)
{
	this->ResetTime();
}
void Test3State::Exit(StateManager* manager)
{
	this->object->GetLayerData()->Get("kiri2")->color.alpha = 1.0f;
	this->object->GetLayerData()->Get("kiri3")->color.alpha = 0.0f;
}
void Test3State::Update()
{
	this->TimeUp(1);
}
bool Test3State::Param(StateManager* manager)
{
	if (this->GetTime() > 5)
	{
		manager->NextState("test3");
		return true;
	}
	return false;
}

Test4State::Test4State(TestObject* obj, const std::string& tag)
	:BaseParam(obj, tag)
{
	this->object = obj;
}
void Test4State::Enter(StateManager* manager)
{
	this->ResetTime();
}
void Test4State::Exit(StateManager* manager)
{
	this->object->GetLayerData()->Get("kiri1")->color.alpha = 1.0f;
	this->object->GetLayerData()->Get("kiri2")->color.alpha = 0.0f;
}
void Test4State::Update()
{
	this->TimeUp(1);
}
bool Test4State::Param(StateManager* manager)
{
	if (this->GetTime() > 5)
	{
		manager->NextState("test");
		return true;
	}
	return false;
}