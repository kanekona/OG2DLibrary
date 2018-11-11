#include "TestObject.h"
#include "State\TestState.h"
TestObject::TestObject(const std::string& tag)
{
	this->tex.Push("kiri0", rm->GetTextureData("kiri0"));
	this->tex.Push("kiri1", rm->GetTextureData("kiri1"));
	this->tex.Push("kiri2", rm->GetTextureData("kiri2"));
	this->tex.Push("kiri3", rm->GetTextureData("kiri3"));
	this->tex.Get("kiri0")->order = 0;
	this->tex.Get("kiri1")->order = 1;
	this->tex.Get("kiri2")->order = 1;
	this->tex.Get("kiri3")->order = 1;
	this->tex.Get("kiri1")->color.alpha = 1.f;
	this->tex.Get("kiri2")->color.alpha = 0.f;
	this->tex.Get("kiri3")->color.alpha = 0.f;
	this->tex.SetDrawOrder();
	__super::SetDrawOrder(1);
	mode = Mode::WAIT;
	premode = Mode::WAIT;
	this->timeCnt = 0;
	this->maxTime = random::GetRand(50, 150);
	__super::SetTag(tag);
	this->sm = new StateManager("test", new TestState(this,"test"));
	this->sm->SetState("test1", new Test2State(this,"test1"));
	this->sm->SetState("test2", new Test3State(this,"test2"));
	this->sm->SetState("test3", new Test4State(this, "test3"));
}
TestObject::~TestObject()
{
	OG::Destroy<StateManager>(this->sm);
}
void TestObject::Update()
{
	//switch (mode)
	//{
	//case Mode::DOWN_0:
	//	/*this->tex.Get("kiri1")->color.alpha -= 0.1f;
	//	this->tex.Get("kiri2")->color.alpha = 1.f - this->tex.Get("kiri1")->color.alpha;*/
	//	
	//	/*if (this->tex.Get("kiri1")->color.alpha <= 0.0f)
	//	{
	//		mode = Mode::DOWN_1;
	//	}*/
	//	if (this->timeCnt > 5)
	//	{
	//		mode = Mode::DOWN_1;
	//		this->tex.Get("kiri2")->color.alpha = 0.f;
	//		this->tex.Get("kiri3")->color.alpha = 1.f;
	//	}
	//	break;
	//case Mode::DOWN_1:
	//	/*this->tex.Get("kiri2")->color.alpha -= 0.1f;
	//	this->tex.Get("kiri3")->color.alpha = 1.f - this->tex.Get("kiri2")->color.alpha;*/
	//	/*if (this->tex.Get("kiri2")->color.alpha <= 0.0f)
	//	{
	//		mode = Mode::UP_0;
	//	}*/
	//	if (this->timeCnt > 5)
	//	{
	//		mode = Mode::UP_0;
	//		this->tex.Get("kiri2")->color.alpha = 1.f;
	//		this->tex.Get("kiri3")->color.alpha = 0.f;
	//	}
	//	break;
	//case Mode::UP_0:
	//	/*this->tex.Get("kiri2")->color.alpha += 0.1f;
	//	this->tex.Get("kiri3")->color.alpha = 1.f - this->tex.Get("kiri2")->color.alpha;*/
	//	/*if (this->tex.Get("kiri2")->color.alpha >= 1.0f)
	//	{
	//		mode = Mode::UP_1;
	//	}*/
	//	if (this->timeCnt > 5)
	//	{
	//		mode = Mode::UP_1;
	//		this->tex.Get("kiri1")->color.alpha = 1.0f;
	//		this->tex.Get("kiri2")->color.alpha = 0.0f;
	//	}
	//	break;
	//case Mode::UP_1:
	//	/*this->tex.Get("kiri1")->color.alpha += 0.1f;
	//	this->tex.Get("kiri2")->color.alpha = 1.f - this->tex.Get("kiri1")->color.alpha;*/
	//	/*if (this->tex.Get("kiri1")->color.alpha >= 1.0f)
	//	{
	//		mode = Mode::WAIT;
	//	}*/
	//	if (this->timeCnt > 5)
	//	{
	//		mode = Mode::WAIT;
	//	}
	//	break;
	//case Mode::WAIT:
	//	if (this->timeCnt >= maxTime)
	//	{
	//		mode = Mode::DOWN_0;
	//		this->tex.Get("kiri1")->color.alpha = 0.f;
	//		this->tex.Get("kiri2")->color.alpha = 1.f;
	//		this->maxTime = random::GetRand(50, 150);
	//	}
	//	break;
	//}
	//this->timeCnt++;
	//if (mode != premode)
	//{
	//	this->timeCnt = 0;
	//	premode = mode;
	//}
	this->sm->Update();
}
void TestObject::Render2D()
{
	Box2D draw(ge->camera->GetPos().x + (ge->camera->GetSize().x / 4 * 3), ge->camera->GetPos().y + ge->camera->GetSize().y - (196.f * 5.f / 2.f), 196.f * 4.f, 196.f * 5.f);
	this->tex.Draw(draw);
}
LayerTexture* TestObject::GetLayerData()
{
	return &this->tex;
}