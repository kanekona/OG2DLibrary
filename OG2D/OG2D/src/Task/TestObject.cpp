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
		this->CreateObject(Cube, Vec2(200, 200), Vec2(128, 128));
	}
	else
	{
		__super::Init("testobj");
		this->CreateObject(Cube, Vec2(200, 200), Vec2(128, 128));
	}
	
	//this->sampleImage.Create("Collision.png");
	//rm->SetTextureData("test",&sampleImage);
	rm->CreateTexture("test", "Collision.png");
	this->SetDrawOrder(1.0f);
	this->Radius = { 0.8f,0.5f };
	this->isHit = false;
	return true;
}
void TestObject::UpDate()
{
	if (OGge->in->key.down(In::Z))
	{
		this->Kill();
	}
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
	return true;
}

void TestObject::Render2D()
{
	//std::cout << "TestObject:" << "Render2D()" << std::endl;
	Box2D draw(this->position, this->Scale);
	draw.OffsetSize();
	rm->GetTextureData("test")->Rotate(this->angle);
	if (this->isHit)
	{
		rm->GetTextureData("test")->Draw(draw, Box2D(0, 128, 128, 256), Color{ 1.f,1.f,1.f,0.3f });
	}
	else
	{
		rm->GetTextureData("test")->Draw(draw, Box2D(0, 0, 128, 128), Color{ 1.f,1.f,1.f,0.3f });
	}
	this->LineDraw();
}

bool TestObject::Finalize()
{
	std::cout << "TestObject:" << "Finalize()" << std::endl;
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		
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

TestObject::SP TestObject::Create(bool is_move_,bool flag_)
{
	std::cout << "TestObject:" << "Create()" << std::endl;
	TestObject::SP to = TestObject::SP(new TestObject(is_move_));
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