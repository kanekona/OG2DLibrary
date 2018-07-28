#include "Task_Sample.h"
#include "Task_Sample2.h"
#include "TestObject.h"
bool Sample::Initialize()
{
	__super::Init("Sample");
	auto testObject = TestObject::Create(true);
	TestObject::Create(true);
	__super::SetDrawOrder(0.0f);
	return true;
}

void Sample::UpDate()
{
	auto test = OGge->GetTasks<TestObject>("TestObject");
	for (auto id = test.begin(); id != test.end(); ++id)
	{
		(*id)->TestCheck();
	}
}

void Sample::Render2D()
{
	
}

bool Sample::Finalize()
{
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
	}
	return true;
}

Sample::Sample()
{
}

Sample::~Sample()
{
	std::cout << "~Sample()" << std::endl;
 	this->Finalize();
}

Sample* Sample::Create(bool flag_)
{
	Sample* to = new Sample();
	if (to)
	{
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