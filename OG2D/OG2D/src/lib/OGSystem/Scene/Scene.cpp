#include "Scene.h"
#include "Engine\Framework.h"
Scene::Scene()
{
	camera = new Camera2D(Box2D(Vec2(), Framework::Get()->GetWindow()->GetSize()));
}
Scene::~Scene()
{
	for (auto id : entitys)
	{
		OG::Destroy<Entity>(id);
	}
	entitys.clear();
	for (auto id : plansEntity)
	{
		OG::Destroy<Entity>(id);
	}
	plansEntity.clear();
	OG::Destroy<Camera2D>(camera);
}
void Scene::Enter()
{

}
void Scene::SetEntity(Entity* entity)
{
	this->plansEntity.emplace_back(entity);
}
void Scene::RegisterEntity()
{
	for (auto id : plansEntity)
	{
		//“o˜^—\’è‚ð“o˜^‚·‚é
		entitys.emplace_back(id);
		Entity::Enter(id);
	}
	//“o˜^—\’è—“‚ðƒŠƒZƒbƒg
	plansEntity.clear();
}
void Scene::KillEntity()
{
	for (auto id = entitys.begin(); id != entitys.end();)
	{
		if (Entity::GetStateCount(*id) == KL_ENTITY_KILL)
		{
			delete *id;
			*id = nullptr;
			id = entitys.erase(id);
		}
		else
		{
			++id;
		}
	}
}
RenderingManager Scene::GetRenderingManager()
{
	return this->renderingManager;
}
Camera2D* Scene::GetCamera()
{
	return this->camera;
}
void Scene::EntityStateAdaptation(Scene* scene)
{
	//íœ—\’è‚ðíœ
	scene->KillEntity();
	//“o˜^—\’è‚ð“o˜^
	scene->RegisterEntity();
}
void Scene::EntityUpdate(Scene* scene)
{
	//Entity Update
	for (auto id : scene->entitys)
	{
		Entity::Update(id);
		Entity::ChildrenUpdate(id);
	}
	//Camera Update
	scene->camera->Update();
	//Rendering
	RenderingManager::Render(&scene->renderingManager);
	//Entity State Check
	for (auto it : scene->entitys)
	{
		Entity::ChildrenStateAdaptation(it);
	}
	//Rendering State Check
	RenderingManager::AllSpriteAdaptation(&scene->renderingManager);
}
size_t Scene::EntityCount() const
{
	return this->entitys.size();
}
Entity* Scene::GetEntity(const size_t num)
{
	return this->entitys[num];
}
std::vector<Entity*>* Scene::GetEntitys()
{
	return &this->entitys;
}