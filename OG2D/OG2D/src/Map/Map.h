#pragma once
#include "OG\OGsystem.h"

class Map : public SceneTask
{
	class Base : public GameObject
	{
		//!	マップ番号
		int arr;
		//!	判定用ID
		int* _id;
	public:
		/**
		*@brief	constructor
		*/
		explicit Base();
		/**
		*@brief	destructor
		*/
		virtual ~Base();
		/**
		*@brief	登録IDが指定番号以下か調べる
		*@param[in]	int id 指定番号
		*@return bool 以下であればtrue
		*/
		bool IDCheck(const int id);
		/**
		*@brief	登録番号が指定値と等しいか調べる
		*@param[in]	int chip 指定値
		*@return bool 同じならtrue
		*/
		bool ChipCheck(const int chip);
		/**
		*@brief	IDを登録する
		*@param[in]	int id IDの値
		*/
		void SetID(const int id);
		/**
		*@brief	マップ番号を指定する
		*@param[in]	int arr 指定値
		*/
		void Setarr(const int arr);
		/**
		*@brief	登録されているマップ番号を返す
		*@return int マップ番号の値
		*/
		int Getarr() const;
		/**
		*@brief	登録されているIDを返す
		*@return int* 未登録ならばnullptr
		*/
		int* GetID() const;
	};
	//! マップチップ画像
	Texture* chip_Image;
	//! 描画サイズ
	Vec2 drawSize;
	//! 1chipごとのObject
	std::vector<Base*> hitBase;
	/**
	*@brief	constructor
	*/
	explicit Map();
public:
	/**
	*@brief	Scene生成
	*@return Map* 生成したScene
	*/
	static Map* Create();
	/**
	*@brief	destructor
	*/
	virtual ~Map();
};