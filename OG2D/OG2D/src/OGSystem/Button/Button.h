#pragma once
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
class Button : public SceneTask
{
	//! Buttonの当たり判定
	GameObject* collision;
	//! 現在の判定状況
	bool hitFlag;
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
	*@beief	:Object情報を返す
	*@return:GameObject* Buttonの判定
	*/
	GameObject* GetObject() const;
};