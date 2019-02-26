#pragma once
#include "Texture\Texture.h"
#include "Timer\glTimer.h"
#include "FPS\FPS.h"
#include "Audio\Sound.h"
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
	FPS* fps;
	//! 指定動画の音声データ
	Sound* sound;
	//! 動画のループ設定
	bool loop;
	//! 再生状態
	bool enablePlay;
	//! アクティブ状態
	bool active;
	/**
	*@brief 固定初期化
	*/
	void Init();
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
	/**
	*@brief	Soundデータの取得
	*@param[in] std::string filePath soundFilePath
	*/
	void SoundLoad(const std::string& filePath);
	/**
	*@brief	更新処理
	*基本的には毎フレーム行う
	*/
	void Update();
	/**
	*@brief	ループ設定を行う
	*@param[in] bool isLoop enableLoop
	*/
	void EnableLoop(const bool isLoop);
	/**
	*@brief 再生設定を行う
	*@param[in] bool isPlay enablePlay
	*/
	void SetPlay(const bool isPlay);
	/**
	*@brief SetActive
	*@param[in] bool enable ActiveState
	*/
	void SetActive(const bool enable);
};