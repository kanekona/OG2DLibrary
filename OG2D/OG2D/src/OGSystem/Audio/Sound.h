/**
*�T�E���h��ǂݍ��݁A�Đ����s��class
*�ꊇ�ǂݍ��݂����Ă���
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
	//! ���[�v�Đ�
	bool isloop_;
	//! �t�@�C���p�X
	const std::string filepath_;
	//! ����
	float volume_;
public:
	/**
	*@brief	:constructor
	*/
	explicit Sound();
	/**
	*@brief	:constructor
	*@param	:string path_ �t�@�C���̃p�X
	*@param	:bool loop ���[�v�Đ�
	*/
	explicit Sound(const std::string& path_, const bool loop = false);
	/**
	*brief	:destructor
	*/
	~Sound();
	/**
	*@brief	:�T�E���h�̓ǂݍ���
	*@param	:string path_ �t�@�C����
	*@param	:bool loop ���[�v�Đ�
	*@return:bool �ǂݍ��ݐ���true
	*/
	bool Create(const std::string& path_, const bool loop = false);
	/**
	*@brief	:�T�E���h�̍Đ�
	*/
	void Play() const;
	/**
	*@brief	:�T�E���h�̒�~
	*/
	void Stop() const;
	/**
	*@brief	:�T�E���h�̈ꎞ��~
	*/
	void Pause() const;
	/**
	*@brief	:�T�E���h�̉��ʕύX
	*@param	:float value_ ����
	*/
	void Volume(const float value_) const;
	/**
	*@brief	:�T�E���h�̃s�b�`�ύX
	*@param	:floar value_ �s�b�`
	*/
	void Pitch(const float value_) const;
	/**
	*@brief	:�T�E���h�̃��[�v�Đ�
	*@param	:bool loop_ ���[�v�̐ݒ�
	*/
	void Looping(const bool loop_) const;
	/**
	*@brief	:�T�E���h���Đ��������ׂ�
	*@return:�Đ���true
	*/
	bool IsPlay() const;
	/**
	*@brief	:���݂̍Đ����Ԃ�Ԃ�
	*@return:���݂̍Đ�����
	*/
	float CurrentTime() const;
	/**
	*@brief	:�T�E���h�̎��Ԃ�Ԃ�
	*@return:�T�E���h�̎���
	*/
	float Duration() const;
	/**
	*@brief	:�ő剹�ʂ��w�肷��
	*@param	:float maxVolume_ �ő剹��
	*/
	void SetVolume(float maxVolume_);
	/**
	*@brief	:�ݒ肳��Ă���ő剹�ʂ�Ԃ�
	*@return:float �ő剹��
	*/
	float GetVolume() const;
};