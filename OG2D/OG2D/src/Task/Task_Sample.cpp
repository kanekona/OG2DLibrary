#include "Task_Sample.h"
#include "Task_Sample2.h"
#include "TestObject.h"
bool Sample::Initialize()
{
	std::cout << "Sample:" << "Initialize()" << std::endl;
	__super::Init(taskName);
	auto testObject = TestObject::Create(true);
	//auto testObject2 = TestObject::Create(false);
	this->testImg.Create("back.png");
	this->SetDrawOrder(0.0f);
	__super::SetDrawOrder(0.0f);
	time.Start();
	return true;
}

void Sample::UpDate()
{
	std::cout << "update" << std::endl;
	auto test = OGge->GetTasks<TestObject>("TestObject");
	for (auto id = (*test).begin(); id != (*test).end(); ++id)
	{
		if ((*id)->TestCheck())
		{

		}
	}
	if (OGge->in->key.down(In::SPACE))
	{
		this->Kill();
	}
	if (OGge->in->key.down(In::Z))
	{
		OGge->SetPause(true);
		time.Pause();
	}
}

void Sample::Pause()
{
	std::cout << "Puase" << std::endl;
	if (OGge->in->key.down(In::Z))
	{
		OGge->SetPause(false);
	}
}

void Sample::Render2D()
{
	
}

bool Sample::Finalize()
{
	std::cout << "Sample:" << "Finalize()" << std::endl;
	this->testImg.Finalize();
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
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