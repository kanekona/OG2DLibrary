#pragma once
#include "OGSystem\_OGsystem.h"

class CollisionBox;
class CollisionCircle;
class CollisionBox
{
public:
	Box2D hitBase;						//“–‚½‚è”»’è	
	bool hitBox(const CollisionBox& b);		//‹éŒ`‚Æ‚Ì”»’è
	bool hitCircle(const CollisionCircle& b);	//‰~‚Æ‚Ì”»’è
	void Rotate(const float _angle);	//‰ñ“]‚ð“K—p
	float angle;						//‰ñ“]’l
private:
	void hitdraw();						//Šm”F—p
};
class CollisionCircle
{
public:
	Circle hitBase;						//“–‚½‚è”»’è
	bool hitBox(const CollisionBox& b);		//‹éŒ`‚Æ‚Ì”»’è
	bool hitCircle(const CollisionCircle& b);	//‰~‚Æ‚Ì”»’è
private:
};