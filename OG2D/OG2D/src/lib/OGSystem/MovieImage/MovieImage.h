#pragma once
#include "Texture\Texture.h"
#include "Timer\glTimer.h"
#include "FPS\FPS.h"
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
	*@brief	�`��
	*@param[in] Box2D draw �`��ʒu
	*/
	void Draw(const Box2D& draw);
};