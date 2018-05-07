#include "Object.h"
GameObject::GameObject() {
	//各変数の初期化
	this->Gravity = false;
	this->angle = 0.f;
	this->objform = Objform::Non;
	this->mass = 0.f;
}
GameObject::GameObject(Objform form, Vec2 _posi, Vec2 _Sca, float _ang)
{
	//各値をセットする
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
	//各値をセットする
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
bool GameObject::hit(GameObject& o)
{
	switch (this->objform)
	{
	case Objform::Cube:			//自分が矩形の時
		//位置とサイズから当たり判定を生成する
		this->collisionCube.hitBase = {
			this->position.x,
			this->position.y,
			this->Scale.x + this->position.x,
			this->Scale.y + this->position.y };
		//回転値を適用させる
		this->collisionCube.Rotate(this->angle);
		switch (o.objform)
		{
		case Objform::Cube:		//相手が矩形の時
			//位置とサイズから当たり判定を生成する
			o.collisionCube.hitBase = {
				o.position.x,
				o.position.y,
				o.Scale.x + o.position.x,
				o.Scale.y + o.position.y};
			//回転値を適用させる
			o.collisionCube.Rotate(o.angle);
			//Collision内の判定を使用してその結果を返す
			return this->collisionCube.hitBox(o.collisionCube);
			break;
		case Objform::Ball:		//相手が円の時
			//位置とサイズから当たり判定を生成する
			o.collisionBall.hitBase = {
				o.Scale.x,
				o.position.x,
				o.position.y };
			//Collision内の判定を使用してその結果を返す
			return this->collisionCube.hitCircle(o.collisionBall);
			break;
		}
		break;
	case Objform::Ball:			//自分が円の時
		//位置とサイズから当たり判定を生成する
		this->collisionBall.hitBase = {
			this->Scale.x,
			this->position.x,
			this->position.y };
		switch (o.objform)
		{
		case Objform::Cube:		//相手が矩形の時
			//位置とサイズから当たり判定を生成する
			o.collisionCube.hitBase = {
				o.position.x,
				o.position.y,
				o.Scale.x + o.position.x,
				o.Scale.y + o.position.y };
			o.collisionCube.Rotate(o.angle);
			//Collision内の判定を使用してその結果を返す
			return this->collisionBall.hitBox(o.collisionCube);
			break;
		case Objform::Ball:		//相手が円の時
			//位置とサイズから当たり判定を生成する
			o.collisionBall.hitBase = {
				o.Scale.x,
				o.position.x,
				o.position.y };
			//Collision内の判定を使用してその結果を返す
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
	case Objform::Cube:		//自分が矩形の時
	{
		//当たり判定を生成する
		this->collisionCube.hitBase = {
			this->position.x,
			this->position.y,
			this->Scale.x + this->position.x,
			this->Scale.y + this->position.y
		};
		//回転を適用する
		this->collisionCube.Rotate(this->angle);
		//Collision内で使用しているVec2配列型に変更
		Vec2 _v[4] = {
		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.y },
		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.y },
		{ this->collisionCube.hitBase.w - 1,this->collisionCube.hitBase.h - 1 },
		{ this->collisionCube.hitBase.x,this->collisionCube.hitBase.h - 1 }
		};
		//その値を回転を適用させた値に変更する
		OG::_Rotate(this->collisionCube.angle, _v);
		//４つの頂点を線で結ぶ
		OG::LineHitDraw(_v);
		break;
	}
	case Objform::Ball:
		break;
	case Objform::Non:
		break;
	}
}