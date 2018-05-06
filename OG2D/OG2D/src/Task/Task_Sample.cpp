#include "Task_Sample.h"
#include "Task_Sample2.h"
#include "TestObject.h"
bool Sample::Initialize()
{
	std::cout << "Sample:" << "Initialize()" << std::endl;
	__super::Init(taskName);
	auto testObject = TestObject::Create(true);
	return true;
}

void Sample::UpDate()
{
	auto test = OGge->GetTask<TestObject>("TestObject");
	if (test != nullptr)
	{
		test->TestCheck();
	}
	if (OGge->in.key.down(In::SPACE))
	{
		this->Kill();
	}
}

void Sample::Render2D()
{
	//std::cout << "Sample:" << "Render2D()" << std::endl;
}

bool Sample::Finalize()
{
	std::cout << "Sample:" << "Finalize()" << std::endl;
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		this->Kill(false);
		auto nextTask = Sample2::Create(true);
	}
	return true;
}

Sample::Sample()
{
	std::cout << "Sample:" << "TaskObject()" << std::endl;
}

Sample::~Sample()
{
	std::cout << "Sample:" << "~TaskObject()" << std::endl;
	this->Finalize();
}

Sample::SP Sample::Create(bool flag_)
{
	std::cout << "Sample:" << "Create()" << std::endl;
	Sample::SP to = Sample::SP(new Sample());
	if (to)
	{
		to->me = to;
		if (flag_)
		{
			OGge->SetTaskObject(to);
		}
		if (!to->Initialize())
		{
			to->Kill();
		}
		return to;
	}
	return nullptr;
}