#pragma once
#include "OG\OGsystem.h"

class Back : public GameObject
{
	//! 画像データ
	Texture* image;
	//! 描画位置
	Box2D draw;
	//! 画像位置
	Box2D src;
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
	*@brief	constructor
	*@param[in]	const string& path
	*/
	explicit Back(const std::string& path);
	/**
	*@brief	destructor
	*/
	virtual ~Back();
};