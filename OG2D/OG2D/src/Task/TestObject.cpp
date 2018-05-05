#include "TestObject.h"

bool TestObject::Initialize()
{
	std::cout << "TestObject:" << "Initialize()" << std::endl;
	__super::Init(taskName);
	this->CreateObject(Cube, Vec2(100, 100), Vec2(128, 128), 0.0f);
	this->sampleImage.Create("Collision.png");
	return true;
}
void TestObject::UpDate()
{
	//std::cout << "TestObject:" << "UpDate()" << std::endl;
	if (OGge->in.key.down(In::Z))
	{
		this->Kill();
	}
}

void TestObject::Render2D()
{
	//std::cout << "TestObject:" << "Render2D()" << std::endl;
	Box2D draw(this->position, this->Scale);
	draw.OffsetSize();
	this->sampleImage.Draw(draw, Box2D(0, 0, 128, 128));
}

bool TestObject::Finalize()
{
	std::cout << "TestObject:" << "Finalize()" << std::endl;
	this->sampleImage.Finalize();
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		this->Kill();
	}
	return true;
}

TestObject::TestObject()
{
	std::cout << "TestObject:" << "()" << std::endl;
}

TestObject::~TestObject()
{
	std::cout << "TestObject:" << "~()" << std::endl;
	this->Finalize();
}

TestObject::SP TestObject::Create(bool flag_)
{
	std::cout << "TestObject:" << "Create()" << std::endl;
	TestObject::SP to = TestObject::SP(new TestObject());
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