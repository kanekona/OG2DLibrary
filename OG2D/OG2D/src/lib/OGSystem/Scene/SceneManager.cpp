#include "SceneManager.h"

SceneManager::SceneManager(Scene* begin)
{
	this->nowScene = begin;
	this->nowScene->Enter();
}
void SceneManager::ChangeScene(Scene* next)
{
	this->nextScene = next;
}
void SceneManager::SceneUpdate()
{
	if (nowScene)
	{
		Scene::EntityUpdate(nowScene);
		ChangeAdaptation();
	}
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