#include "SceneManager.h"

void SceneManager::ChangeScene(Scene* next)
{
	this->nextScene = next;
}
void SceneManager::SceneUpdate()
{
	Scene::EntityUpdate(nowScene);
}
void SceneManager::ChangeAdaptation()
{
	if (nextScene != nullptr)
	{
		delete nowScene;
		nowScene = nextScene;
		nowScene->Enter();
		nextScene = nullptr;
	}
}
Scene* SceneManager::Get()
{
	return this->nowScene;
}