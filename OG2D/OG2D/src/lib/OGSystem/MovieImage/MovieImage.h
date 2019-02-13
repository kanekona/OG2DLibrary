#pragma once
#include "Texture\Texture.h"
#include "Timer\glTimer.h"
#include "FPS\FPS.h"
/**
*@brief 童画の読み込みと再生と保存を行うclass
*/

class MovieImage
{
	//! OpenCV行列
	cv::Mat	mat;
	//! キャプチャを行う
	cv::VideoCapture videoCapture;
	//!　読み込んだ動画のフレームレート
	float videoFramerate;
	//! 1frame分をTextureにして描画する
	Texture texture;
	//! 更新にFPSclassを使用し、deltaTimeで計算する
	FPS fps;
public:
	/**
	*@brief	DefaultConstructor
	*/
	explicit MovieImage();
	/**
	*@brief	constructor
	*@param[in] std::string filePath VideoFilePath
	*/
	explicit MovieImage(const std::string& filePath);
	/**
	*@brief	LoadVideoFile
	*@param[in] std::string filePath VideoFilePath
	*/
	bool Load(const std::string& filePath);
	/**
	*@brief	destructor
	*/
	virtual ~MovieImage();
	/**
	*@brief	描画
	*@param[in] Box2D draw 描画位置
	*/
	void Draw(const Box2D& draw);
};