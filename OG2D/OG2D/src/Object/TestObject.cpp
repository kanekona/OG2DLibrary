#include "TestObject.h"

TestObject::TestObject()
{
	this->tex.Push("kiri0", rm->GetTextureData("kiri0"));
	this->tex.Push("kiri1", rm->GetTextureData("kiri1"));
	this->tex.Get("kiri0")->order = 0;
	this->tex.Get("kiri1")->order = 1;
	this->tex.SetDrawOrder();
	__super::SetDrawOrder(1);
}
TestObject::~TestObject()
{

}
void TestObject::Update()
{

}
void TestObject::Render2D()
{
	Box2D draw(ge->camera->GetPos().x + (ge->camera->GetSize().x / 4 * 3), ge->camera->GetPos().y + ge->camera->GetSize().y - (196.f * 5.f / 2.f), 196.f * 4.f, 196.f * 5.f);
	this->tex.Draw(draw);
}