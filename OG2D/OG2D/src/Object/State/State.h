#pragma once
#include "OG\OGsystem.h"

class StateParam;
class StateManager;

class StateParam
{
	unsigned int timeCnt;
public:
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual void Update() = 0;
	virtual void Param() = 0;
	unsigned int GetTime() const;
	void TimeUp(const unsigned int cnt);
};

class StateManager
{
	//std::vector<std::pair<std::string, StateParam*>> list;
	std::unordered_map<std::string, StateParam*> list;
	/*StateParam* nowState;
	StateParam* nextState;
	StateParam* preState;*/
	std::string nowState;
	std::string nextState;
	std::string preState;
	StateParam* activeState;
public:
	explicit StateManager(const std::string& tag, StateParam* state);
	StateParam* GetState(const std::string& tag);
	bool SetState(const std::string& tag, StateParam* state);
	template <class T> T* GetState(const std::string& tag)
	{
		return (T*)this->list[tag];
	}
	void NextState(const std::string& tag);
};