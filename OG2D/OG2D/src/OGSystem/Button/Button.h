#pragma once
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
class Button : public GameObject
{
	//! 現在の判定状況
	bool hitFlag;
	//! 画像データ
	Texture* image;
	//! 描画位置
	Box2D* draw;
	//! 描画画像位置
	Box2D* src;
	//! 画像カラー
	Color* image_color;
	/**
	*@brief	:constructor
	*@param	:Vec2 pos 生成位置
	*@param	:Vec2 size 生成サイズ
	*/
	explicit Button(const Vec2& pos, const Vec2& size);
	/**
	*@brief	:更新処理
	*/
	void Update() override;
	/**
	*@brief	:描画処理
	*/
	void Render2D() override;
public:
	/**
	*@brief	:destructor
	*/
	virtual ~Button();
	/**
	*@brief	:Button生成
	*@param	:const Vec2& pos 位置
	*@param :const Vec2& size 大きさ
	*@return:Button* 生成したButton
	*/
	static Button* Create(const Vec2& pos, const Vec2& size);
};