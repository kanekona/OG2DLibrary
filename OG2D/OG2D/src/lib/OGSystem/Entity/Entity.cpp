#include "Entity.h"

Entity::Entity()
{
	this->active = true;
	this->stateCount = KL_ENTITY_NORMAL;
}
Entity::~Entity()
{
	//Žq‚Ì‰ð•ú
	for (auto id : this->childs)
	{
		delete id;
	}
	this->childs.clear();
}
void Entity::Update()
{

}
void Entity::Enter()
{

}
void Entity::Destroy()
{
	this->stateCount = KL_ENTITY_KILL;
}
void Entity::SetActive(const bool isActive)
{
	this->active = isActive;
}
bool Entity::GetActive() const
{
	return this->active;
}
void Entity::RegisterChildren()
{
	for (auto id : plansChilds)
	{
		childs.emplace_back(id);
		id->Enter();

		id->RegisterChildren();
	}
	plansChilds.clear();
}
void Entity::KillChildren()
{
	for (auto id = childs.begin(); id != childs.end();)
	{
		if (Entity::GetStateCount(*id) == KL_ENTITY_KILL)
		{
			delete *id;
			id = childs.erase(id);
		}
		else
		{
			//Ä‹N‚ÅŽq‚ÌŽq‚ðíœ‚·‚é
			(*id)->KillChildren();
			++id;
		}
	}
}
void Entity::SetChildren(Entity* child)
{
	plansChilds.emplace_back(child);
}
int Entity::GetStateCount(Entity* entity)
{
	return entity->stateCount;
}
void Entity::Destroy(Entity* entity)
{
	entity->Destroy();
}
void Entity::Update(Entity* entity)
{
	if (entity->active)
	{
		entity->Update();
	}
}
void Entity::Enter(Entity* entity)
{
	entity->Enter();
}
void Entity::ChildrenUpdate(Entity* entity)
{
	for (auto id : entity->childs)
	{
		if (id->active)
		{
			Entity::Update(id);
			Entity::ChildrenUpdate(id);
		}
	}
}
void Entity::ChildrenStateAdaptation(Entity* entity)
{
	//íœ—\’è‚ðíœ
	entity->KillChildren();
	//“o˜^—\’è‚ð“o˜^
	entity->RegisterChildren();
}
size_t Entity::ChildCount() const
{
	return this->childs.size();
}
Entity* Entity::GetChild(const size_t num)
{
	return this->childs[num];
}
std::vector<Entity*>* Entity::GetChilds()
{
	return &this->childs;
}