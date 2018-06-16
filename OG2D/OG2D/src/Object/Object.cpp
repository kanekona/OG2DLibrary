#include "Object.h"
GameObject::GameObject() {
	//�e�ϐ��̏�����
	this->Gravity = false;
	this->angle = 0.f;
	this->objform = Objform::Non;
	this->mass = 0.f;
	this->Radius = { 1.0f,1.0f };
	this->isCheck = false;
}
GameObject::GameObject(const Objform& form,const Vec2& _posi,const  Vec2& _Sca,const float _ang)
{
	//�e�l���Z�b�g����
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
	this->CheckON();
}
GameObject::~GameObject()
{

}
void GameObject::CreateObject(const Objform& form, const Vec2& _posi, const  Vec2& _Sca, const float _ang)
{
	//�e�l���Z�b�g����
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
	this->CheckON();
}
bool GameObject::hit(GameObject& o)
{
	if (!this->isCheck || !o.isCheck)
	{
		return false;
	}
	switch (this->objform)
	{
	case Objform::Cube:			//��������`�̎�
	{
		Vec2 ScaleSize = { this->Scale.x * this->Radius.x,this->Scale.y * this->Radius.y };
		//�����蔻��𐶐�����
		this->collisionCube.hitBase = {
			this->position.x + ((this->Scale.x - ScaleSize.x) / 2),
			this->position.y + ((this->Scale.y - ScaleSize.y) / 2),
			ScaleSize.x + (this->position.x + ((this->Scale.x - ScaleSize.x) / 2)),
			ScaleSize.y + (this->position.y + ((this->Scale.y - ScaleSize.y) / 2))
		};
		//��]�l��K�p������
		this->collisionCube.Rotate(this->angle);
		switch (o.objform)
		{
		case Objform::Cube:		//���肪��`�̎�
		{
			Vec2 ScaleSize_o = { o.Scale.x * o.Radius.x,o.Scale.y * o.Radius.y };
			//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
			o.collisionCube.hitBase = {
				o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2),
				o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2),
				ScaleSize_o.x + (o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2)),
				ScaleSize_o.y + (o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2))
			};
			//��]�l��K�p������
			o.collisionCube.Rotate(o.angle);
			//Collision���̔�����g�p���Ă��̌��ʂ�Ԃ�
			return this->collisionCube.hitBox(o.collisionCube);
			break;
		}
		case Objform::Ball:		//���肪�~�̎�
		{
			//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
			o.collisionBall.hitBase = {
				o.Scale.x,
				o.position.x,
				o.position.y };
			//Collision���̔�����g�p���Ă��̌��ʂ�Ԃ�
			return this->collisionCube.hitCircle(o.collisionBall);
			break;
		}
		}
	}
		break;
	case Objform::Ball:			//�������~�̎�
	{
		//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
		this->collisionBall.hitBase = {
			this->Scale.x,
			this->position.x,
			this->position.y };
		switch (o.objform)
		{
		case Objform::Cube:		//���肪��`�̎�
		{
			Vec2 ScaleSize_o = { o.Scale.x * o.Radius.x,o.Scale.y * o.Radius.y };
			//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
			o.collisionCube.hitBase = {
				o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2),
				o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2),
				ScaleSize_o.x + (o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2)),
				ScaleSize_o.y + (o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2))
			};
			o.collisionCube.Rotate(o.angle);
			//Collision���̔�����g�p���Ă��̌��ʂ�Ԃ�
			return this->collisionBall.hitBox(o.collisionCube);
			break;
		}
		case Objform::Ball:		//���肪�~�̎�
		{
			//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
			o.collisionBall.hitBase = {
				o.Scale.x,
				o.position.x,
				o.position.y };
			//Collision���̔�����g�p���Ă��̌��ʂ�Ԃ�
			return this->collisionBall.hitCircle(o.collisionBall);
			break;
		}
		}
		break;
	}
	}
	return false;
}
bool GameObject::CubeHit(GameObject &o)
{
	if (this->objform != Objform::Cube || o.objform != Objform::Cube)
	{
		return false;
	}
	Vec2 ScaleSize = { this->Scale.x * this->Radius.x,this->Scale.y * this->Radius.y };
	//�����蔻��𐶐�����
	this->collisionCube.hitBase = {
		this->position.x + ((this->Scale.x - ScaleSize.x) / 2),
		this->position.y + ((this->Scale.y - ScaleSize.y) / 2),
		ScaleSize.x + (this->position.x + ((this->Scale.x - ScaleSize.x) / 2)),
		ScaleSize.y + (this->position.y + ((this->Scale.y - ScaleSize.y) / 2))
	};
	Vec2 ScaleSize_o = { o.Scale.x * o.Radius.x,o.Scale.y * o.Radius.y };
	//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
	o.collisionCube.hitBase = {
		o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2),
		o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2),
		ScaleSize_o.x + (o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2)),
		ScaleSize_o.y + (o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2))
	};
	if (this->collisionCube.hitBase.x < o.collisionCube.hitBase.w &&
		this->collisionCube.hitBase.w > o.collisionCube.hitBase.x &&
		this->collisionCube.hitBase.y < o.collisionCube.hitBase.h &&
		this->collisionCube.hitBase.h > o.collisionCube.hitBase.y)
	{
		return true;
	}
	return false;
}

void GameObject::LineDraw()
{
	switch (this->objform)
	{
	case Objform::Cube:		//��������`�̎�
	{
		Vec2 ScaleSize = { this->Scale.x * this->Radius.x,this->Scale.y * this->Radius.y };
		//�����蔻��𐶐�����
		this->collisionCube.hitBase = {
			this->position.x + ((this->Scale.x - ScaleSize.x) / 2),
			this->position.y + ((this->Scale.y - ScaleSize.y) / 2),
			ScaleSize.x + (this->position.x + ((this->Scale.x - ScaleSize.x) / 2)),
			ScaleSize.y + (this->position.y + ((this->Scale.y - ScaleSize.y) / 2))
		};
		//��]��K�p����
		this->collisionCube.Rotate(this->angle);
		//Collision���Ŏg�p���Ă���Vec2�z��^�ɕύX
		Vec2 _v[4] = {
		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.y },
		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.y },
		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.h - 1 },
		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.h - 1 }
		};
		//���̒l����]��K�p�������l�ɕύX����
		OG::_Rotate(this->collisionCube.angle, _v);
		//�S�̒��_����Ō���
		OG::LineHitDraw(_v);
		break;
	}
	case Objform::Ball:
		break;
	case Objform::Non:
		break;
	}
}

void GameObject::CheckON()
{
	this->isCheck = true;
}

bool GameObject::IsObjectDistanceCheck(const Vec2& pos, const Vec2& size)
{
	if (this->position.x - this->Scale.x < pos.x + size.x &&
		this->position.y - this->Scale.y < pos.y + size.y &&
		this->position.x + (this->Scale.x * 2) > pos.x &&
		this->position.y + (this->Scale.y * 2) > pos.y)
	{
		return true;
	}
	return false;
}

void GameObject::LineDistanceDraw()
{
	Box2D d(this->position.x - this->Scale.x, this->position.y - this->Scale.y, this->position.x + (this->Scale.x * 2), this->position.y + (this->Scale.y * 2));
	OG::LineHitDraw(&d);
}