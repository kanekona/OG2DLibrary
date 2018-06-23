#include "Task_Sample.h"
#include "Task_Sample2.h"
#include "TestObject.h"
bool Sample::Initialize()
{
	std::cout << "Sample:" << "Initialize()" << std::endl;
	__super::Init(taskName);
	auto testObject = TestObject::Create(true);
	auto testObject2 = TestObject::Create(false);
	this->testImg.Create("back.png");
	this->SetDrawOrder(0.0f);
	__super::SetDrawOrder(0.0f);
	time.Start();
	return true;
}

void Sample::Render(Texture* tex, std::shared_ptr<Sample::Param>& param)
{
	while (param->on)
	{
		//std::cout << param->cnt << std::endl;
		param->fps.Update();
		if (param->cnt > 10000)
		{
			param->cnt = 0;
		}
		param->cnt++;
		if (tex)
		{
			tex->Draw(Box2D(0, 0, 960, 540), Box2D(0.f, 0.f, tex->GetTextureSize().x, tex->GetTextureSize().y));
		}
	}
}

void Sample::UpDate()
{
	auto test = OGge->GetTasks<TestObject>("TestObject");
	if (OGge->in->key.down(In::SPACE))
	{
		this->Kill();
	}
	if (OGge->in->axis(In::AXIS_LEFT_X) != 0.f)
	{
		std::cout << OGge->in->axis(In::AXIS_LEFT_X) << std::endl;
	}
	if (OGge->in->down(In::B1))
	{
		this->param->mutex.lock();
		this->param->on = false;
		this->param->mutex.unlock();
	}
}

void Sample::Pause()
{
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