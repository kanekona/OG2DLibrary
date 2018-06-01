#pragma once
#include "OGSystem\_OGsystem.h"

class CollisionBox;
class CollisionCircle;
class CollisionBox
{
public:
	Box2D hitBase;						//�����蔻��	
	bool hitBox(const CollisionBox& b);		//��`�Ƃ̔���
	bool hitCircle(const CollisionCircle& b);	//�~�Ƃ̔���
	void Rotate(const float _angle);	//��]��K�p
	float angle;						//��]�l
private:
	void hitdraw();						//�m�F�p
};
class CollisionCircle
{
public:
	Circle hitBase;						//�����蔻��
	bool hitBox(const CollisionBox& b);		//��`�Ƃ̔���
	bool hitCircle(const CollisionCircle& b);	//�~�Ƃ̔���
private:
};