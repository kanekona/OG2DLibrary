#include "State.h"
StateParam::StateParam(const std::string& t)
{
	this->tag = t;
}
unsigned int StateParam::GetTime() const
{
	return this->timeCnt;
}
void StateParam::TimeUp(const unsigned int cnt)
{
	this->timeCnt += cnt;
}
void StateParam::ResetTime()
{
	this->timeCnt = 0;
}
std::string StateParam::GetTag() const
{
	return this->tag;
}

StateManager::StateManager(const std::string& tag, StateParam* state)
{
	this->list[tag] = state;
	this->nowState = tag;
	this->list[tag]->Enter(this);
}

StateManager::~StateManager()
{
	auto id = this->list.begin();
	while (id != this->list.end())
	{
		delete id->second;
		id = this->list.erase(id);
	}
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
	//this->Param(this->list[this->nowState]->Param());
	while(this->list[this->nowState]->Param(this))
	{
		this->Param();
	}
	this->list[this->nowState]->Update();
}
void StateManager::Param(const std::string& tag)
{
	this->preState = this->nowState;
	this->list[this->preState]->Exit(this);
	this->nowState = tag;
	this->list[this->nowState]->Enter(this);
}
void StateManager::Param()
{
	this->list[this->nowState]->Exit(this);
	this->preState = this->nowState;
	this->nowState = this->nextState;
	this->list[this->nowState]->Enter(this);
}