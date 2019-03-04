#pragma once
#include "Entity\Entity.h"
#include "RenderingManager\RenderingManager.h"
#include "Camera\Camera.h"
#include <typeinfo>
class Scene : private NonCopyable
{
	//! AllEntity
	std::vector<Entity*> entitys;
	//! Plans Entity
	std::vector<Entity*> plansEntity;
	//! RenderingManager
	RenderingManager renderingManager;
	//! MainCamera
	Camera2D* camera;
	//! 
	/**
	*@brief	Register registration schedule
	*/
	void RegisterEntity();
	/**
	*@brief	Kill Plans Kills
	*/
	void KillEntity();
public:
	//! tag
	std::string tag;
	/**
	*@brief constructor
	*/
	explicit Scene();
	/**
	*@brief	destructor
	*/
	virtual ~Scene();
	/**
	*@brief Scene Enter
	*/
	virtual void Enter();
	/**
	*@brief	Registration Entity
	*/
	void SetEntity(Entity* entity);
	/**
	*@brief	Get RenderingManager
	*@return RenderingManager this RenderingManager
	*/
	RenderingManager GetRenderingManager();
	/**
	*@brief	Get Camera
	*@return Camera2D* template Scene Camera
	*/
	Camera2D* GetCamera();
	/**
	*@brief	Get Entity Count
	*@return size_t This Entity Size
	*/
	size_t EntityCount() const;
	/**
	*@brief	Get Entity
	*@param[in] size_t num Entity Number
	*@return Entity* entity
	*/
	Entity* GetEntity(const size_t num);
	/**
	*@brief	Get Entitys
	*@return std::vector<Entity*>* All Entity
	*/
	std::vector<Entity*>* GetEntitys();
	/**
	*@brief	Get Entity
	*@tparam T assignment class
	*@return T* assignment class Entity
	*@detail ‘¶İ‚µ‚È‚¢ê‡‚Ínullptr‚ğ•Ô‚·
	*@detail “o˜^‚µ‚Ä‚¢‚é‚à‚Ì‚Æ“o˜^—\’è‚Ì‚à‚Ì‚©‚çŒŸõ‚·‚é
	*/
	template <class T> T* GetEntity()
	{
		for (auto it : entitys)
		{
			if ((typeid(T) == typeid(*it)))
			{
				return static_cast<T*>(it);
			}
		}
		for (auto it : plansEntity)
		{
			if ((typeid(T) == typeid(*it)))
			{
				return static_cast<T*>(it);
			}
		}
		return nullptr;
	}
	/**
	*@brief	Get Entity
	*@tparam T Assigment Class
	*@param std::string tag Assigment Tag
	*@return T* Assigment Tag Class Entity
	*@detail ‘¶İ‚µ‚È‚¢ê‡‚Ínullptr‚ğ•Ô‚·
	*@detail “o˜^‚µ‚Ä‚¢‚é‚à‚Ì‚Æ“o˜^—\’è‚Ì‚à‚Ì‚©‚çŒŸõ‚·‚é
	*/
	template <class T> T* GetEntity(const std::string& tag)
	{
		for (auto it : entitys)
		{
			if (it->tag == tag)
			{
				return static_cast<T*>(it);
			}
		}
		for (auto it : plansEntity)
		{
			if (it->tag == tag)
			{
				return static_cast<T*>(it);
			}
		}
		return nullptr;
	}
	/**
	*@brief	Entity State Chenge Adaptation
	*@param[in] Scene* scene this
	*/
	static void EntityStateAdaptation(Scene* scene);
	/**
	*@brief	Entitys Update
	*@param[in] Scene* scene this
	*/
	static void EntityUpdate(Scene* scene);
};