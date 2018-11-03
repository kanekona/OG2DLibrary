#pragma once
#include "OG\_OGsystem.h"
#include "Collision\Collision.h"
/**
*@brief	2DCamera
*
*GL機能を使用し2D上でのカメラを扱うclass
*
*既存GameEngineを使用している場合は内部で宣言されている
*
*使用しない場合は2Dの描画のために１つ生成する必要がある
*/
class Camera2D : private NonCopyable
{
	//!	実際位置
	Box2D cameraPos;
	//!	位置
	Vec2 position;
	//! サイズ
	Vec2 Scale;
	//! 投影行列を保存しておく配列
	GLfloat projectionMatrix[16];
	//! 判定用
	CollisionCircle collision;
	//! Collision用変数
	Vec2 radius;
	//! Collision用変数
	float angle;
	//! Collision用Pos
	Vec2 centerPos;
	//! Collision用Scale
	Vec2 direScale;
public:
	/**
	*@brief	constructor
	*/
	explicit Camera2D();
	/**
	*@brief	constructor
	*@param[in]	const Box2D& b 位置とサイズ
	*/
	explicit Camera2D(const Box2D& b);
	/**
	*@brief	destructor
	*/
	virtual ~Camera2D();
	/**
	*@brief	初期化処理
	*@param[in]	const Box2D& b 位置とサイズ
	*/
	void Initialize(const Box2D& b);
	/**
	*@brief	更新処理
	*/
	void Update();
	/**
	*@brief	位置を移動させる
	*@param[in] const Vec2& move 移動値
	*/
	void MovePos(const Vec2& move);
	/**
	*@brief	位置を設定する
	*@param[in]	const Vec2& pos 位置
	*/
	void SetPos(const Vec2& pos);
	/**
	*@brief	サイズを設定する
	*@param[in]	const Vec2& size 大きさ
	*/
	void SetSize(const Vec2& size);
	/**
	*@brief	サイズを動かす
	*@param[in]	const Vec2& move 移動値
	*/
	void MoveSize(const Vec2& move);
	/**
	*@brief	カメラ位置のX座標を設定する
	*@param[in]	float x 座標値
	*/
	void SetPos_x(const float& x);
	/**
	*@brief	カメラ位置のY座標を設定する
	*@param[in]	float y 座標値
	*/
	void SetPos_y(const float& y);
	/**
	*@brief	カメラの横サイズを変える
	*@param[in]	float w 横サイズ
	*/
	void SetSize_w(const float& w);
	/**
	*@brief	カメラの縦サイズを変える
	*@param[in]	float w 縦サイズ
	*/
	void SetSize_h(const float& h);
	/**
	*@brief	カメラの位置を返す
	*@return Vec2 カメラ位置
	*/
	Vec2 GetPos() const;
	/**
	*@brief	カメラのサイズを返す
	*@return Vec2 カメラの大きさ
	*/
	Vec2 GetSize() const;
	/**
	*@brief	投影行列を登録する
	*@param[in] float left 左
	*@param[in] float right 右
	*@param[in] float buttom 下
	*@param[in] float top 上
	*@param[in] float nearVal 手前
	*@param[in] float farVal 奥
	*/
	void SetProjectionMatrix(
		const float left, const float right,
		const float buttom, const float top,
		const float nearVal, const float farVal);
	/**
	*@brief	投影行列を取得する
	*@return GLfloat* 投影行列
	*/
	GLfloat* GetProjectionMatrix();
	/**
	*@brief Camera判定を取得
	*@return CollisionCircle* 判定
	*/
	CollisionCircle* GetCollision();
};