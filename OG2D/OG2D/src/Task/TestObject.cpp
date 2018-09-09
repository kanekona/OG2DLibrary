#include "TestObject.h"

TestObject::TestObject(bool flag_)
{
	this->isMove = flag_;
}

bool TestObject::Initialize()
{
	std::cout << "TestObject:" << "Initialize()" << std::endl;
	if (isMove)
	{
		__super::Init(taskName);
		this->CreateObject(Cube, Vec2(263, 458), Vec2(64, 64));
	}
	else
	{
		__super::Init("testobj");
		this->CreateObject(Cube, Vec2(1344, 512), Vec2(128, 64));
		this->angle = 0;
	}
	//rm->CreateTexture("test", "Collision.png");
	this->SetDrawOrder(1.0f);
	this->Radius = { 0.8f,0.5f };
	this->isHit = false;
	return true;
}
void TestObject::UpDate()
{
	if (this->isMove)
	{
		if (OGge->in->key.on(In::Q))
		{
			this->angle -= 1.0f;
		}
		if (OGge->in->key.on(In::E))
		{
			this->angle += 1.0f;
		}
		if (OGge->in->on(In::CU))
		{
			this->position.y -= 1.0f;
		}
		if (OGge->in->on(In::CD))
		{
			this->position.y += 1.0f;
		}
		if (OGge->in->on(In::CL))
		{
			this->position.x -= 1.0f;
		}
		if (OGge->in->on(In::CR))
		{
			this->position.x += 1.0f;
		}
		auto t = OGge->GetTask<TestObject>("testobj");
		if (t)
		{
			if (this->IsObjectDistanceCheck(t->position, t->Scale))
			{
				this->isHit = this->hit(*t);
			}
		}
	}
}

bool TestObject::TestCheck()
{
	std::cout << "TestCheck()" << std::endl;
	return true;
}

void TestObject::Render2D()
{
	//std::cout << "TestObject:" << "Render2D()" << std::endl;
	Box2D draw(this->position, this->Scale);
	draw.OffsetSize();
	rm->GetTextureData("collision")->Rotate(this->angle);
	if (this->isHit)
	{
		rm->GetTextureData("collision")->Draw(draw, Box2D(0, 128, 128, 256), Color{ 1.f,1.f,1.f,0.3f });
	}
	else
	{
		rm->GetTextureData("collision")->Draw(draw, Box2D(0, 0, 128, 128), Color{ 1.f,1.f,1.f,0.3f });
	}
	this->LineDraw();
}

TestObject::TestObject()
{
	std::cout << "TestObject:" << "()" << std::endl;
}

TestObject::~TestObject()
{
	std::cout << "TestObject:" << "~()" << std::endl;
}

TestObject* TestObject::Create(bool is_move_,bool flag_)
{
	TestObject* to = new TestObject(is_move_);
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