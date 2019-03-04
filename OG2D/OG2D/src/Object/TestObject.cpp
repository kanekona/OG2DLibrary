#include "TestObject.h"
#include "ResourceManager\ResourceManager.h"
#include "State\TestState.h"
TestObject::TestObject(const std::string& tag)
{
	this->tex.Push("kiri0", ResourceManager::Get()->GetTextureData("kiri0"));
	this->tex.Push("kiri1", ResourceManager::Get()->GetTextureData("kiri1"));
	this->tex.Push("kiri2", ResourceManager::Get()->GetTextureData("kiri2"));
	this->tex.Push("kiri3", ResourceManager::Get()->GetTextureData("kiri3"));
	this->tex.Get("kiri0")->order = 0;
	this->tex.Get("kiri0")->color.alpha = 1.0f;
	this->tex.Get("kiri1")->order = 1;
	this->tex.Get("kiri2")->order = 1;
	this->tex.Get("kiri3")->order = 1;
	this->tex.Get("kiri1")->color.alpha = 1.f;
	this->tex.Get("kiri2")->color.alpha = 0.f;
	this->tex.Get("kiri3")->color.alpha = 0.f;
	this->tex.SetDrawOrder();
	this->sm = new StateManager("test", new TestState(this,"test"));
	this->sm->SetState("test1", new Test2State(this,"test1"));
	this->sm->SetState("test2", new Test3State(this,"test2"));
	this->sm->SetState("test3", new Test4State(this,"test3"));
}
TestObject::~TestObject()
{
	OG::Destroy<StateManager>(this->sm);
}
void TestObject::Update()
{
	//this->sm->Update();

}
//void TestObject::Render2D()
//{
//	Box2D draw(ge->camera->GetPos().x + (ge->camera->GetSize().x / 4 * 3), ge->camera->GetPos().y + ge->camera->GetSize().y - (196.f * 5.f / 2.f), 196.f * 4.f, 196.f * 5.f);
//	this->tex.Draw(draw);
//}
LayerTexture* TestObject::GetLayerData()
{
	return &this->tex;
}