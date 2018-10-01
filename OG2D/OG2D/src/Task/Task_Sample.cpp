#include "Task_Sample.h"
#include "Task_Sample2.h"
#include "TestObject.h"
#include "OGSystem\Button\Button.h"
Sample::Sample()
{
	std::cout << "Sample()\n";
	OGge->SetGameObject(TestObject::Create());
	OGge->SetGameObject(Button::Create(Vec2(400, 400), Vec2(256, 128)));
}
Sample::~Sample()
{
	std::cout << "~Sample()\n";
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		OGge->SetTask(Sample2::Create());
	}
}
void Sample::Update()
{
	if (OGge->in->key.down(In::SPACE))
	{
		this->EnableGameObjectDestroy(true);
		this->Kill();
	}
}
Sample* Sample::Create()
{
	std::cout << "Sample::Create\n";
	Sample* to = new Sample();
	if (to)
	{
		return to;
	}
	return nullptr;
}