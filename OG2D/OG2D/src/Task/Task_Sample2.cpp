#include "Task_Sample2.h"
#include "TestObject.h"
#include "Task_Sample.h"
Sample2::Sample2()
{
	std::cout << "Sample2()\n";
}
Sample2::~Sample2()
{
	std::cout << "~Sample2()\n";
	if (this->GetNextTask() && !ge->GetDeleteEngine())
	{
		ge->SetTask(Sample::Create());
	}
}
void Sample2::Update()
{
	if (ge->in->key.down(In::SPACE))
	{
		this->EnableGameObjectDestroy(true);
		this->Kill();
	}
}
Sample2* Sample2::Create()
{
	std::cout << "Sample2::Create\n";
	Sample2* to = new Sample2();
	if (to)
	{
		return to;
	}
	return nullptr;
}