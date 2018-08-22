#include "Task_Sample.h"
#include "Task_Sample2.h"
#include "TestObject.h"
bool Sample::Initialize()
{
	__super::Init("Sample");
	auto testObject = TestObject::Create(true);
	TestObject::Create(false);
	__super::SetDrawOrder(0.0f);
	return true;
}

void Sample::UpDate()
{
	if (OGge->in->EitherDown())
	{
		std::cout << "down\n";
	}
	if (OGge->in->EitherOn())
	{
		std::cout << "on\n";
	}
	if (OGge->in->EitherUp())
	{
		std::cout << "up\n";
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