#pragma once
#include "OG\OGsystem.h"
#include "Object\GameObject.h"
/**
*@brief	マウスに反応するButtonclass
*マウスと当たっていてクリックされている判定を行ってくれる
*/
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
	//! Text文字
	std::string _text;
	//! Font
	Font font;
	/**
	*@brief	constructor
	*@param[in]	Vec2 pos 生成位置
	*@param[in]	Vec2 size 生成サイズ
	*@param[in]	string name 登録名
	*/
	explicit Button(const Vec2& pos, const Vec2& size,const std::string& name);
	/**
	*@brief	更新処理
	*/
	void Update() override;
	/**
	*@brief	描画処理
	*/
	void Render2D() override;
public:
	/**
	*@brief	destructor
	*/
	virtual ~Button();
	/**
	*@brief	Button生成
	*@param[in]	const Vec2& pos 位置
	*@param[in] const Vec2& size 大きさ
	*@param[in]	const string& name 登録名
	*@return Button* 生成したButton
	*/
	static Button* Create(const Vec2& pos, const Vec2& size,const std::string& name);
	/**
	*@brief	マウスポインタとの判定を返す
	*@return bool Hit true
	*/
	bool IsMouseHit() const;
	/**
	*@brief	Buttonに設置するText
	*@param[in]	const string& text
	*/
	void SetText(const std::string& text);
};