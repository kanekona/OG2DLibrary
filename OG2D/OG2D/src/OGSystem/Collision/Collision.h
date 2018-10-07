#pragma once
#include "OGSystem\_OGsystem.h"
class CollisionBase;
class CollisionBox;
class CollisionCircle;
class CollisionPointer;
class CollisionLine;
class CollisionCapsule;

/**
*namespace CT 
*@brief	生成するときに使用する型
*/
namespace CT
{
	enum CollisionType
	{
		//! 矩形
		BOX,
		//! 円
		CIRCLE,
		//! 点
		POINTER,
		//! カプセル
		CAPSULE,
		//! 線
		LINE,
		//! 無
		NON,
	};
}

/**
*@brief	判定の元
*/
class CollisionBase
{
public:
	/**
	*@brief	constructor
	*@param[in]	unsigned short vertex 頂点数
	*/
	explicit CollisionBase(const unsigned short vertex);
	/**
	*@brief	当たり判定を生成する
	*@param[in]	Vec2* pos Position
	*@param[in]	Vec2* scale Scale
	*@param[in]	Vec2* radius Radius
	*@param[in] float* angle Angle
	*/
	virtual void CreateHitBase(Vec2* pos, Vec2* scale, Vec2* radius, float* angle);
	/**
	*@brief	当たり判定を返す
	*@param[in] CollisionBase* collision 判定相手
	*@return bool true hit
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
	*@brief	矩形との判定
	*@param[in] CollisionBox* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) = 0;
	/**
	*@brief	円との判定
	*@param[in] CollisionCircle* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle*b) = 0;
	/**
	*@brief	点との判定
	*@param[in] CollisionPointer* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) = 0;
	/**
	*@brief	カプセルとの判定
	*@param[in]	CollisionCapsule* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCapsule* b) = 0;
	/**
	*@brief	線との判定
	*@param[in]	CollisionLine* b 相手のオブジェクト
	*@returnbool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionLine* b) = 0;
};
/**
*@brief	矩形判定
*/
class CollisionBox : public CollisionBase
{
	//! 回転値
	float angle;
public:
	/**
	*@brief	constructor
	*/
	explicit CollisionBox();
	//!	当たり判定
	Box2D hitBase;
	/**
	*@brief	回転値を変更する
	*@param[in] float _angle 回転値
	*/
	void Rotate(const float _angle);
	/**
	*@brief	回転値を取得する
	*@return float 回転値
	*/
	float Rotate() const;
	/**
	*@brief	当たり判定を生成する
	*/
	void CreateCollision();
	/**
	*@brief	当たり判定を返す
	*@param[in]	CollisionBase* collision 判定相手
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	矩形との判定
	*@param[in] CollisionBox* b 相手のオブジェクト
	*@return  bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	円との判定
	*@param[in] CollisionCircle* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	点との判定
	*@param[in] CollisionPointer* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	点との判定(未完成)
	*@param[in] CollisionLine* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	カプセルとの判定(未完成)
	*@param[in] CollisionCapsule* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};
/**
*@brief	円判定
*/
class CollisionCircle : public CollisionBase
{
public:
	//! 当たり判定
	Circle hitBase;
	/**
	*@brief	constructor
	*/
	explicit CollisionCircle();
	/**
	*@brief	当たり判定を生成する
	*/
	void CreateCollision();
	/**
	*@brief	当たり判定を返す
	*@param[in]	CollisionBase* collision 判定相手
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	矩形との判定
	*@param[in] CollisionBox* b 相手のオブジェクト
	*@return  bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	円との判定
	*@param[in] CollisionCircle* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	点との判定
	*@param[in] CollisionPointer* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	線との判定(未完成)
	*@param[in] CollisionLine* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	カプセルとの判定(未完成)
	*@param[in] CollisionCapsule* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};
/**
*@brief	点判定
*/
class CollisionPointer : public CollisionBase
{
public:
	//! 当たり判定
	Vec2 hitBase;
	/**
	*@brief	constructor
	*/
	explicit CollisionPointer();
	/**
	*@brief	当たり判定を生成する
	*/
	void CreateCollision();
	/**
	*@brief	当たり判定を返す
	*@param[in]	CollisionBase* collision 判定相手
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	矩形との判定
	*@param[in] CollisionBox* b 相手のオブジェクト
	*@return  bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	円との判定
	*@param[in] CollisionCircle* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	点との判定
	*@param[in] CollisionPointer* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	線との判定
	*@param[in] CollisionLine* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	カプセルとの判定(未完成)
	*@param[in] CollisionCapsule* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};
/**
*@brief	線判定
*/
class CollisionLine : public CollisionBase
{
public:
	//! 当たり判定
	Vec2 hitBase[2];
	/**
	*@brief	constructor
	*/
	explicit CollisionLine();
	/**
	*@brief	当たり判定を生成する
	*/
	void CreateCollision();
	/**
	*@brief	当たり判定を返す
	*@param[in]	CollisionBase* collision 判定相手
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	矩形との判定
	*@param[in] CollisionBox* b 相手のオブジェクト
	*@return  bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	円との判定
	*@param[in] CollisionCircle* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	点との判定
	*@param[in] CollisionPointer* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	線との判定
	*@param[in] CollisionLine* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	カプセルとの判定
	*@param[in] CollisionCapsule* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};
/**
*@brief	カプセル判定
*! 未完成
*/
class CollisionCapsule : public CollisionBase
{
public:
	//! 当たり判定
	Vec2 hitBase[2];
	/**
	*@brief	constructor
	*/
	explicit CollisionCapsule();
	/**
	*@brief	当たり判定を返す
	*@param[in]	CollisionBase* collision 判定相手
	*@return bool true hit
	*/
	bool Hit(CollisionBase* collision) override;
	/**
	*@brief	矩形との判定
	*@param[in] CollisionBox* b 相手のオブジェクト
	*@return  bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionBox* b) override;
	/**
	*@brief	円との判定
	*@param[in] CollisionCircle* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCircle* b) override;
	/**
	*@brief	点との判定
	*@param[in] CollisionPointer* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionPointer* b) override;
	/**
	*@brief	線との判定
	*@param[in] CollisionLine* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionLine* b) override;
	/**
	*@brief	カプセルとの判定
	*@param[in] CollisionCapsule* b 相手のオブジェクト
	*@return bool 当たっていればtrue
	*/
	virtual bool GetHit(CollisionCapsule* b) override;
};