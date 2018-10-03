#include "Collision.h"
//--------------------------------------------------
//@:CollisionBase
//--------------------------------------------------
CollisionBase::CollisionBase(const unsigned short vertex)
	:VERTEX_NUM(vertex)
{
	OG::Destroy<Vec2>(this->_pos);
	OG::Destroy<Vec2>(this->_scale);
	OG::Destroy<Vec2>(this->_radius);
	OG::Destroy<float>(this->_rotate);
}
void CollisionBase::CreateHitBase(Vec2* pos, Vec2* scale, Vec2* radius, float* angle)
{
	this->_pos = pos;
	this->_scale = scale;
	this->_radius = radius;
	this->_rotate = angle;
}
//--------------------------------------------------
//@:CollisionBox
//--------------------------------------------------
CollisionBox::CollisionBox()
	:CollisionBase(4)
{
}
//矩形×矩形
bool CollisionBox::GetHit(CollisionBox* b)
{
	this->CreateCollision();
	b->CreateCollision();
	//頂点情報のセット
	Vec2 _ver[4] = {
		{ b->hitBase.x,b->hitBase.y },
	{ b->hitBase.w - 1,b->hitBase.y },
	{ b->hitBase.w - 1,b->hitBase.h },
	{ b->hitBase.x,b->hitBase.h }
	};
	Vec2 _v[4] = {
		{ hitBase.x,hitBase.y },
	{ hitBase.w - 1,hitBase.y },
	{ hitBase.w - 1,hitBase.h },
	{ hitBase.x,hitBase.h }
	};
	//回転の適用
	OG::_Rotate(angle, _v);
	OG::_Rotate(b->angle, _ver);
	//どちらかの範囲内に相手の頂点が存在する場合TRUEを返す
	for (int i = 0; i < 4; ++i) {
		if ((((_v[1].x - _v[0].x)*(_ver[i].y - _v[0].y)) - ((_ver[i].x - _v[0].x)*(_v[1].y - _v[0].y))) >= 0 &&
			(((_v[2].x - _v[1].x)*(_ver[i].y - _v[1].y)) - ((_ver[i].x - _v[1].x)*(_v[2].y - _v[1].y))) >= 0 &&
			(((_v[3].x - _v[2].x)*(_ver[i].y - _v[2].y)) - ((_ver[i].x - _v[2].x)*(_v[3].y - _v[2].y))) >= 0 &&
			(((_v[0].x - _v[3].x)*(_ver[i].y - _v[3].y)) - ((_ver[i].x - _v[3].x)*(_v[0].y - _v[3].y))) >= 0)
		{
			return true;
		}
	}
	//相手オブジェクト目線でも同じく処理を行う
	for (int i = 0; i < 4; ++i) {
		if ((((_ver[1].x - _ver[0].x)*(_v[i].y - _ver[0].y)) - ((_v[i].x - _ver[0].x)*(_ver[1].y - _ver[0].y))) >= 0 &&
			(((_ver[2].x - _ver[1].x)*(_v[i].y - _ver[1].y)) - ((_v[i].x - _ver[1].x)*(_ver[2].y - _ver[1].y))) >= 0 &&
			(((_ver[3].x - _ver[2].x)*(_v[i].y - _ver[2].y)) - ((_v[i].x - _ver[2].x)*(_ver[3].y - _ver[2].y))) >= 0 &&
			(((_ver[0].x - _ver[3].x)*(_v[i].y - _ver[3].y)) - ((_v[i].x - _ver[3].x)*(_ver[0].y - _ver[3].y))) >= 0)
		{
			return true;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		//オブジェクトAの終点-始点の方向ベクトル
		Vec2 mainvec = _v[(i + 1) % 4] - _v[i % 4];
		for (int j = 0; j < 4; ++j)
		{
			//オブジェクトBの終点-始点の方向ベクトル
			Vec2 subvec = _ver[(j + 1) % 4] - _ver[j % 4];
			Vec2 v = _ver[j % 4] - _v[i % 4];
			//外積計算
			float crs = OG::cross(mainvec, subvec);
			if (crs == 0.0f)
			{
				//平行状態
				continue;
			}
			float crs_v1 = OG::cross(v, mainvec);
			float crs_v2 = OG::cross(v, subvec);
			float t1 = crs_v2 / crs;
			float t2 = crs_v1 / crs;
			if (t1 > 0.f && t1 < 1.f && t2 > 0.f && t2 < 1.f)
			{
				//交差してる
				return true;
			}
		}
	}
	return false;
}
//矩形×円
bool CollisionBox::GetHit(CollisionCircle* b)
{
	this->CreateCollision();
	b->CreateCollision();
	//頂点情報のセット
	Vec2 _ver[1] = {
		{ b->hitBase.center_x,b->hitBase.center_y }
	};
	Vec2 _v[4] = {
		{ hitBase.x,hitBase.y },
	{ hitBase.w - 1,hitBase.y },
	{ hitBase.w - 1,hitBase.h },
	{ hitBase.x,hitBase.h }
	};
	//Box型の回転の適用
	OG::_Rotate(angle, _v);
	//円の中に頂点が存在する場合TRUEを返す
	if ((((_v[1].x - _v[0].x)*(_ver[0].y - _v[0].y)) - ((_ver[0].x - _v[0].x)*(_v[1].y - _v[0].y))) >= b->hitBase.r*b->hitBase.r &&
		(((_v[2].x - _v[1].x)*(_ver[0].y - _v[1].y)) - ((_ver[0].x - _v[1].x)*(_v[2].y - _v[1].y))) >= b->hitBase.r*b->hitBase.r &&
		(((_v[3].x - _v[2].x)*(_ver[0].y - _v[2].y)) - ((_ver[0].x - _v[2].x)*(_v[3].y - _v[2].y))) >= b->hitBase.r*b->hitBase.r &&
		(((_v[0].x - _v[3].x)*(_ver[0].y - _v[3].y)) - ((_ver[0].x - _v[3].x)*(_v[0].y - _v[3].y))) >= b->hitBase.r*b->hitBase.r)
	{
		return true;
	}
	
	//円の中に線分が存在する場合TRUEを返す
	for (int i = 0; i<4; i++) {
		if (OG::get_distance(_ver[0].x, _ver[0].y, _v[i].x, _v[i].y, _v[(i + 1) % 4].x, _v[(i + 1) % 4].y)<b->hitBase.r)
			return true;
	}
	return false;
}
//矩形×点
bool CollisionBox::GetHit(CollisionPointer* b)
{
	this->CreateCollision();
	b->CreateCollision();
	Vec2 _v[4] = {
		{ hitBase.x,hitBase.y },
	{ hitBase.w - 1,hitBase.y },
	{ hitBase.w - 1,hitBase.h },
	{ hitBase.x,hitBase.h }
	};
	OG::_Rotate(angle, _v);
	for (int i = 0; i < 4; ++i)
	{
		if ((((_v[(i + 1) % 4].x - _v[i].x)*
			(b->hitBase.y - _v[i].y)) -
			((b->hitBase.x - _v[i].x)*
			(_v[(i + 1) % 4].y - _v[i].y)))
			< 0)
		{
			return false;
		}
	}
	return true;
}
//矩形×線
bool CollisionBox::GetHit(CollisionLine* b)
{
	this->CreateCollision();
	b->CreateCollision();
	return false;
}
//矩形×カプセル
bool CollisionBox::GetHit(CollisionCapsule* b)
{
	return false;
}
//判定生成
void CollisionBox::CreateCollision()
{
	Vec2 scaleSize = { this->_scale->x * this->_radius->x,this->_scale->y * this->_radius->y };
	this->hitBase = {
		this->_pos->x - (scaleSize.x / 2.f),
		this->_pos->y - (scaleSize.y / 2.f),
		this->_pos->x + (scaleSize.x / 2.f),
		this->_pos->y + (scaleSize.y / 2.f)
	};
	this->Rotate(*this->_rotate);
}
//回転適用
void CollisionBox::Rotate(const float _angle) {
	//回転の値を格納
	this->angle = _angle;
}
//回転取得
float CollisionBox::Rotate() const
{
	return this->angle;
}
//判定
bool CollisionBox::Hit(CollisionBase* collision)
{
	return collision->GetHit(this);
}
//--------------------------------------------------
//@:CollisionCircle
//--------------------------------------------------
CollisionCircle::CollisionCircle()
	:CollisionBase(1)
{
}
//円×矩形
bool CollisionCircle::GetHit(CollisionBox* b)
{
	this->CreateCollision();
	b->CreateCollision();
	//頂点情報のセット
	Vec2 _ver[1] = {
		{ hitBase.center_x,hitBase.center_y }
	};
	Vec2 _v[4] = {
		{ b->hitBase.x,b->hitBase.y },
	{ b->hitBase.w - 1,b->hitBase.y },
	{ b->hitBase.w - 1,b->hitBase.h },
	{ b->hitBase.x,b->hitBase.h }
	};
	//Box型の回転の適用
	OG::_Rotate(b->Rotate(), _v);
	//円の中に頂点が存在する場合TRUEを返す
	if ((((_v[1].x - _v[0].x)*(_ver[0].y - _v[0].y)) - ((_ver[0].x - _v[0].x)*(_v[1].y - _v[0].y))) >= hitBase.r*hitBase.r &&
		(((_v[2].x - _v[1].x)*(_ver[0].y - _v[1].y)) - ((_ver[0].x - _v[1].x)*(_v[2].y - _v[1].y))) >= hitBase.r*hitBase.r &&
		(((_v[3].x - _v[2].x)*(_ver[0].y - _v[2].y)) - ((_ver[0].x - _v[2].x)*(_v[3].y - _v[2].y))) >= hitBase.r*hitBase.r &&
		(((_v[0].x - _v[3].x)*(_ver[0].y - _v[3].y)) - ((_ver[0].x - _v[3].x)*(_v[0].y - _v[3].y))) >= hitBase.r*hitBase.r)
	{
		return true;
	}
	//円の中に線分が存在する場合TRUEを返す
	for (int i = 0; i<4; i++) {
		if (OG::get_distance(_ver[0].x, _ver[0].y, _v[i].x, _v[i].y, _v[(i + 1) % 4].x, _v[(i + 1) % 4].y)<hitBase.r)
			return true;
	}
	return false;
}
//円×円
bool CollisionCircle::GetHit(CollisionCircle* b)
{
	this->CreateCollision();
	b->CreateCollision();
	//円の範囲内に相手の円の範囲が存在する場合TRUEを返す
	if (((b->hitBase.center_x - this->hitBase.center_x)*
		(b->hitBase.center_x - this->hitBase.center_x)) +
		((b->hitBase.center_y - this->hitBase.center_y)*
		(b->hitBase.center_y - this->hitBase.center_y)) <=
			(b->hitBase.r + this->hitBase.r)*(b->hitBase.r + this->hitBase.r))
	{
		return true;
	}
	return false;
}
//円×点
bool CollisionCircle::GetHit(CollisionPointer* b)
{
	this->CreateCollision();
	b->CreateCollision();
	//頂点情報のセット
	Vec2 _ver[1] = {
		{ hitBase.center_x,hitBase.center_y }
	};
	Vec2 _v[1] = {
		{ b->hitBase.x,b->hitBase.y },
	};
	//円の中に頂点が存在する場合TRUEを返す
	if (((_ver[0].x - _v[0].x) * (_ver[0].x - _v[0].x)) + ((_ver[0].y - _v[0].y) * (_ver[0].y - _v[0].y)) <= this->hitBase.r * this->hitBase.r)
	{
		return true;
	}
	return false;
}
//円×線
bool CollisionCircle::GetHit(CollisionLine* b)
{
	return false;
}
//円×カプセル
bool CollisionCircle::GetHit(CollisionCapsule* b)
{
	return false;
}
//判定生成
void CollisionCircle::CreateCollision()
{
	this->hitBase = {
		this->_pos->x,
		this->_pos->y,
		this->_scale->x / 2.f
	};
}
//判定
bool CollisionCircle::Hit(CollisionBase* collision)
{
	return collision->GetHit(this);
}
//--------------------------------------------------
//@:CollisionPointer
//--------------------------------------------------
CollisionPointer::CollisionPointer()
	:CollisionBase(1)
{
}
//点×矩形
bool CollisionPointer::GetHit(CollisionBox* b)
{
	this->CreateCollision();
	b->CreateCollision();
	Vec2 _v[4] = {
	{ b->hitBase.x,b->hitBase.y },
	{ b->hitBase.w - 1,b->hitBase.y },
	{ b->hitBase.w - 1,b->hitBase.h },
	{ b->hitBase.x,b->hitBase.h }
	};
	OG::_Rotate(b->Rotate(), _v);
	for (int i = 0; i < 4; ++i)
	{
		if ((((_v[(i + 1) % 4].x - _v[i].x)*
			(hitBase.y - _v[i].y)) -
			((hitBase.x - _v[i].x)*
			(_v[(i + 1) % 4].y - _v[i].y)))
			< 0)
		{
			return false;
		}
	}
	return true;
}
//点×円
bool CollisionPointer::GetHit(CollisionCircle* b)
{
	this->CreateCollision();
	b->CreateCollision();
	//頂点情報のセット
	Vec2 _ver[1] = {
		{ b->hitBase.center_x,b->hitBase.center_y }
	};
	Vec2 _v[1] = {
		{ hitBase.x,hitBase.y },
	};
	//円の中に頂点が存在する場合TRUEを返す
	if (((_ver[0].x - _v[0].x) * (_ver[0].x - _v[0].x)) + ((_ver[0].y - _v[0].y) * (_ver[0].y - _v[0].y)) <= b->hitBase.r * b->hitBase.r)
	{
		return true;
	}
	return false;
}
//点×点
bool CollisionPointer::GetHit(CollisionPointer* b)
{
	this->CreateCollision();
	b->CreateCollision();
	return this->hitBase == b->hitBase;
}
//点×線
bool CollisionPointer::GetHit(CollisionLine* b)
{
	this->CreateCollision();
	b->CreateCollision();
	float line_1 = sqrt(
		(b->hitBase[1].x - b->hitBase[0].x)*(b->hitBase[1].x - b->hitBase[0].x) +
		(b->hitBase[1].y - b->hitBase[0].y)*(b->hitBase[1].y - b->hitBase[0].y)
	);
	float line_2 = sqrt(
		(hitBase.x - b->hitBase[0].x)*(hitBase.x - b->hitBase[0].x) +
		(hitBase.y - b->hitBase[0].y)*(hitBase.y - b->hitBase[0].y)
	);
	if (
		((b->hitBase[1].x - b->hitBase[0].x)*(hitBase.x - b->hitBase[0].x) +
		(b->hitBase[1].y - b->hitBase[0].y)*(hitBase.x - b->hitBase[0].y)) == line_1 * line_2 &&
		line_1 >= line_2
		)
	{
		return true;
	}
	return false;
}
//点×カプセル
bool CollisionPointer::GetHit(CollisionCapsule* b)
{
	return false;
}
//判定生成
void CollisionPointer::CreateCollision()
{
	this->hitBase = *this->_pos;
}
//判定
bool CollisionPointer::Hit(CollisionBase* collision)
{
	return collision->GetHit(this);
}
//--------------------------------------------------
//@:CollisionLine
//--------------------------------------------------
CollisionLine::CollisionLine()
	:CollisionBase(2)
{

}
//線×矩形
bool CollisionLine::GetHit(CollisionBox* b)
{
	return false;
}
//線×円
bool CollisionLine::GetHit(CollisionCircle* b)
{
	return false;
}
//線×線
bool CollisionLine::GetHit(CollisionLine* b)
{
	return false;
}
//線×点
bool CollisionLine::GetHit(CollisionPointer* b)
{
	return false;
}
//線×カプセル
bool CollisionLine::GetHit(CollisionCapsule* b)
{
	return false;
}
//判定生成
void CollisionLine::CreateCollision()
{
	this->hitBase[0] = *this->_pos;
	this->hitBase[1] = *this->_scale;
}
//判定
bool CollisionLine::Hit(CollisionBase* collision)
{
	return collision->GetHit(this);
}
//--------------------------------------------------
//@:CollisionCapsule
//--------------------------------------------------
CollisionCapsule::CollisionCapsule()
	:CollisionBase(6)
{

}
//カプセル×カプセル
bool CollisionCapsule::GetHit(CollisionCapsule* b)
{
	return false;
}
//カプセル×矩形
bool CollisionCapsule::GetHit(CollisionBox* b)
{
	return false;
}
//カプセル×円
bool CollisionCapsule::GetHit(CollisionCircle* b)
{
	return false;
}
//カプセル×点
bool CollisionCapsule::GetHit(CollisionPointer* b)
{
	return false;
}
//カプセル×線
bool CollisionCapsule::GetHit(CollisionLine* b)
{
	return false;
}
//判定
bool CollisionCapsule::Hit(CollisionBase* collision)
{
	return collision->Hit(this);
}