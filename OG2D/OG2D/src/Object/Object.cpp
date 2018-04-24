#include "Object.h"
GameObject::GameObject() {
	this->Gravity = false;
	this->angle = 0.f;
	this->objform = Objform::Non;
	this->CollisionProcess = nullptr;
	this->mass = 0.f;
}
GameObject::GameObject(Objform form, Vec2 _posi, Vec2 _Sca, float _ang)
{
	this->objform = form;
	switch (objform)
	{
	case Objform::Cube:
		this->position = _posi;
		this->Scale = _Sca;
		break;
	case Objform::Ball:
		this->position = _posi;
		this->Scale = _Sca;
		break;
	}
	this->angle = _ang;
}
GameObject::~GameObject()
{

}
void GameObject::CreateObject(Objform form, Vec2 _posi, Vec2 _Sca, float _ang) 
{
	this->objform = form;
	switch (objform)
	{
	case Objform::Cube:
		this->position = _posi;
		this->Scale = _Sca;
		break;
	case Objform::Ball:
		this->position = _posi;
		this->Scale = _Sca;
		break;
	}
	this->angle = _ang;
}
bool GameObject::hit(GameObject o)
{
	switch (this->objform)
	{
	case Objform::Cube:
		this->collisionCube.hitBase = {
			this->position.x,
			this->position.y,
			this->Scale.x + this->position.x,
			this->Scale.y + this->position.y };
		this->collisionCube.Rotate(this->angle);
		switch (o.objform)
		{
		case Objform::Cube:
			o.collisionCube.hitBase = {
				o.position.x,
				o.position.y,
				o.Scale.x + o.position.x,
				o.Scale.y + o.position.y};
			o.collisionCube.Rotate(o.angle);
			return this->collisionCube.hitBox(o.collisionCube);
			break;
		case Objform::Ball:
			o.collisionBall.hitBase = {
				o.Scale.x,
				o.position.x,
				o.position.y };
			return this->collisionCube.hitCircle(o.collisionBall);
			break;
		}
		break;
	case Objform::Ball:
		this->collisionBall.hitBase = {
			this->Scale.x,
			this->position.x,
			this->position.y };
		switch (o.objform)
		{
		case Objform::Cube:
			o.collisionCube.hitBase = {
				o.position.x,
				o.position.y,
				o.Scale.x + o.position.x,
				o.Scale.y + o.position.y };
			o.collisionCube.Rotate(o.angle);
			return this->collisionBall.hitBox(o.collisionCube);
			break;
		case Objform::Ball:
			o.collisionBall.hitBase = {
				o.Scale.x,
				o.position.x,
				o.position.y };
			return this->collisionBall.hitCircle(o.collisionBall);
			break;
		}
		break;
	}
	return false;
}

void GameObject::LineDraw()
{
	switch (this->objform)
	{
	case Objform::Cube:
	{
		this->collisionCube.hitBase = {
			this->position.x,
			this->position.y,
			this->Scale.x + this->position.x,
			this->Scale.y + this->position.y
		};
		this->collisionCube.Rotate(this->angle);
		Vec2 _v[4] = {
		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.y },
		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.y },
		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.h - 1 },
		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.h - 1 }
		};
		OG::_Rotate(this->collisionCube.angle, _v);
		OG::LineHitDraw(_v);
		break;
	}
	case Objform::Ball:
		break;
	case Objform::Non:
		break;
	}
}