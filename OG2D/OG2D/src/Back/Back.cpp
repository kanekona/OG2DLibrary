#include "Back.h"

Back::Back(const std::string& path)
{
	this->image = rm->GetTextureData(path);
}
Back::~Back()
{

}
void Back::Update()
{

}
void Back::Render2D()
{
	this->draw = { ge->camera->GetPos(),ge->camera->GetSize() };
	this->draw.OffsetSize();
	this->src = { Vec2(),this->image->GetTextureSize() };
	this->image->Draw(this->draw, this->src, Color(1.0f, 1.0f, 1.0f, 0.5f));
}