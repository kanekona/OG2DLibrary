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
}

void Sample::Render2D()
{
	std::vector<int> __y;
	for (int i = 0; i < 12; ++i)
	{
		__y.push_back(i * 32 + i * 2);
	}
	this->texfont.Draw("asdfghjkl", Vec2(0, __y[0]), 32);
	this->texfont.Draw("ASDFGHJKL", Vec2(0, __y[1]), 32);
	this->texfont.Draw("����������", Vec2(0, __y[2]), 32);
	this->texfont.Draw("����������", Vec2(0, __y[3]), 32);
	this->texfont.Draw("����������", Vec2(0, __y[4]), 32);
	this->texfont.Draw("�����Ă�", Vec2(0, __y[5]), 32);
	this->texfont.Draw("�Ȃɂʂ˂�", Vec2(0, __y[6]), 32);
	this->texfont.Draw("�͂Ђӂւ�", Vec2(0, __y[7]), 32);
	this->texfont.Draw("�܂݂ނ߂�", Vec2(0, __y[8]), 32);
	this->texfont.Draw("����", Vec2(0, __y[9]), 32);
	this->texfont.Draw("�������b��", Vec2(0, __y[10]), 32);
	this->texfont.Draw("�������", Vec2(0, __y[11]), 32);
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