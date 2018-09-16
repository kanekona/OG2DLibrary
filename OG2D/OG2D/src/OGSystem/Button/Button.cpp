#include "Button.h"

Button::Button(const Vec2& pos, const Vec2& size)
{
	this->collision = new GameObject;
	//”»’è‚ð¶¬
}
Button::~Button()
{
	delete this->collision;
}
GameObject* Button::GetObject() const
{
	return this->collision;
}
void Button::UpDate()
{
	
}
void Button::Render2D()
{

}