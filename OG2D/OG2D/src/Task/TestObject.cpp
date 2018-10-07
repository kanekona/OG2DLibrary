#include "TestObject.h"

TestObject::TestObject()
{
	std::cout << "TestObject()\n";
	this->draw = new Box2D;
	this->src = new Box2D;
}
TestObject::~TestObject()
{
	std::cout << "~TestObject()\n";
	OG::Destroy<Box2D>(this->draw);
	OG::Destroy<Box2D>(this->src);
}
void TestObject::Update()
{
	
}
void TestObject::Render2D()
{

}
TestObject* TestObject::Create()
{
	std::cout << "TestObject::Create\n";
	TestObject* to = new TestObject();
	if (to)
	{
		return to;
	}
	return nullptr;
}