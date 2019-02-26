#include "SceneManager.h"

void SceneManager::ChangeScene(Scene* next)
{
	this->nextScene = next;
}
void SceneManager::SceneUpdate()
{
	std::cout << "SceneManagerUpdate" << std::endl;
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