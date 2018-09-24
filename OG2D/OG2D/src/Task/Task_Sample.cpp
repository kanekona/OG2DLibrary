#include "Task_Sample.h"
#include "TestObject.h"
Sample::Sample()
{
	auto test1 = TestObject::Create();
	test1->isInput = true;
	test1->Init("testObject");
	test1->CreateObject(Cube, Vec2(100, 100), Vec2(128, 64), 0.0f);
	auto test2 = TestObject::Create();
	test2->CreateObject(Cube, Vec2(200, 400), Vec2(64, 256), 46.0f);
	auto test3 = TestObject::Create();
	test3->CreateObject(Ball, Vec2(200, 100), Vec2(128, 128), 0.0f);
	auto test4 = TestObject::Create();
	test4->CreateObject(Line, Vec2(300, 300), Vec2(400, 400), 0.0f);
}
Sample::~Sample()
{

}
void Sample::Update()
{

}
void Sample::Render2D()
{
}
Sample* Sample::Create()
{
	Sample* to = new Sample();
	if (to)
	{
		OGge->SetTaskObject(to);
		return to;
	}
	return nullptr;
}