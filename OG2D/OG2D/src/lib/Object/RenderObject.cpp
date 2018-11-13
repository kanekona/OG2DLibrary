#include "RenderObject.h"

void RenderObject::Render2D()
{

}
void RenderObject::SetDrawOrder(const unsigned int order_)
{
	this->order = order_;
}
unsigned int RenderObject::GetDrawOrder() const
{
	return this->order;
}
OG::Mode RenderObject::GetMode() const
{
	return this->mode;
}
bool RenderObject::ModeCheck(const OG::Mode& mode) const
{
	return this->mode == mode;
}