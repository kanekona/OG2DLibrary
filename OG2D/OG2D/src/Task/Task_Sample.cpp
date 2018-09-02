#include "Task_Sample.h"
#include "Task_Sample2.h"
#include "TestObject.h"
bool Sample::Initialize()
{
	__super::Init("Sample");
	TestObject::Create(true);
	TestObject::Create(false);
	__super::SetDrawOrder(0.0f);
	Texture("error.png");
	return true;
}

void Sample::UpDate()
{
	OGge->camera->MovePos(Vec2(OGge->in->axis(In::AXIS_LEFT_X), OGge->in->axis(In::AXIS_LEFT_Y) * -1));
}

void Sample::Render2D()
{
	std::vector<int> __y;
	for (int i = 0; i < 14; ++i)
	{
		__y.push_back(i * 64);
	}
	this->texfont.Draw("������������", Vec2(0, __y[0]), 64);
	this->texfont.Draw("�`�a�b�w�x�y", Vec2(0, __y[1]), 64);
	this->texfont.Draw("����������", Vec2(0, __y[2]), 64);
	this->texfont.Draw("�����", Vec2(0, __y[3]), 64);
	this->texfont.Draw("�A�C�E�G�I", Vec2(0, __y[4]), 64);
	this->texfont.Draw("�������", Vec2(0, __y[5]), 64);
	this->texfont.Draw("�������b��", Vec2(0, __y[6]), 64);
	this->texfont.Draw("a b c d e f g h i j k l n", Vec2(0, __y[7]), 64);
	this->texfont.Draw("m o p q r s t u v w x y z", Vec2(0, __y[8]), 64);
	this->texfont.Draw("ABCXYZ", Vec2(0, __y[9]), 64);
	this->texfont.Draw("012789", Vec2(0, __y[10]), 64);
	this->texfont.Draw("�O�P�Q�V�W�X", Vec2(0, __y[11]), 64);
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