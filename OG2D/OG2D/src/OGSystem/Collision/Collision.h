#pragma once
#include "OGSystem\_OGsystem.h"
#include "OGSystem\GameEngine\GameEngine.h"
class CollisionBox;
class CollisionCircle;
class CollisionBox
{
public:
	Box2D hitBase;						//�����蔻��	
	bool hitBox(CollisionBox& b);		//��`�Ƃ̔���
	bool hitCircle(CollisionCircle& b);	//�~�Ƃ̔���
	void Rotate(float _angle);			//��]��K�p
	float angle;						//��]�l
private:
	void hitdraw();						//�m�F�p
};
class CollisionCircle
{
public:
	Circle hitBase;						//�����蔻��
	bool hitBox(CollisionBox& b);		//��`�Ƃ̔���
	bool hitCircle(CollisionCircle& b);	//�~�Ƃ̔���
private:
};