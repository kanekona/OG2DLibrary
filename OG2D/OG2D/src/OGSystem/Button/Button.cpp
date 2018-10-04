#include "Button.h"

Button::Button(const Vec2& pos, const Vec2& size)
{
	this->hitFlag = false;
	this->Init(Objform::Box, "Button1", pos, size, 0.0f);
	this->image = rm->GetTextureData("button");
	this->draw = new Box2D;
	this->src = new Box2D;
	this->image_color = new Color;
}
Button::~Button()
{
	OG::Destroy<Box2D>(this->draw);
	OG::Destroy<Box2D>(this->src);
	OG::Destroy<Color>(this->image_color);
}
void Button::Update()
{
	this->hitFlag = this->Hit(ge->in->mouse->GetCollision());
	this->SetRotate(this->GetRotate() + 1.f);
}
void Button::Render2D()
{
	*this->draw = { this->GetPosition(),this->GetScale() };
	this->draw->OffsetCenterSize();
	*this->src = { 0.f,0.f,this->image->GetTextureSize().x / 2.f,this->image->GetTextureSize().y };
	*this->image_color = { 1,1,1,1 };
	if (this->hitFlag)
	{
		*this->image_color = { 0.1f,0.1f,0.1f,1.0f };
	}
	if (ge->in->mouse->on(Mouse::LEFT))
	{
		*this->image_color = { 0.4f,0.4f,0.4f,1.0f };
	}
	this->image->Rotate(this->GetRotate());
	this->image->Draw(*this->draw, *this->src, *this->image_color);
	this->LineDistanceDraw();
	this->LineDraw();
}
Button* Button::Create(const Vec2& pos, const Vec2& size)
{
	Button* to = new Button(pos, size);
	return to;
}