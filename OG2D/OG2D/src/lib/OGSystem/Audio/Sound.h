/**
*サウンドを読み込み、再生を行うclass
*
*一括読み込みをしている
*/
#pragma once
#include "Audio.h"
class Sound
{
private:
	//! bufferData
	std::shared_ptr<Buffer> buffer;
	//! sourceData
	std::shared_ptr<Source> source;
	//! ループ再生
	bool isloop_;
	//! ファイルパス
	const std::string filepath_;
	//! 音量
	float volume_;
public:
	/**
	*@brief	constructor
	*/
	explicit Sound();
	/**
	*@brief	constructor
	*@param[in]	string path_ ファイルのパス
	*@param[in]	bool loop ループ再生
	*/
	explicit Sound(const std::string& path_, const bool loop = false);
	/**
	*brief	destructor
	*/
	virtual ~Sound();
	/**
	*@brief	サウンドの読み込み
	*@param[in]	string path_ ファイル名
	*@param[in]	bool loop ループ再生
	*@return bool 読み込み成功true
	*/
	bool Create(const std::string& path_, const bool loop = false);
	/**
	*@brief	サウンドの再生
	*/
	void Play() const;
	/**
	*@brief	サウンドの停止
	*/
	void Stop() const;
	/**
	*@brief	サウンドの一時停止
	*/
	void Pause() const;
	/**
	*@brief	サウンドの音量変更
	*@param[in]	float value_ 音量
	*/
	void Volume(const float value_) const;
	/**
	*@brief	サウンドのピッチ変更
	*@param[in]	floar value_ ピッチ
	*/
	void Pitch(const float value_) const;
	/**
	*@brief	サウンドのループ再生
	*@param[in]	bool loop_ ループの設定
	*/
	void Looping(const bool loop_) const;
	/**
	*@brief	サウンドが再生中か調べる
	*@return 再生中true
	*/
	bool IsPlay() const;
	/**
	*@brief	現在の再生時間を返す
	*@return 現在の再生時間
	*/
	float CurrentTime() const;
	/**
	*@brief	サウンドの時間を返す
	*@return サウンドの時間
	*/
	float Duration() const;
	/**
	*@brief	最大音量を指定する
	*@param[in]	float maxVolume_ 最大音量
	*/
	void SetVolume(float maxVolume_);
	/**
	*@brief	設定されている最大音量を返す
	*@return float 最大音量
	*/
	float GetVolume() const;
};