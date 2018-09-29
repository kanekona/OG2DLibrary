//#include "TestObject.h"
//
//TestObject::TestObject()
//{
//	this->isInput = false;
//	this->isHit = false;
//}
//TestObject::~TestObject()
//{
//
//}
//void TestObject::Update()
//{
//	if (this->isInput)
//	{
//		this->position.x += OGge->in->axis(In::AXIS_LEFT_X);
//		this->position.y += OGge->in->axis(In::AXIS_LEFT_Y) * -1;
//		if (OGge->in->on(In::L1))
//		{
//			this->angle -= 1.f;
//		}
//		if (OGge->in->on(In::R1))
//		{
//			this->angle += 1.f;
//		}
//		CollisionPointer cp;
//		cp.hitBase = OGge->in->mouse.GetPos();
//		this->isHit = this->collisionCube.hitPointer(cp);
//	}
//	else
//	{
//		auto test = OGge->GetTasks<TestObject>("testObject");
//		for (auto id = test.begin(); id != test.end(); ++id)
//		{
//			this->isHit = this->hit(*(*id));
//		}
//	}
//}
//void TestObject::Render2D()
//{
//	Box2D draw(this->position, this->Scale);
//	if (this->objform == Ball)
//	{
//		draw.x -= this->Scale.x / 2;
//		draw.y -= this->Scale.y / 2;
//	}
//	draw.OffsetSize();
//	Box2D src(0, 0, 128, 128);
//	if (this->isHit)
//	{
//		src.y += 128;
//	}
//	if (this->objform == Objform::Ball)
//	{
//		src.x += 128;
//	}
//	src.OffsetSize();
//	rm->GetTextureData("collision")->Rotate(this->angle);
//	rm->GetTextureData("collision")->Draw(draw, src, Color(1.f, 1.f, 1.f, 0.3f));
//	this->LineDraw();
//}
//TestObject* TestObject::Create()
//{
//	TestObject* to = new TestObject();
//	if (to)
//	{
//		OGge->SetTaskObject(to);
//		return to;
//	}
//	return nullptr;
//}