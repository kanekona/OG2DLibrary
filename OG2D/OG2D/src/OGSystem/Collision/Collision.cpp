#include "Collision.h"
//--------------------------------------------------
//@:CollisionBase
//--------------------------------------------------
CollisionBase::CollisionBase(const unsigned short vertex)
	:VERTEX_NUM(vertex)
{
}
bool CollisionBase::Hit(const CollisionBase& b)
{
	return false;
}
bool CollisionBase::Hit(const CollisionBox& b)
{
	return false;
}
bool CollisionBase::Hit(const CollisionCircle& b)
{
	return false;
}
bool CollisionBase::Hit(const CollisionPointer& b)
{
	return false;
}
bool CollisionBase::Hit(const CollisionCapsule& b)
{
	return false;
}
bool CollisionBase::Hit(const CollisionLine& b)
{
	return false;
}
void CollisionBase::CreateHitBase(const Vec2& pos, const Vec2& scale)
{

}
//--------------------------------------------------
//@:CollisionBox
//--------------------------------------------------
CollisionBox::CollisionBox()
	:CollisionBase(4)
{
}
//��`�~��`
bool CollisionBox::Hit(const CollisionBox& b)
{
	//���_���̃Z�b�g
	Vec2 _ver[4] = {
		{ b.hitBase.x,b.hitBase.y },
	{ b.hitBase.w - 1,b.hitBase.y },
	{ b.hitBase.w - 1,b.hitBase.h },
	{ b.hitBase.x,b.hitBase.h }
	};
	Vec2 _v[4] = {
		{ hitBase.x,hitBase.y },
	{ hitBase.w - 1,hitBase.y },
	{ hitBase.w - 1,hitBase.h },
	{ hitBase.x,hitBase.h }
	};
	//��]�̓K�p
	OG::_Rotate(angle, _v);
	OG::_Rotate(b.angle, _ver);
	//�ǂ��炩�͈͓̔��ɑ���̒��_�����݂���ꍇTRUE��Ԃ�
	for (int i = 0; i < 4; ++i) {
		if ((((_v[1].x - _v[0].x)*(_ver[i].y - _v[0].y)) - ((_ver[i].x - _v[0].x)*(_v[1].y - _v[0].y))) >= 0 &&
			(((_v[2].x - _v[1].x)*(_ver[i].y - _v[1].y)) - ((_ver[i].x - _v[1].x)*(_v[2].y - _v[1].y))) >= 0 &&
			(((_v[3].x - _v[2].x)*(_ver[i].y - _v[2].y)) - ((_ver[i].x - _v[2].x)*(_v[3].y - _v[2].y))) >= 0 &&
			(((_v[0].x - _v[3].x)*(_ver[i].y - _v[3].y)) - ((_ver[i].x - _v[3].x)*(_v[0].y - _v[3].y))) >= 0)
		{
			return true;
		}
	}
	//����I�u�W�F�N�g�ڐ��ł��������������s��
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
		//�I�u�W�F�N�gA�̏I�_-�n�_�̕����x�N�g��
		Vec2 mainvec = _v[(i + 1) % 4] - _v[i % 4];
		for (int j = 0; j < 4; ++j)
		{
			//�I�u�W�F�N�gB�̏I�_-�n�_�̕����x�N�g��
			Vec2 subvec = _ver[(j + 1) % 4] - _ver[j % 4];
			Vec2 v = _ver[j % 4] - _v[i % 4];
			//�O�όv�Z
			float crs = OG::cross(mainvec, subvec);
			if (crs == 0.0f)
			{
				//���s���
				continue;
			}
			float crs_v1 = OG::cross(v, mainvec);
			float crs_v2 = OG::cross(v, subvec);
			float t1 = crs_v2 / crs;
			float t2 = crs_v1 / crs;
			if (t1 > 0.f && t1 < 1.f && t2 > 0.f && t2 < 1.f)
			{
				//�������Ă�
				return true;
			}
		}
	}
	return false;
}
//��`�~�~
bool CollisionBox::Hit(const CollisionCircle& b)
{
	//���_���̃Z�b�g
	Vec2 _ver[1] = {
		{ b.hitBase.center_x,b.hitBase.center_y }
	};
	Vec2 _v[4] = {
		{ hitBase.x,hitBase.y },
	{ hitBase.w - 1,hitBase.y },
	{ hitBase.w - 1,hitBase.h },
	{ hitBase.x,hitBase.h }
	};
	//Box�^�̉�]�̓K�p
	OG::_Rotate(angle, _v);
	//�~�̒��ɒ��_�����݂���ꍇTRUE��Ԃ�
	if ((((_v[1].x - _v[0].x)*(_ver[0].y - _v[0].y)) - ((_ver[0].x - _v[0].x)*(_v[1].y - _v[0].y))) >= b.hitBase.r*b.hitBase.r &&
		(((_v[2].x - _v[1].x)*(_ver[0].y - _v[1].y)) - ((_ver[0].x - _v[1].x)*(_v[2].y - _v[1].y))) >= b.hitBase.r*b.hitBase.r &&
		(((_v[3].x - _v[2].x)*(_ver[0].y - _v[2].y)) - ((_ver[0].x - _v[2].x)*(_v[3].y - _v[2].y))) >= b.hitBase.r*b.hitBase.r &&
		(((_v[0].x - _v[3].x)*(_ver[0].y - _v[3].y)) - ((_ver[0].x - _v[3].x)*(_v[0].y - _v[3].y))) >= b.hitBase.r*b.hitBase.r)
	{
		return true;
	}
	
	//�~�̒��ɐ��������݂���ꍇTRUE��Ԃ�
	for (int i = 0; i<4; i++) {
		if (OG::get_distance(_ver[0].x, _ver[0].y, _v[i].x, _v[i].y, _v[(i + 1) % 4].x, _v[(i + 1) % 4].y)<b.hitBase.r)
			return true;
	}
	return false;
}
//�_�Ƌ�`
bool CollisionBox::Hit(const CollisionPointer& b)
{
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
			(b.hitBase.y - _v[i].y)) -
			((b.hitBase.x - _v[i].x)*
			(_v[(i + 1) % 4].y - _v[i].y)))
			< 0)
		{
			return false;
		}
	}
	return true;
}

void CollisionBox::Rotate(const float _angle) {
	//��]�̒l���i�[
	this->angle = _angle;
}
float CollisionBox::Rotate() const
{
	return this->angle;
}
//--------------------------------------------------
//@:CollisionCircle
//--------------------------------------------------
CollisionCircle::CollisionCircle()
	:CollisionBase(1)
{
}
//�~�~��`
bool CollisionCircle::Hit(const CollisionBox& b)
{
	//���_���̃Z�b�g
	Vec2 _ver[1] = {
		{ hitBase.center_x,hitBase.center_y }
	};
	Vec2 _v[4] = {
		{ b.hitBase.x,b.hitBase.y },
	{ b.hitBase.w - 1,b.hitBase.y },
	{ b.hitBase.w - 1,b.hitBase.h },
	{ b.hitBase.x,b.hitBase.h }
	};
	//Box�^�̉�]�̓K�p
	OG::_Rotate(b.Rotate(), _v);
	//�~�̒��ɒ��_�����݂���ꍇTRUE��Ԃ�
	if ((((_v[1].x - _v[0].x)*(_ver[0].y - _v[0].y)) - ((_ver[0].x - _v[0].x)*(_v[1].y - _v[0].y))) >= hitBase.r*hitBase.r &&
		(((_v[2].x - _v[1].x)*(_ver[0].y - _v[1].y)) - ((_ver[0].x - _v[1].x)*(_v[2].y - _v[1].y))) >= hitBase.r*hitBase.r &&
		(((_v[3].x - _v[2].x)*(_ver[0].y - _v[2].y)) - ((_ver[0].x - _v[2].x)*(_v[3].y - _v[2].y))) >= hitBase.r*hitBase.r &&
		(((_v[0].x - _v[3].x)*(_ver[0].y - _v[3].y)) - ((_ver[0].x - _v[3].x)*(_v[0].y - _v[3].y))) >= hitBase.r*hitBase.r)
	{
		return true;
	}
	//�~�̒��ɐ��������݂���ꍇTRUE��Ԃ�
	for (int i = 0; i<4; i++) {
		if (OG::get_distance(_ver[0].x, _ver[0].y, _v[i].x, _v[i].y, _v[(i + 1) % 4].x, _v[(i + 1) % 4].y)<hitBase.r)
			return true;
	}
	return false;
}
//�~�~�~
bool CollisionCircle::Hit(const CollisionCircle& b)
{
	//�~�͈͓̔��ɑ���̉~�͈̔͂����݂���ꍇTRUE��Ԃ�
	if (((b.hitBase.center_x - this->hitBase.center_x)*
		(b.hitBase.center_x - this->hitBase.center_x)) +
		((b.hitBase.center_y - this->hitBase.center_y)*
		(b.hitBase.center_y - this->hitBase.center_y)) <=
			(b.hitBase.r + this->hitBase.r)*(b.hitBase.r + this->hitBase.r))
	{
		return true;
	}
	return false;
}
bool CollisionCircle::Hit(const CollisionPointer& b)
{
	//���_���̃Z�b�g
	Vec2 _ver[1] = {
		{ hitBase.center_x,hitBase.center_y }
	};
	Vec2 _v[1] = {
		{ b.hitBase.x,b.hitBase.y },
	};
	//�~�̒��ɒ��_�����݂���ꍇTRUE��Ԃ�
	if (((_ver[0].x - _v[0].x) * (_ver[0].x - _v[0].x)) + ((_ver[0].y - _v[0].y) * (_ver[0].y - _v[0].y)) <= this->hitBase.r * this->hitBase.r)
	{
		return true;
	}
	return false;
}
//--------------------------------------------------
//@:CollisionPointer
//--------------------------------------------------
CollisionPointer::CollisionPointer()
	:CollisionBase(1)
{
}
bool CollisionPointer::Hit(const CollisionBox& b)
{
	Vec2 _v[4] = {
	{ b.hitBase.x,b.hitBase.y },
	{ b.hitBase.w - 1,b.hitBase.y },
	{ b.hitBase.w - 1,b.hitBase.h },
	{ b.hitBase.x,b.hitBase.h }
	};
	OG::_Rotate(b.Rotate(), _v);
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
bool CollisionPointer::Hit(const CollisionCircle& b)
{
	//���_���̃Z�b�g
	Vec2 _ver[1] = {
		{ b.hitBase.center_x,b.hitBase.center_y }
	};
	Vec2 _v[1] = {
		{ hitBase.x,hitBase.y },
	};
	//�~�̒��ɒ��_�����݂���ꍇTRUE��Ԃ�
	if (((_ver[0].x - _v[0].x) * (_ver[0].x - _v[0].x)) + ((_ver[0].y - _v[0].y) * (_ver[0].y - _v[0].y)) <= b.hitBase.r * b.hitBase.r)
	{
		return true;
	}
	return false;
}
bool CollisionPointer::Hit(const CollisionPointer& b)
{
	return this->hitBase == b.hitBase;
}
bool CollisionPointer::Hit(const CollisionLine& b)
{
	float line_1 = sqrt(
		(b.hitBase[1].x - b.hitBase[0].x)*(b.hitBase[1].x - b.hitBase[0].x) +
		(b.hitBase[1].y - b.hitBase[0].y)*(b.hitBase[1].y - b.hitBase[0].y)
	);
	float line_2 = sqrt(
		(hitBase.x - b.hitBase[0].x)*(hitBase.x - b.hitBase[0].x) +
		(hitBase.y - b.hitBase[0].y)*(hitBase.y - b.hitBase[0].y)
	);
	if (
		((b.hitBase[1].x - b.hitBase[0].x)*(hitBase.x - b.hitBase[0].x) +
		(b.hitBase[1].y - b.hitBase[0].y)*(hitBase.x - b.hitBase[0].y)) == line_1 * line_2 &&
		line_1 >= line_2
		)
	{
		return true;
	}
	return false;
}
//--------------------------------------------------
//@:CollisionCapsule
//--------------------------------------------------
CollisionCapsule::CollisionCapsule()
	:CollisionBase(6)
{

}
bool CollisionCapsule::Hit(const CollisionCapsule& b)
{
	return false;
}
bool CollisionCapsule::Hit(const CollisionBox& b)
{
	return false;
}
bool CollisionCapsule::Hit(const CollisionCircle& b)
{
	return false;
}
bool CollisionCapsule::Hit(const CollisionPointer& b)
{
	return false;
}