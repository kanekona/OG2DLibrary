#include "Object.h"

GameObject::GameObject()
{
	//���薢�����R���X�g���N�^����
	this->ResetData();
	this->angle = 0.f;
	this->collision = nullptr;
	this->distanceCollision = nullptr;
	this->form = Objform::Non;
}
GameObject::~GameObject()
{
	//�������
	OG::Destroy<CollisionBase>(this->collision);
	OG::Destroy<CollisionCircle>(this->distanceCollision);
}

GameObject::GameObject(
	const Objform& form,
	const std::string& tag,
	const Vec2& pos,
	const Vec2& scale,
	const float angle)
{
	this->Init(form, tag, pos, scale, angle);
}

void GameObject::ResetData()
{
	this->mass = 0.f;
	this->isCollision = true;
	this->mode = Mode::NORMAL;
}

void GameObject::Init(
	const Objform& form,
	const std::string& tag,
	const Vec2& pos,
	const Vec2& scale,
	const float angle)
{
	this->ResetData();
	this->form = form;
	this->tag = tag;
	this->position = pos;
	this->scale = scale;
	this->angle = angle;
	this->CreateCollision();
}

void GameObject::CreateCollision()
{
	OG::Destroy<CollisionBase>(this->collision);
	switch (this->form)
	{
	case Objform::Ball:
		this->collision = new CollisionCircle;
		break;
	case Objform::Cube:
		this->collision = new CollisionBox;
		break;
	case Objform::Line:
		this->collision = new CollisionLine;
		break;
	case Objform::Pointer:
		this->collision = new CollisionPointer;
		break;
	}
}

bool GameObject::Hit(GameObject* object)
{
	return this->collision->Hit(*object->collision);
}
bool GameObject::Hit(CollisionBase* object)
{
	return this->collision->Hit(*object);
}
bool GameObject::IsObjectDistanceCheck(GameObject* object)
{
	return this->distanceCollision->Hit(*object->distanceCollision);
}
bool GameObject::IsObjectDistanceCheck(CollisionCircle* object)
{
	return this->distanceCollision->Hit(*object);
}
void GameObject::LineDraw(const float lineWidth)
{

}
void GameObject::LineDistanceDraw(const float lineWidth)
{

}
void GameObject::Update()
{
	
}
void GameObject::Render2D()
{

}
void GameObject::Pause()
{

}
void GameObject::UpdateManager()
{
	switch (this->mode)
	{
	case Mode::NORMAL:
		this->Update();
		break;
	case Mode::PAUSE:
		this->Pause();
		break;
	default:
		break;
	}
}
void GameObject::RenderManager()
{
	switch (this->mode)
	{
	case Mode::NORMAL:
	case Mode::PAUSE:
	case Mode::STOP:
		this->Render2D();
		break;
	default:
		break;
	}
}
void GameObject::CollisionConfig(const bool flag)
{
	this->isCollision = flag;
}
bool GameObject::IsCollision() const
{
	return this->isCollision;
}
void GameObject::SetPosition(const Vec2& pos)
{
	this->position = pos;
}
void GameObject::SetPosition(const float x, const float y)
{
	this->position = { x,y };
}
Vec2 GameObject::GetPosition() const
{
	return this->position;
}
void GameObject::SetScale(const Vec2& scale)
{
	this->scale = scale;
}
void GameObject::SetScale(const float x, const float y)
{
	this->scale = { x,y };
}
Vec2 GameObject::GetScale() const
{
	return this->scale;
}
void GameObject::SetRotate(const float angle)
{
	this->angle = angle;
}
float GameObject::GetRotate() const
{
	return this->angle;
}
void GameObject::SetRadius(const Vec2& radius)
{
	this->radius = radius;
}
void GameObject::SetRadius(const float x, const float y)
{
	this->radius = { x,y };
}
Vec2 GameObject::GetRadius() const
{
	return this->radius;
}
void GameObject::SetTag(const std::string& tag)
{
	this->tag = tag;
}
std::string GameObject::GetTag() const
{
	return this->tag;
}
void GameObject::SetMass(const float mass)
{
	this->mass = mass;
}
float GameObject::GetMass() const
{
	return this->mass;
}
void GameObject::Kill()
{
	this->mode = Mode::KILL;
}
void GameObject::SetPause(const bool flag)
{
	//�폜��Ԃ͍ŗD��̂��߂��̏ꍇ�͏Ȃ�
	if (this->ModeCheck(Mode::KILL))
	{
		return;
	}
	if (flag)
	{
		this->mode = Mode::PAUSE;
	}
	else
	{	
		this->mode = Mode::NORMAL;
	}
}
void GameObject::SetStop(const bool flag)
{
	if (this->ModeCheck(Mode::KILL))
	{
		return;
	}
	if (flag)
	{
		this->mode = Mode::STOP;
	}
	else
	{
		this->mode = Mode::NORMAL;
	}
}
void GameObject::SetAllStop(const bool flag)
{
	if (this->ModeCheck(Mode::KILL))
	{
		return;
	}
	if (flag)
	{
		this->mode = Mode::ALLSTOP;
	}
	else
	{
		this->mode = Mode::NORMAL;
	}
}
Mode GameObject::GetMode() const
{
	return this->mode;
}
bool GameObject::ModeCheck(const Mode& mode) const
{
	return this->mode == mode ? true : false;
}
Objform GameObject::Getform() const
{
	return this->form;
}

//
//GameObject::GameObject() {
//	//�e�ϐ��̏�����
//	this->isGravity = false;
//	this->angle = 0.f;
//	this->objform = Objform::Non;
//	this->mass = 0.f;
//	this->Radius = { 1.0f,1.0f };
//	this->isCheck = false;
//}
//GameObject::GameObject(const Objform& form,const Vec2& _posi,const  Vec2& _Sca,const float _ang)
//{
//	//�e�l���Z�b�g����
//	this->objform = form;
//	switch (objform)
//	{
//	case Objform::Cube:
//		this->position = _posi;
//		this->Scale = _Sca;
//		break;
//	case Objform::Ball:
//		this->position = _posi;
//		this->Scale = _Sca;
//		break;
//	}
//	this->angle = _ang;
//	this->HitCheck();
//}
//GameObject::~GameObject()
//{
//}
//void GameObject::CreateObject(const Objform& form, const Vec2& _posi, const  Vec2& _Sca, const float _ang)
//{
//	//�e�l���Z�b�g����
//	this->objform = form;
//	switch (objform)
//	{
//	case Objform::Cube:
//		this->position = _posi;
//		this->Scale = _Sca;
//		break;
//	case Objform::Ball:
//		this->position = _posi;
//		this->Scale = _Sca;
//		break;
//	}
//	this->angle = _ang;
//	this->HitCheck();
//}
//bool GameObject::hit(GameObject& o)
//{
//	if (!this->isCheck || !o.isCheck)
//	{
//		return false;
//	}
//	switch (this->objform)
//	{
//	case Objform::Cube:			//��������`�̎�
//	{
//		Vec2 ScaleSize = { this->Scale.x * this->Radius.x,this->Scale.y * this->Radius.y };
//		//�����蔻��𐶐�����
//		this->collisionCube.hitBase = {
//			this->position.x + ((this->Scale.x - ScaleSize.x) / 2),
//			this->position.y + ((this->Scale.y - ScaleSize.y) / 2),
//			ScaleSize.x + (this->position.x + ((this->Scale.x - ScaleSize.x) / 2)),
//			ScaleSize.y + (this->position.y + ((this->Scale.y - ScaleSize.y) / 2))
//		};
//		//��]�l��K�p������
//		this->collisionCube.Rotate(this->angle);
//		switch (o.objform)
//		{
//		case Objform::Cube:		//���肪��`�̎�
//		{
//			Vec2 ScaleSize_o = { o.Scale.x * o.Radius.x,o.Scale.y * o.Radius.y };
//			//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
//			o.collisionCube.hitBase = {
//				o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2),
//				o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2),
//				ScaleSize_o.x + (o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2)),
//				ScaleSize_o.y + (o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2))
//			};
//			//��]�l��K�p������
//			o.collisionCube.Rotate(o.angle);
//			//Collision���̔�����g�p���Ă��̌��ʂ�Ԃ�
//			return this->collisionCube.hitBox(o.collisionCube);
//			break;
//		}
//		case Objform::Ball:		//���肪�~�̎�
//		{
//			//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
//			o.collisionBall.hitBase = {
//				o.position.x,
//				o.position.y,
//				o.Scale.x / 2.f };
//			//Collision���̔�����g�p���Ă��̌��ʂ�Ԃ�
//			return this->collisionCube.hitCircle(o.collisionBall);
//			break;
//		}
//		}
//	}
//		break;
//	case Objform::Ball:			//�������~�̎�
//	{
//		//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
//		this->collisionBall.hitBase = {
//			this->position.x,
//			this->position.y,
//			this->Scale.x / 2.f };
//		switch (o.objform)
//		{
//		case Objform::Cube:		//���肪��`�̎�
//		{
//			Vec2 ScaleSize_o = { o.Scale.x * o.Radius.x,o.Scale.y * o.Radius.y };
//			//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
//			o.collisionCube.hitBase = {
//				o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2),
//				o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2),
//				ScaleSize_o.x + (o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2)),
//				ScaleSize_o.y + (o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2))
//			};
//			o.collisionCube.Rotate(o.angle);
//			//Collision���̔�����g�p���Ă��̌��ʂ�Ԃ�
//			return this->collisionBall.hitBox(o.collisionCube);
//			break;
//		}
//		case Objform::Ball:		//���肪�~�̎�
//		{
//			//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
//			o.collisionBall.hitBase = {
//				o.position.x,
//				o.position.y,
//				o.Scale.x / 2.f };
//			//Collision���̔�����g�p���Ă��̌��ʂ�Ԃ�
//			return this->collisionBall.hitCircle(o.collisionBall);
//			break;
//		}
//		}
//		break;
//	}
//	}
//	return false;
//}
//bool GameObject::CubeHit(GameObject &o)
//{
//	if (this->objform != Objform::Cube || o.objform != Objform::Cube)
//	{
//		return false;
//	}
//	Vec2 ScaleSize = { this->Scale.x * this->Radius.x,this->Scale.y * this->Radius.y };
//	//�����蔻��𐶐�����
//	this->collisionCube.hitBase = {
//		this->position.x + ((this->Scale.x - ScaleSize.x) / 2),
//		this->position.y + ((this->Scale.y - ScaleSize.y) / 2),
//		ScaleSize.x + (this->position.x + ((this->Scale.x - ScaleSize.x) / 2)),
//		ScaleSize.y + (this->position.y + ((this->Scale.y - ScaleSize.y) / 2))
//	};
//	Vec2 ScaleSize_o = { o.Scale.x * o.Radius.x,o.Scale.y * o.Radius.y };
//	//�ʒu�ƃT�C�Y���瓖���蔻��𐶐�����
//	o.collisionCube.hitBase = {
//		o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2),
//		o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2),
//		ScaleSize_o.x + (o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2)),
//		ScaleSize_o.y + (o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2))
//	};
//	if (this->collisionCube.hitBase.x < o.collisionCube.hitBase.w &&
//		this->collisionCube.hitBase.w > o.collisionCube.hitBase.x &&
//		this->collisionCube.hitBase.y < o.collisionCube.hitBase.h &&
//		this->collisionCube.hitBase.h > o.collisionCube.hitBase.y)
//	{
//		return true;
//	}
//	return false;
//}
//
//void GameObject::LineDraw()
//{
//	switch (this->objform)
//	{
//	case Objform::Cube:		//��������`�̎�
//	{
//		Vec2 ScaleSize = { this->Scale.x * this->Radius.x,this->Scale.y * this->Radius.y };
//		//�����蔻��𐶐�����
//		this->collisionCube.hitBase = {
//			this->position.x + ((this->Scale.x - ScaleSize.x) / 2),
//			this->position.y + ((this->Scale.y - ScaleSize.y) / 2),
//			ScaleSize.x + (this->position.x + ((this->Scale.x - ScaleSize.x) / 2)),
//			ScaleSize.y + (this->position.y + ((this->Scale.y - ScaleSize.y) / 2))
//		};
//		//��]��K�p����
//		this->collisionCube.Rotate(this->angle);
//		//Collision���Ŏg�p���Ă���Vec2�z��^�ɕύX
//		Vec2 _v[4] = {
//		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.y },
//		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.y },
//		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.h - 1 },
//		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.h - 1 }
//		};
//		//���̒l����]��K�p�������l�ɕύX����
//		OG::_Rotate(this->collisionCube.Rotate(), _v);
//		//�S�̒��_����Ō���
//		OG::LineHitDraw(_v);
//		break;
//	}
//	case Objform::Ball:
//		break;
//	case Objform::Non:
//		break;
//	}
//}
//
//void GameObject::HitCheck(bool flag)
//{
//	this->isCheck = flag;
//}
//
//bool GameObject::IsObjectDistanceCheck(const Vec2& pos, const Vec2& size)
//{
//	float maxSize[2];
//	if (this->Scale.x > this->Scale.y)
//	{
//		maxSize[0] = this->Scale.x;
//	}
//	else
//	{
//		maxSize[0] = this->Scale.y;
//	}
//	if (size.x > size.y)
//	{
//		maxSize[1] = size.x;
//	}
//	else
//	{
//		maxSize[1] = size.y;
//	}
//	if (this->position.x - maxSize[0] < pos.x + maxSize[1] &&
//		this->position.y - maxSize[0] < pos.y + maxSize[1] &&
//		this->position.x + maxSize[0] * 2 > pos.x &&
//		this->position.y + maxSize[0] * 2 > pos.y)
//	{
//		return true;
//	}
//	return false;
//}
//
//void GameObject::LineDistanceDraw()
//{
//	float maxSize;
//	if (this->Scale.x > this->Scale.y)
//	{
//		maxSize = this->Scale.x;
//	}
//	else
//	{
//		maxSize = this->Scale.y;
//	}
//	Box2D d(
//		this->position.x - maxSize,
//		this->position.y - maxSize,
//		this->position.x + maxSize * 2,
//		this->position.y + maxSize * 2);
//	OG::LineHitDraw(&d);
//}
//
//void GameObject::Move()
//{
//
//}
//
//void GameObject::Friction()
//{
//
//}