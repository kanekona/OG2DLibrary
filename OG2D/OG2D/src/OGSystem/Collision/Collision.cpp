#include "Collision.h"
//--------------------------------------------------
//@:Collisionclass									
//--------------------------------------------------
//�����`�~�����`
bool CollisionBox::hitBox(const CollisionBox& b)
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
		Vec2 mainvec = _v[(i + 1) % 4] - _v[i % 4];
	//	for (int j = 0; j < 4; ++j)
		{
			/*Vec2 v3 = _ver[j % 4] - _v[i % 4];
			Vec2 v4 = _ver[(j + 1) % 4] - _v[i % 4];
			if ((((mainvec.x * v3.y) - (mainvec.y * v3.x))*((mainvec.x * v4.y) - (mainvec.y * v4.x))) < 0)
			{
				return true;
			}*/
			if (
				((mainvec.x * (_ver[0].y - _v[i].y)) - (mainvec.y * (_ver[0].x - _v[i].x)))*
				((mainvec.x * (_ver[1].y - _v[i].y)) - (mainvec.y * (_ver[1].x - _v[i].x))) < 0 ||
				((mainvec.x * (_ver[1].y - _v[i].y)) - (mainvec.y * (_ver[1].x - _v[i].x)))*
				((mainvec.x * (_ver[2].y - _v[i].y)) - (mainvec.y * (_ver[2].x - _v[i].x))) < 0 ||
				((mainvec.x * (_ver[2].y - _v[i].y)) - (mainvec.y * (_ver[2].x - _v[i].x)))*
				((mainvec.x * (_ver[3].y - _v[i].y)) - (mainvec.y * (_ver[3].x - _v[i].x))) < 0 ||
				((mainvec.x * (_ver[3].y - _v[i].y)) - (mainvec.y * (_ver[3].x - _v[i].x)))*
				((mainvec.x * (_ver[0].y - _v[i].y)) - (mainvec.y * (_ver[0].x - _v[i].x))) < 0
				)
			{
				return true;
			}
		}
	}
	return false;
}
//�����`�~�~
bool CollisionBox::hitCircle(const CollisionCircle& b)
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
	if ((((_v[1].x - _v[0].x)*(_ver[0].y - _v[0].y)) - ((_ver[0].x - _v[0].x)*(_v[1].y - _v[0].y))) <= b.hitBase.r*b.hitBase.r &&
		(((_v[2].x - _v[1].x)*(_ver[0].y - _v[1].y)) - ((_ver[0].x - _v[1].x)*(_v[2].y - _v[1].y))) <= b.hitBase.r*b.hitBase.r &&
		(((_v[3].x - _v[2].x)*(_ver[0].y - _v[2].y)) - ((_ver[0].x - _v[2].x)*(_v[3].y - _v[2].y))) <= b.hitBase.r*b.hitBase.r &&
		(((_v[0].x - _v[3].x)*(_ver[0].y - _v[3].y)) - ((_ver[0].x - _v[3].x)*(_v[0].y - _v[3].y))) <= b.hitBase.r*b.hitBase.r)
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
//�~�~�����`
bool CollisionCircle::hitBox(const CollisionBox& b)
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
	OG::_Rotate(b.angle, _v);
	//�~�̒��ɒ��_�����݂���ꍇTRUE��Ԃ�
	if ((((_v[1].x - _v[0].x)*(_ver[0].y - _v[0].y)) - ((_ver[0].x - _v[0].x)*(_v[1].y - _v[0].y))) <= hitBase.r*hitBase.r &&
		(((_v[2].x - _v[1].x)*(_ver[0].y - _v[1].y)) - ((_ver[0].x - _v[1].x)*(_v[2].y - _v[1].y))) <= hitBase.r*hitBase.r &&
		(((_v[3].x - _v[2].x)*(_ver[0].y - _v[2].y)) - ((_ver[0].x - _v[2].x)*(_v[3].y - _v[2].y))) <= hitBase.r*hitBase.r &&
		(((_v[0].x - _v[3].x)*(_ver[0].y - _v[3].y)) - ((_ver[0].x - _v[3].x)*(_v[0].y - _v[3].y))) <= hitBase.r*hitBase.r)
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
bool CollisionCircle::hitCircle(const CollisionCircle& b)
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
//�`��m�F�p(�����g��Ȃ�)
void CollisionBox::hitdraw() {

}
void CollisionBox::Rotate(const float _angle) {
	//��]�̒l���i�[
	this->angle = _angle;
}