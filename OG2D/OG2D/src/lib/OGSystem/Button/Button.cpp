#include "Button.h"

Button::Button(const Vec2& pos, const Vec2& size,const std::string& name)
{
	this->hitFlag = false;
	this->Init(Objform::Box, name, pos, size, 0.0f);
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
}
void Button::Render2D()
{
	*this->draw = { this->GetPosition(),this->GetScale() };
	this->draw->OffsetCenterSize();
	*this->src = { 0.f,0.f,this->image->GetTextureSize().x / 2.f,this->image->GetTextureSize().y };
	*this->image_color = { 1,1,1,1 };
	if (this->hitFlag)
	{
		*this->image_color = { 0.7f,0.7f,0.7f,1.0f };
	}
	if (ge->in->mouse->on(Mouse::LEFT) && this->hitFlag)
	{
		*this->image_color = { 0.4f,0.4f,0.4f,1.0f };
	}
	this->image->Rotate(this->GetRotate());
	this->image->Draw(*this->draw, *this->src, *this->image_color);
	this->draw->x += this->GetScale().x / 10.f;
	this->draw->y += this->GetScale().x / 10.f;
	//this->font.Draw(this->_text, Vec2(this->draw->x, this->draw->y), (int)((this->GetScale().x - (this->GetScale().x / 5.f)) / 3));
	this->font.Draw(this->_text, (float)((this->GetScale().x - (this->GetScale().x / 5.f)) / 3), Vec2(this->draw->x, this->draw->y), Color(0.0f, 0.0f, 0.0f, 1.0f));
}
bool Button::IsMouseHit() const
{
	return this->hitFlag;
}
void Button::SetText(const std::string& text)
{
	this->_text = text;
}
Button* Button::Create(const Vec2& pos, const Vec2& size,const std::string& name)
{
	Button* to = new Button(pos, size, name);
	return to;
}