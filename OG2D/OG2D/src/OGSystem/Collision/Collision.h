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
*! 未完成
*/
class CollisionCapsule;
/**
*@brief	:汎用型判定
*/
class Collision;
/**
*namespace CT 生成するときに使用する型
*/
namespace CT
{
	enum CollisionType
	{
		BOX,
		CIRCLE,
		POINTER,
		CAPSULE,
		LINE,
		NON,
	};
}


class CollisionBase
{
public:
	/**
	*@brief	:当たり判定を生成する
	*@param	:Vec2* pos Position
	*@param	:Vec2* scale Scale
	*@param	:Vec2* radius Radius
	*@param :float* angle Angle
	*/
	virtual void CreateHitBase(Vec2* pos, Vec2* scale, Vec2* radius, float* angle);
	/**
	*@brief	:constructor
	*@param	:unsigned short vertex 頂点数
	*/
	explicit CollisionBase(const unsigned short vertex);
	/**
	*@brief	:当たり判定を返す
	*@param	:CollisionBase* collision 判定相手
	*@return:bool true hit
	*/
	virtual bool Hit(CollisionBase* collision) = 0;
	//! 頂点数
	const unsigned short VERTEX_NUM;
	//! Position
	Vec2* _pos;
	//! Scale
	Vec2* _scale;
	//! Radius
	Vec2* _radius;
	//! Angle
	float* _rotate;
	/**
	*@brief	:矩形との判定
	*@param :CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) = 0;
	/**
	*@brief	:円との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle*b) = 0;
	/**
	*@brief	:点との判定
	*@param :CollisionPointer b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) = 0;
	/**
	*@brief	:カプセルとの判定
	*@param	:CollisionCapsule b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCapsule* b) = 0;
	/**
	*@brief	:線との判定
	*@param	:CollisionLine b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionLine* b) = 0;
};

class CollisionBox : CollisionBase
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
	*@brief	:回転値を変更する
	*@param :float _angle 回転値
	*/
	void Rotate(const float _angle);
	/**
	*@brief	:回転値を取得する
	*@return:float 回転値
	*/
	float Rotate() const;
	/**
	*@brief	:当たり判定を生成する
	*/
	void CreateCollision();
	/**
	*@brief	:当たり判定を返す
	*@param	:CollisionBase* collision 判定相手
	*@return:bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	:矩形との判定
	*@param :CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	:円との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	:点との判定
	*@param :CollisionPointer b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	:点との判定
	*@param :CollisionLine b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionLine* b) override;
};

class CollisionCircle : CollisionBase
{
public:
	//! 当たり判定
	Circle hitBase;
	/**
	*@brief	:constructor
	*/
	explicit CollisionCircle();
	/**
	*@brief	:当たり判定を生成する
	*/
	void CreateCollision();
	/**
	*@brief	:当たり判定を返す
	*@param	:CollisionBase* collision 判定相手
	*@return:bool true hit
	*/
	virtual bool Hit(CollisionBase* collision);
	/**
	*@brief	:矩形との判定
	*@param :CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	:円との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	:点との判定
	*@param :CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) override;
};

class CollisionPointer : CollisionBase
{
public:
	//! 当たり判定
	Vec2 hitBase;
	/**
	*@brief	:constructor
	*/
	explicit CollisionPointer();
	/**
	*@brief	:当たり判定を生成する
	*/
	void CreateCollision();
	/**
	*@brief	:当たり判定を返す
	*@param	:CollisionBase* collision 判定相手
	*@return:bool true hit
	*/
	virtual bool Hit(CollisionBase* collision);
	/**
	*@brief	:矩形との判定
	*@param	:CollisionBox b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	:円との判定
	*@param	:CollisionPointer b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	:点との判定
	*@param	:CollisionCircle b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	:線との判定
	*@param	:CollisionLine b 相手のオブジェクト
	*@return:bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionLine* b) override;
};

class CollisionLine : public CollisionBase
{
public:
	Vec2 hitBase[2];
	/**
	*@brief	:constructor
	*/
	explicit CollisionLine();
	/**
	*@brief	:当たり判定を生成する
	*/
	void CreateCollision();
};

class CollisionCapsule : public CollisionBase
{
public:
	Vec2 hitBase[2];
	/**
	*@brief	:constructor
	*/
	explicit CollisionCapsule();
	/**
	*@brief	:当たり判定を返す
	*@param	:CollisionBase* collision 判定相手
	*@return:bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	bool GetHit(CollisionCapsule* b) override;
	bool GetHit(CollisionBox* b) override;
	bool GetHit(CollisionCircle* b) override;
	bool GetHit(CollisionPointer* b) override;
};