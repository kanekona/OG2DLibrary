#include "Task_Sample.h"
#include "Task_Sample2.h"
#include "TestObject.h"
bool Sample::Initialize()
{
	std::cout << "Sample:" << "Initialize()" << std::endl;
	__super::Init(taskName);
	auto testObject = TestObject::Create(true);
	this->testImg.Create((std::string)"back.png");
	this->SetDrawOrder(1.0f);
	return true;
}

void Sample::UpDate()
{
	if (OGge->in->key.down(In::SPACE))
	{

		auto test = OGge->GetTask<TestObject>("TestObject");
		if (test != nullptr)
		{
			test->SetDrawOrder(1.0f);
		}
		this->Kill();
	}
}

void Sample::Render2D()
{
	//std::cout << "Sample:" << "Render2D()" << std::endl;
	this->testImg.Draw(Box2D(0, 0, 960, 540), Box2D(0, 0, 1080, 720));
}

bool Sample::Finalize()
{
	std::cout << "Sample:" << "Finalize()" << std::endl;
	this->testImg.Finalize();
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