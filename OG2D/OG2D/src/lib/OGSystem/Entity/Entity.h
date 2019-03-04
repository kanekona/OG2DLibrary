#pragma once
#include "NonCopyable\NonCopyable.hpp"
#include <vector>
#include <string>
#include "EntityLayer.h"
#define KL_ENTITY_NORMAL 0x00
#define KL_ENTITY_KILL 0x01
#pragma warning (disable : 4100)
/**
*@brief Šî‘bclass
*•`‰æ‚ÆXV‚Ì‹@”\‚Ì‚İ
*/
class Entity : private NonCopyable
{
	//! Enable Active
	bool active;
	//! Entity StateCount
	unsigned int stateCount;
	//! Children
	std::vector<Entity*> childs;
	//! Plans Children
	std::vector<Entity*> plansChilds;
	/**
	*@brief Entity Update
	*/
	virtual void Update();
	/**
	*@brief Entity System Enter
	*/
	virtual void Enter();
	/**
	*@brief	Register registration schedule
	*/
	void RegisterChildren();
	/**
	*@brief Kill Check Children
	*/
	void KillChildren();
	/**
	*@brief	Children
	*/
	template <class T> static T* GetChildren(std::vector<Entity*>* entity)
	{
		for (auto it : *entity)
		{
			if ((typeid(*it) == typeid(T)))
			{
				return static_cast<T*>(it);
			}
			T* t = GetChildren<T>(it->childs);
			if (t != nullptr)
			{
				return t;
			}
		}
		return nullptr;
	}
public:
	//! tag
	std::string tag;
	//! Layer
	Layer layer;
	/**
	*@brief	constructor
	*/
	explicit Entity();
	/**
	*@brief	destructor
	*/
	virtual ~Entity();
	/**
	*@brief	Entity Set Active
	*@param[in] bool isActive EntityActive
	*/
	void SetActive(const bool isActive);
	/**
	*@brief Entity GetActive
	*@return bool Entity Active
	*/
	bool GetActive() const;
	/**
	*@brief	This Entity Children to Registration
	*@param[in] Entity* child Children
	*/
	void SetChildren(Entity* child);
	/**
	*@brief Get Entity State
	*@param[in] Entity* entity this
	*@return int EntityStateCount
	*/
	static int GetStateCount(Entity* entity);
	/**
	*@brief	Entity Destroy
	*@param[in] Entity* entity this
	*/
	static void Destroy(Entity* entity);
	/**
	*@brief	Entity Update
	*@param[in] Entity* entity this
	*/
	static void Update(Entity* entity);
	/**
	*@brief	Entity Enter
	*@param[in] Entity* entity this
	*/
	static void Enter(Entity* entity);
	/**
	*@brief	Entity Children Update
	*@parma[in] Entity* entity this
	*/
	static void ChildrenUpdate(Entity* entity);
	/**
	*@brief	Entity Children Kill Check
	*@param[in] Entity* entity this
	*/
	static void ChildrenStateAdaptation(Entity* entity);
	/**
	*@brief	Entity Delete
	*/
	void Destroy();
	/**
	*@brief Get Children Count
	*@return size_t This Children Size
	*/
	size_t ChildCount() const;
	/**
	*@brief	Get Children
	*@param[in] size_t num Children Number
	*@return Entity* Children
	*/
	Entity* GetChild(const size_t num);
	/**
	*@brief Get Childrens
	*@return std::vector<Entity*>* All Children
	*/
	std::vector<Entity*>* GetChilds();
	/**
	*@brief	Get Children
	*@tparam T assignment class
	*@return T* assignment class Children
	*@detail ‘¶İ‚µ‚È‚¢ê‡‚Ínullptr‚ğ•Ô‚·
	*@detail “o˜^‚µ‚Ä‚¢‚é‚à‚Ì‚Æ“o˜^—\’è‚Ì‚à‚Ì‚©‚çŒŸõ‚·‚é
	*/
	template <class T> T* GetChild()
	{
		return Entity::GetChildren<T>(&this->childs);
	}
};