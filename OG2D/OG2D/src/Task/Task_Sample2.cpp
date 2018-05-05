#include "Task_Sample2.h"
#include "Task_Sample.h"

bool Sample2::Initialize()
{
	std::cout << "Sample2:" << "Initialize()" << std::endl;
	__super::Init(taskName);
	return true;
}

void Sample2::UpDate()
{
	//std::cout << "Sample2:" << "UpDate()" << std::endl;
	if (OGge->in.key.down(In::SPACE))
	{
		this->Kill();
	}
}

void Sample2::Render2D()
{
	//std::cout << "Sample2:" << "Render2D()" << std::endl;
}

bool Sample2::Finalize()
{
	std::cout << "Sample2:" << "Finalize()" << std::endl;
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		auto nextTask = Sample::Create(true);
		this->Kill();
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

Sample2::SP Sample2::Create(bool flag_)
{
	std::cout << "Sample2:" << "Create()" << std::endl;
	Sample2::SP to = Sample2::SP(new Sample2());
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