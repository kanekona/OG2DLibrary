#include "Framework.h"
#include "OG\OGlib.h"
Framework::Framework(bool* destroy)
{
	this->sceneManager = nullptr;
	this->enableEngineDestroy = destroy;
	//Window¶¬
	this->window = new Window();
}
Framework::~Framework()
{
	this->enableEngineDestroy = nullptr;
	delete this->sceneManager;
	delete this->window;
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
	this->sceneManager->ChangeScene(next);
}
Scene* Framework::GetScene()
{
	return this->sceneManager->Get();
}
void Framework::Update()
{
	this->sceneManager->SceneUpdate();
}
Window* Framework::GetWindow()
{
	return this->window;
}
void Framework::EngineDestroy()
{
	*this->enableEngineDestroy = false;
}
void Framework::CreateSceneManager(Scene* begin)
{
	if (this->sceneManager == nullptr)
	{
		sceneManager = new SceneManager(begin);
	}
}