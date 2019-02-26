#pragma once
#include "Texture\Texture.h"
#include "Timer\glTimer.h"
#include "FPS\FPS.h"
#include "Audio\Sound.h"
/**
*@brief ����̓ǂݍ��݂ƍĐ��ƕۑ����s��class
*/

class MovieImage
{
	//! OpenCV�s��
	cv::Mat	mat;
	//! �L���v�`�����s��
	cv::VideoCapture videoCapture;
	//!�@�ǂݍ��񂾓���̃t���[�����[�g
	float videoFramerate;
	//! 1frame����Texture�ɂ��ĕ`�悷��
	Texture texture;
	//! �X�V��FPSclass���g�p���AdeltaTime�Ōv�Z����
	FPS* fps;
	//! �w�蓮��̉����f�[�^
	Sound* sound;
	//! ����̃��[�v�ݒ�
	bool loop;
	//! �Đ����
	bool enablePlay;
	//! �A�N�e�B�u���
	bool active;
	/**
	*@brief �Œ菉����
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
	*@brief	�`��
	*@param[in] Box2D draw �`��ʒu
	*/
	void Draw(const Box2D& draw);
	/**
	*@brief	Sound�f�[�^�̎擾
	*@param[in] std::string filePath soundFilePath
	*/
	void SoundLoad(const std::string& filePath);
	/**
	*@brief	�X�V����
	*��{�I�ɂ͖��t���[���s��
	*/
	void Update();
	/**
	*@brief	���[�v�ݒ���s��
	*@param[in] bool isLoop enableLoop
	*/
	void EnableLoop(const bool isLoop);
	/**
	*@brief �Đ��ݒ���s��
	*@param[in] bool isPlay enablePlay
	*/
	void SetPlay(const bool isPlay);
	/**
	*@brief SetActive
	*@param[in] bool enable ActiveState
	*/
	void SetActive(const bool enable);
};