#include "Object.h"

GameObject::GameObject()
{
	//判定未生成コンストラクタ処理
	this->ResetData();
	this->_angle = 0.f;
	this->_collision = nullptr;
	this->_distanceCollision = nullptr;
	this->_form = Objform::Non;
}
GameObject::~GameObject()
{
	//解放処理
	OG::Destroy<CollisionBase>(this->_collision);
	OG::Destroy<CollisionCircle>(this->_distanceCollision);
}

GameObject::GameObject(
	const Objform& form,
	const std::string& tag,
	const Vec2& pos,
	const Vec2& scale,
	const float angle)
{
	//引数ありコンストラクタ処理
	this->Init(form, tag, pos, scale, angle);
}

void GameObject::ResetData()
{
	//自動設定される値のリセット処理
	this->_mass = 0.f;
	this->enableCollision = true;
	this->_mode = GO::Mode::NORMAL;
	this->_radius = { 1,1 };
}

void GameObject::Init(
	const Objform& form,
	const std::string& tag,
	const Vec2& pos,
	const Vec2& scale,
	const float angle)
{
	//初期化処理
	this->ResetData();
	this->_form = form;
	this->_tag = tag;
	this->_position = pos;
	this->_scale = scale;
	this->_angle = angle;
	this->_distanceScale = this->_scale * 1.5f;
	this->CreateCollision();
}

void GameObject::CreateCollision()
{
	//当たり判定を生成
	OG::Destroy<CollisionBase>(this->_collision);
	switch (this->_form)
	{
	case Objform::Circle:
	{
		this->_collision = new CollisionCircle;
		this->_collision->CreateHitBase(&this->_position, &this->_scale, &this->_radius, &this->_angle);
	}
		break;
	case Objform::Box:
	{
		this->_collision = new CollisionBox;
		this->_collision->CreateHitBase(&this->_position, &this->_scale, &this->_radius, &this->_angle);
	}
		break;
	case Objform::Line:
	{
		this->_collision = new CollisionLine;
		this->_collision->CreateHitBase(&this->_position, &this->_scale, &this->_radius, &this->_angle);
	}
		break;
	case Objform::Pointer:
	{
		this->_collision = new CollisionPointer;
		this->_collision->CreateHitBase(&this->_position, &this->_scale, &this->_radius, &this->_angle);
	}
		break;
	default:
		break;
	}
	OG::Destroy<CollisionCircle>(this->_distanceCollision);
	this->_distanceCollision = new CollisionCircle();
	this->_distanceCollision->CreateHitBase(&this->_position, &this->_distanceScale, &this->_radius, &this->_angle);
}

bool GameObject::Hit(GameObject* object)
{
	return this->_collision->Hit(object->_collision);
}
bool GameObject::Hit(CollisionBase* object)
{
	return this->_collision->Hit(object);
}
bool GameObject::IsObjectDistanceCheck(GameObject* object)
{
	return this->_distanceCollision->Hit(object->_distanceCollision);
}
bool GameObject::IsObjectDistanceCheck(CollisionCircle* object)
{
	return this->_distanceCollision->Hit(object);
}
void GameObject::LineDraw(const float lineWidth)
{
	switch (this->_form)
	{
	case Objform::Circle:
	{
		Vec2 scaleSize = { this->_scale * this->_radius };
		OG::LineOvalDraw(
			&this->_position,
			&scaleSize,
			lineWidth);
	}
		break;
	case Objform::Box:
	{
		Box2D d = { this->_position ,this->_scale * this->_radius };
		d.OffsetCenterSize();
		Vec2 _v[4] = {
			{ d.x,d.y },
		{ d.w - 1,d.y },
		{ d.w - 1,d.h },
		{ d.x,d.h }
		};
		OG::_Rotate(_angle, _v);
		OG::LineBoxDraw(_v, lineWidth);
	}
		break;
	case Objform::Line:
	{
		Vec2 _v[2] =
		{
		{this->_position},
		{this->_scale}
		};
		OG::LineDraw(_v, lineWidth);
	}
		break;
	case Objform::Pointer:
		OG::PointDraw(&this->_position, lineWidth);
		break;
	default:
		break;
	}
}
void GameObject::LineDistanceDraw(const float lineWidth)
{
	OG::LineOvalDraw(this->_position.x, this->_position.y, this->_distanceScale.x, this->_distanceScale.y,lineWidth);
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
	switch (this->_mode)
	{
	case GO::Mode::NORMAL:
		this->Update();
		break;
	case GO::Mode::PAUSE:
		this->Pause();
		break;
	default:
		break;
	}
}
void GameObject::RenderManager()
{
	switch (this->_mode)
	{
	case GO::Mode::NORMAL:
	case GO::Mode::PAUSE:
	case GO::Mode::STOP:
		this->Render2D();
		break;
	default:
		break;
	}
}
void GameObject::CollisionConfig(const bool flag)
{
	this->enableCollision = flag;
}
bool GameObject::IsCollision() const
{
	return this->enableCollision;
}
void GameObject::SetPosition(const Vec2& pos)
{
	this->_position = pos;
}
void GameObject::SetPosition(const float x, const float y)
{
	this->_position = { x,y };
}
Vec2 GameObject::GetPosition() const
{
	return this->_position;
}
void GameObject::SetScale(const Vec2& scale)
{
	this->_scale = scale;
}
void GameObject::SetScale(const float x, const float y)
{
	this->_scale = { x,y };
}
Vec2 GameObject::GetScale() const
{
	return this->_scale;
}
void GameObject::SetRotate(const float angle)
{
	this->_angle = angle;
}
float GameObject::GetRotate() const
{
	return this->_angle;
}
void GameObject::SetRadius(const Vec2& radius)
{
	this->_radius = radius;
}
void GameObject::SetRadius(const float x, const float y)
{
	this->_radius = { x,y };
}
Vec2 GameObject::GetRadius() const
{
	return this->_radius;
}
void GameObject::SetTag(const std::string& tag)
{
	this->_tag = tag;
}
std::string GameObject::GetTag() const
{
	return this->_tag;
}
void GameObject::SetMass(const float mass)
{
	this->_mass = mass;
}
float GameObject::GetMass() const
{
	return this->_mass;
}
void GameObject::Kill()
{
	this->_mode = GO::Mode::KILL;
}
void GameObject::CancelKill()
{
	this->_mode = GO::Mode::NORMAL;
}
void GameObject::SetPause(const bool flag)
{
	//削除状態は最優先のためその場合は省く
	if (this->ModeCheck(GO::Mode::KILL))
	{
		return;
	}
	if (flag)
	{
		this->_mode = GO::Mode::PAUSE;
	}
	else
	{	
		this->_mode = GO::Mode::NORMAL;
	}
}
void GameObject::SetStop(const bool flag)
{
	if (this->ModeCheck(GO::Mode::KILL))
	{
		return;
	}
	if (flag)
	{
		this->_mode = GO::Mode::STOP;
	}
	else
	{
		this->_mode = GO::Mode::NORMAL;
	}
}
void GameObject::SetAllStop(const bool flag)
{
	if (this->ModeCheck(GO::Mode::KILL))
	{
		return;
	}
	if (flag)
	{
		this->_mode = GO::Mode::ALLSTOP;
	}
	else
	{
		this->_mode = GO::Mode::NORMAL;
	}
}
GO::Mode GameObject::GetMode() const
{
	return this->_mode;
}
bool GameObject::ModeCheck(const GO::Mode& mode) const
{
	return this->_mode == mode ? true : false;
}
Objform GameObject::Getform() const
{
	return this->_form;
}
void GameObject::SetDrawOrder(const unsigned int order)
{
	this->_order = order;
}
unsigned int GameObject::GetDrawOrder() const
{
	return this->_order;
}

//
//GameObject::GameObject() {
//	//各変数の初期化
//	this->isGravity = false;
//	this->angle = 0.f;
//	this->objform = Objform::Non;
//	this->mass = 0.f;
//	this->Radius = { 1.0f,1.0f };
//	this->isCheck = false;
//}
//GameObject::GameObject(const Objform& form,const Vec2& _posi,const  Vec2& _Sca,const float _ang)
//{
//	//各値をセットする
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
//	//各値をセットする
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
//	case Objform::Cube:			//自分が矩形の時
//	{
//		Vec2 ScaleSize = { this->Scale.x * this->Radius.x,this->Scale.y * this->Radius.y };
//		//当たり判定を生成する
//		this->collisionCube.hitBase = {
//			this->position.x + ((this->Scale.x - ScaleSize.x) / 2),
//			this->position.y + ((this->Scale.y - ScaleSize.y) / 2),
//			ScaleSize.x + (this->position.x + ((this->Scale.x - ScaleSize.x) / 2)),
//			ScaleSize.y + (this->position.y + ((this->Scale.y - ScaleSize.y) / 2))
//		};
//		//回転値を適用させる
//		this->collisionCube.Rotate(this->angle);
//		switch (o.objform)
//		{
//		case Objform::Cube:		//相手が矩形の時
//		{
//			Vec2 ScaleSize_o = { o.Scale.x * o.Radius.x,o.Scale.y * o.Radius.y };
//			//位置とサイズから当たり判定を生成する
//			o.collisionCube.hitBase = {
//				o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2),
//				o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2),
//				ScaleSize_o.x + (o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2)),
//				ScaleSize_o.y + (o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2))
//			};
//			//回転値を適用させる
//			o.collisionCube.Rotate(o.angle);
//			//Collision内の判定を使用してその結果を返す
//			return this->collisionCube.hitBox(o.collisionCube);
//			break;
//		}
//		case Objform::Ball:		//相手が円の時
//		{
//			//位置とサイズから当たり判定を生成する
//			o.collisionBall.hitBase = {
//				o.position.x,
//				o.position.y,
//				o.Scale.x / 2.f };
//			//Collision内の判定を使用してその結果を返す
//			return this->collisionCube.hitCircle(o.collisionBall);
//			break;
//		}
//		}
//	}
//		break;
//	case Objform::Ball:			//自分が円の時
//	{
//		//位置とサイズから当たり判定を生成する
//		this->collisionBall.hitBase = {
//			this->position.x,
//			this->position.y,
//			this->Scale.x / 2.f };
//		switch (o.objform)
//		{
//		case Objform::Cube:		//相手が矩形の時
//		{
//			Vec2 ScaleSize_o = { o.Scale.x * o.Radius.x,o.Scale.y * o.Radius.y };
//			//位置とサイズから当たり判定を生成する
//			o.collisionCube.hitBase = {
//				o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2),
//				o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2),
//				ScaleSize_o.x + (o.position.x + ((o.Scale.x - ScaleSize_o.x) / 2)),
//				ScaleSize_o.y + (o.position.y + ((o.Scale.y - ScaleSize_o.y) / 2))
//			};
//			o.collisionCube.Rotate(o.angle);
//			//Collision内の判定を使用してその結果を返す
//			return this->collisionBall.hitBox(o.collisionCube);
//			break;
//		}
//		case Objform::Ball:		//相手が円の時
//		{
//			//位置とサイズから当たり判定を生成する
//			o.collisionBall.hitBase = {
//				o.position.x,
//				o.position.y,
//				o.Scale.x / 2.f };
//			//Collision内の判定を使用してその結果を返す
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
//	//当たり判定を生成する
//	this->collisionCube.hitBase = {
//		this->position.x + ((this->Scale.x - ScaleSize.x) / 2),
//		this->position.y + ((this->Scale.y - ScaleSize.y) / 2),
//		ScaleSize.x + (this->position.x + ((this->Scale.x - ScaleSize.x) / 2)),
//		ScaleSize.y + (this->position.y + ((this->Scale.y - ScaleSize.y) / 2))
//	};
//	Vec2 ScaleSize_o = { o.Scale.x * o.Radius.x,o.Scale.y * o.Radius.y };
//	//位置とサイズから当たり判定を生成する
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
//	case Objform::Cube:		//自分が矩形の時
//	{
//		Vec2 ScaleSize = { this->Scale.x * this->Radius.x,this->Scale.y * this->Radius.y };
//		//当たり判定を生成する
//		this->collisionCube.hitBase = {
//			this->position.x + ((this->Scale.x - ScaleSize.x) / 2),
//			this->position.y + ((this->Scale.y - ScaleSize.y) / 2),
//			ScaleSize.x + (this->position.x + ((this->Scale.x - ScaleSize.x) / 2)),
//			ScaleSize.y + (this->position.y + ((this->Scale.y - ScaleSize.y) / 2))
//		};
//		//回転を適用する
//		this->collisionCube.Rotate(this->angle);
//		//Collision内で使用しているVec2配列型に変更
//		Vec2 _v[4] = {
//		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.y },
//		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.y },
//		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.h - 1 },
//		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.h - 1 }
//		};
//		//その値を回転を適用させた値に変更する
//		OG::_Rotate(this->collisionCube.Rotate(), _v);
//		//４つの頂点を線で結ぶ
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