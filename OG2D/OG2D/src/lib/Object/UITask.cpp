#include "UITask.h"
#include "OG\OGsystem.h"
UIObject::UIObject()
{
	this->_angle = 0.f;
	this->ResetData();
}
UIObject::UIObject(const std::string& tag, const Vec2& pos, const Vec2& scale, const float angle)
{
	this->Init(tag, pos, scale, angle);
}
UIObject::~UIObject()
{

}
void UIObject::ResetData()
{
	this->_order = 0;
	this->_mode = UO::Mode::NORMAL;
}
void UIObject::Init(const std::string& tag, const Vec2& pos, const Vec2& scale, const float angle)
{
	this->ResetData();
	this->_tag = tag;
	this->_position = pos;
	this->_scale = scale;
	this->_angle = angle;
}
void UIObject::Update()
{

}
void UIObject::Render2D()
{

}
void UIObject::Pause()
{

}
void UIObject::UpdateManager()
{
	switch (this->_mode)
	{
	case UO::Mode::NORMAL:
		this->Update();
		break;
	case UO::Mode::PAUSE:
		this->Pause();
		break;
	default:
		break;
	}
}
void UIObject::RenderManager()
{
	switch (this->_mode)
	{
	case UO::Mode::NORMAL:
	case UO::Mode::PAUSE:
	case UO::Mode::STOP:
		this->Render2D();
		break;
	default:
		break;
	}
}
void UIObject::SetPosition(const Vec2& pos)
{
	this->_position = pos;
}
void UIObject::SetPosition(const float x, const float y)
{
	this->_position = { x,y };
}
Vec2 UIObject::GetPosition()
{
	return this->_position + ge->camera->GetPos();
}
void UIObject::SetScale(const Vec2& scale)
{
	this->_scale = scale;
}
void UIObject::SetScale(const float x, const float y)
{
	this->_scale = { x,y };
}
Vec2 UIObject::GetScale() const
{
	return this->_scale;
}
void UIObject::SetRotate(const float angle)
{
	this->_angle = angle;
}
float UIObject::GetRotate() const
{
	return this->_angle;
}
void UIObject::SetTag(const std::string& tag)
{
	this->_tag = tag;
}
std::string UIObject::GetTag() const
{
	return this->_tag;
}
void UIObject::Kill()
{
	this->_mode = UO::Mode::KILL;
}
void UIObject::CancelKill()
{
	this->_mode = UO::Mode::NORMAL;
}
void UIObject::SetPause(const bool flag)
{
	//íœó‘Ô‚ÍÅ—Dæ‚Ì‚½‚ß‚»‚Ìê‡‚ÍÈ‚­
	if (this->ModeCheck(UO::Mode::KILL))
	{
		return;
	}
	if (flag)
	{
		this->_mode = UO::Mode::PAUSE;
	}
	else
	{
		this->_mode = UO::Mode::NORMAL;
	}
}
void UIObject::SetStop(const bool flag)
{
	if (this->ModeCheck(UO::Mode::KILL))
	{
		return;
	}
	if (flag)
	{
		this->_mode = UO::Mode::STOP;
	}
	else
	{
		this->_mode = UO::Mode::NORMAL;
	}
}
void UIObject::SetAllStop(const bool flag)
{
	if (this->ModeCheck(UO::Mode::KILL))
	{
		return;
	}
	if (flag)
	{
		this->_mode = UO::Mode::ALLSTOP;
	}
	else
	{
		this->_mode = UO::Mode::NORMAL;
	}
}
UO::Mode UIObject::GetMode() const
{
	return this->_mode;
}
bool UIObject::ModeCheck(const UO::Mode& mode) const
{
	return this->_mode == mode ? true : false;
}
void UIObject::SetDrawOrder(const unsigned int order)
{
	this->_order = order;
}
unsigned int UIObject::GetDrawOrder() const
{
	return this->_order;
}