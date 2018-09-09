#include "Task_Sample.h"
#include "Task_Sample2.h"
#include "TestObject.h"
bool Sample::Initialize()
{
	__super::Init("Sample");
	TestObject::Create(true);
	TestObject::Create(false);
	__super::SetDrawOrder(0.0f);
	return true;
}

void Sample::UpDate()
{
	OGge->camera->MovePos(Vec2(OGge->in->axis(In::AXIS_LEFT_X), OGge->in->axis(In::AXIS_LEFT_Y) * -1));
}

void Sample::Render2D()
{

	Box2D draw(0, 0, 160, 90);
	Box2D src(Vec2(0, 0), rm->GetTextureData("back")->GetTextureSize());
	rm->GetTextureData("back")->Draw(draw, src);


	std::vector<int> __y;
	for (int i = 0; i < 14; ++i)
	{
		__y.push_back(i * 64);
	}
	this->texfont.Draw("‚‚‚‚ƒ‚˜‚™‚š", Vec2(0, __y[0]), 64);
	this->texfont.Draw("‚`‚a‚b‚w‚x‚y", Vec2(0, __y[1]), 64);
	this->texfont.Draw("‚ ‚¢‚¤‚¦‚¨", Vec2(0, __y[2]), 64);
	this->texfont.Draw("‚á‚ã‚å‚Á", Vec2(0, __y[3]), 64);
	this->texfont.Draw("ƒAƒCƒEƒGƒI", Vec2(0, __y[4]), 64);
	this->texfont.Draw("‚í‚î‚ï‚ð‚ñ", Vec2(0, __y[5]), 64);
	this->texfont.Draw("ƒƒƒ…ƒ‡ƒbƒ”", Vec2(0, __y[6]), 64);
	this->texfont.Draw("a b c d e f g h i j k l n", Vec2(0, __y[7]), 64);
	this->texfont.Draw("m o p q r s t u v w x y z", Vec2(0, __y[8]), 64);
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