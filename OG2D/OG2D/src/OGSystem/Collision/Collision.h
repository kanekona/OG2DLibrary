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
/**
*@brief	:線判定
*/
class CollisionLine;
/**
*@brief	:カプセル判定
*/
class CollisionCapsule;

class CollisionBase
{
	/**
	*@brief	:矩形との判定
	*@param :CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool hitBox(const CollisionBox& b);
	/**
	*@brief	:円との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool hitCircle(const CollisionCircle& b);
	/**
	*@brief	:点との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool hitPointer(const CollisionPointer& b);
	/**
	*@brief	:カプセルとの判定
	*@param	:CollisionCapsule b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool hitCapsule(const CollisionCapsule& b);
	/**
	*@brief	:線との判定
	*@param	:CollisionLine b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool hitLine(const CollisionLine& b);
public:
	/**
	*@brief	:constructor
	*@param	:unsigned short vertex 頂点数
	*/
	explicit CollisionBase(const unsigned short vertex);
	//! 頂点数
	const unsigned short VERTEX_NUM;
};

class CollisionBox : public CollisionBase
{
	//! 回転値
	float angle;
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
	bool hitBox(const CollisionBox& b) override;
	/**
	*@brief	:円との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitCircle(const CollisionCircle& b) override;
	/**
	*@brief	:点との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitPointer(const CollisionPointer& b) override;
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
};
class CollisionCircle : public CollisionBase
{
public:
	//! 当たり判定
	Circle hitBase;
	/**
	*@brief	:constructor
	*/
	explicit CollisionCircle();
	/**
	*@brief	:矩形との判定
	*@param :CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitBox(const CollisionBox& b) override;
	/**
	*@brief	:円との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitCircle(const CollisionCircle& b) override;
	/**
	*@brief	:点との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitPointer(const CollisionPointer& b) override;
private:
};
class CollisionPointer : public CollisionBase
{
public:
	//! 当たり判定
	Vec2 hitBase;
	/**
	*@brief	:constructor
	*/
	explicit CollisionPointer();
	/**
	*@brief	:矩形との判定
	*@param	:CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitBox(const CollisionBox& b) override;
	/**
	*@brief	:円との判定
	*@param	:CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitPointer(const CollisionPointer& b) override;
	/**
	*@brief	:点との判定
	*@param	:CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitCircle(const CollisionCircle& b) override;
	/**
	*@brief	:線との判定
	*@param	:CollisionLine b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	bool hitLine(const CollisionLine& b) override;
};
class CollisionLine : public CollisionBase
{
public:
	Vec2 hitBase[2];
	/**
	*@brief	:constructor
	*/
	explicit CollisionLine();
};
class CollisionCapsule : public CollisionBase
{
public:
	Vec2 hitBase[2];
	/**
	*@brief	:constructor
	*/
	explicit CollisionCapsule();
	bool hitCapsule(const CollisionCapsule& b) override;
	bool hitBox(const CollisionBox& b) override;
	bool hitCircle(const CollisionCircle& b) override;
	bool hitPointer(const CollisionPointer& b) override;
};