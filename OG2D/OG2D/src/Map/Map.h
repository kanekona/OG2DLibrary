#pragma once
#include "OG\OGsystem.h"

class Map : public SceneTask
{
	class Base : public GameObject
	{
		//!	�}�b�v�ԍ�
		int arr;
		//!	����pID
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
		*@brief	�o�^ID���w��ԍ��ȉ������ׂ�
		*@param[in]	int id �w��ԍ�
		*@return bool �ȉ��ł����true
		*/
		bool IDCheck(const int id);
		/**
		*@brief	�o�^�ԍ����w��l�Ɠ����������ׂ�
		*@param[in]	int chip �w��l
		*@return bool �����Ȃ�true
		*/
		bool ChipCheck(const int chip);
		/**
		*@brief	ID��o�^����
		*@param[in]	int id ID�̒l
		*/
		void SetID(const int id);
		/**
		*@brief	�}�b�v�ԍ����w�肷��
		*@param[in]	int arr �w��l
		*/
		void Setarr(const int arr);
		/**
		*@brief	�o�^����Ă���}�b�v�ԍ���Ԃ�
		*@return int �}�b�v�ԍ��̒l
		*/
		int Getarr() const;
		/**
		*@brief	�o�^����Ă���ID��Ԃ�
		*@return int* ���o�^�Ȃ��nullptr
		*/
		int* GetID() const;
	};
	//! �}�b�v�`�b�v�摜
	Texture* chip_Image;
	//! �`��T�C�Y
	Vec2 drawSize;
	//! 1chip���Ƃ�Object
	std::vector<Base*> hitBase;
	/**
	*@brief	constructor
	*/
	explicit Map();
public:
	/**
	*@brief	Scene����
	*@return Map* ��������Scene
	*/
	static Map* Create();
	/**
	*@brief	destructor
	*/
	virtual ~Map();
};