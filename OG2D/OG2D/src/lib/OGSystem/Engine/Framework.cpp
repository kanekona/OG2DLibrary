#include "Framework.h"
#include "OG\OGlib.h"
Framework::Framework(bool* destroy)
{
	this->enableEngineDestroy = destroy;
	//Window¶¬
	this->window->Create();
}
Framework::~Framework()
{
	this->enableEngineDestroy = nullptr;
}
Framework* Framework::Create(bool* destroy)
{
	if (Framework::instance == nullptr)
	{
		Framework::instance = new Framework(destroy);
	}
	return Framework::Get();
}
Framework* Framework::Get()
{
	return Framework::instance;
}
void Framework::Destroy()
{
	//OG::Destroy<Framework>(instance);
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}
void Framework::ChangeScene(Scene* next)
{
	this->sceneManager.ChangeScene(next);
}
Scene* Framework::GetScene()
{
	return this->sceneManager.Get();
}
void Framework::Update()
{
	this->sceneManager.SceneUpdate();
}
Window* Framework::GetWindow()
{
	return this->window;
}
void Framework::EngineDestroy()
{
	*this->enableEngineDestroy = true;
}