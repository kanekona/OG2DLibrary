#include "State.h"

unsigned int StateParam::GetTime() const
{
	return this->timeCnt;
}
void StateParam::TimeUp(const unsigned int cnt)
{
	this->timeCnt += cnt;
}


StateManager::StateManager(const std::string& tag, StateParam* state)
{
	this->list[tag] = state;
	this->nowState = tag;
}

StateParam* StateManager::GetState(const std::string& tag)
{
	return this->list[tag];
}
bool StateManager::SetState(const std::string& tag, StateParam* state)
{
	this->list[tag] = state;
	return true;
}
void StateManager::NextState(const std::string& tag)
{
	this->nextState = tag;
}
void StateManager::Update()
{
	this->list[this->nowState]->Update();
}