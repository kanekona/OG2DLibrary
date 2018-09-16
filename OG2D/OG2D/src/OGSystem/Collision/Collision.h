/**
*Box2D,Circleを使用し当たり判定を行うclass
*/
#pragma once
#include "OGSystem\_OGsystem.h"
/**
*@brief	:判定の元
*/
class CollisionBase;
/**
*@brief	:矩形判定
*/
class CollisionBox;
/**
*@brief	:円判定
*/
class CollisionCircle;
/**
*@brief	:点判定
*/
class CollisionPointer;

class CollisionBase
{
	virtual bool hitBox(const CollisionBox& b);
	virtual bool hitCircle(const CollisionCircle& b);
	virtual bool hitPointer(const CollisionPointer& b);
public:
	explicit CollisionBase(const unsigned short vertex);
	const unsigned short VERTEX_NUM;
};

class CollisionBox : public CollisionBase
{
public:
	/**
	*@brief	:constructor
	*/
	explicit CollisionBox();
	//!	当たり判定
	Box2D hitBase;
	/**
	*@brief	:矩形との判定
	*@param :CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitBox(const CollisionBox& b);
	/**
	*@brief	:円との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitCircle(const CollisionCircle& b);
	/**
	*@brief	:点との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitPointer(const CollisionPointer& b);
	/**
	*@brief	:回転値を変更する
	*@param :float _angle 回転値
	*/
	void Rotate(const float _angle);
	/**
	*@brief	:回転値を取得する
	*@return:float 回転値
	*/
	float Rotate() const;
private:
	//! 回転値
	float angle;
};
class CollisionCircle : public CollisionBase
{
public:
	/**
	*@brief	:constructor
	*/
	explicit CollisionCircle();
	//! 当たり判定
	Circle hitBase;
	/**
	*@brief	:矩形との判定
	*@param :CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitBox(const CollisionBox& b);
	/**
	*@brief	:円との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitCircle(const CollisionCircle& b);
private:
};

class CollisionPointer : public CollisionBase
{
public:
	explicit CollisionPointer();
	Vec2 hitBase;
	/*bool hitBox(const CollisionBox& b) override;
	bool hitPointer(const CollisionPointer& b) override;
	bool hitCircle(const CollisionCircle& b) override;*/
};