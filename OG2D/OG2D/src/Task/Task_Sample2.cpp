#include "Task_Sample2.h"
#include "Task_Sample.h"

bool Sample2::Initialize()
{
	std::cout << "Sample2:" << "Initialize()" << std::endl;
	__super::Init(taskName);
	this->SetDrawOrder(0.5f);
	return true;
}

void Sample2::UpDate()
{
	if (OGge->in->key.down(In::SPACE))
	{
		this->Kill();
	}
}

void Sample2::Render2D()
{
	//std::cout << "Sample2:" << "Render2D()" << std::endl;
}

bool Sample2::CheckOn()
{
	return true;
}

bool Sample2::Finalize()
{
	std::cout << "Sample2:" << "Finalize()" << std::endl;
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		Sample::Create(true);
	}
	return true;
}

Sample2::Sample2()
{
	std::cout << "Sample2:" << "()" << std::endl;
}

Sample2::~Sample2()
{
	std::cout << "Sample2:" << "~()" << std::endl;
	this->Finalize();
}

Sample2* Sample2::Create(bool flag_)
{
	Sample2* to = new Sample2();
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