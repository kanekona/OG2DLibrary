#pragma once
#include "OG\OGsystem.h"

class StateParam;
class StateManager;

class StateParam
{
	unsigned int timeCnt;
	std::string tag;
public:
	explicit StateParam(const std::string& tag);
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual void Update() = 0;
	//virtual std::string Param() = 0;
	virtual bool Param(StateManager* manager) = 0;
	unsigned int GetTime() const;
	void TimeUp(const unsigned int cnt);
	void ResetTime();
	std::string GetTag() const;
};

class StateManager : private NonCopyable
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
	virtual ~StateManager();
	StateParam* GetState(const std::string& tag);
	bool SetState(const std::string& tag, StateParam* state);
	template <class T> T* GetState(const std::string& tag)
	{
		return (T*)this->list[tag];
	}
	void NextState(const std::string& tag);
	void Update();
	void Param(const std::string& tag);
	void Param();
};