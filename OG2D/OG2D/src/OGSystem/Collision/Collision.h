#pragma once
#include "OGSystem\_OGsystem.h"
#include "OGSystem\GameEngine\GameEngine.h"
class CollisionBox;
class CollisionCircle;
class CollisionBox
{
public:
	Box2D hitBase;						//当たり判定	
	bool hitBox(CollisionBox b);		//矩形との判定
	bool hitCircle(CollisionCircle b);	//円との判定
	void Rotate(float _angle);			//回転を適用
	float angle;						//回転値
private:
	void hitdraw();						//確認用
};
class CollisionCircle
{
public:
	Circle hitBase;						//当たり判定
	bool hitBox(CollisionBox b);		//矩形との判定
	bool hitCircle(CollisionCircle b);	//円との判定
private:
};