/**
*Window�̐����A�Ǘ����s��class
*/
#pragma once
#include "OGSystem\_OGsystem.h"

class Window : private NonCopyable
{
	//! �A�C�R�����
	GLFWimage image[1];	
	//! �A�C�R���摜��ID
	GLuint id_;
	//! �E�B���h�E�̃A�C�R������
	bool enableIcon;
	//! ������
	bool isVisualization;
	//! ��
	int widht;
	//! ����
	int height;
	//! Window�̖�
	const char* _name;
	//! �t���X�N�ݒ�
	bool _screen;
	//! Window�̈ʒu
	Vec2 position;
	//! Window���
	GLFWwindow *window;	
public:
	/**
	*@brief	:constructor
	*/
	Window();
	/**
	*@brief	:constructor
	*@param	:int x windowX�T�C�Y
	*@param :int y windowY�T�C�Y
	*@param	:char* name window��
	*@param :bool flag �t���X�N�ݒ�
	*@param	:Vec2 pos window�ʒu
	*/
	Window(
		const int x,
		const int y,
		const char* name,
		const bool flag,
		const Vec2& pos);
	/**
	*@brief	:destructor
	*/
	~Window();
	/**
	*@brief	:constructor
	*@param	:int x windowX�T�C�Y
	*@param :int y windowY�T�C�Y
	*@param	:char* name window��
	*@param :bool flag �t���X�N�ݒ�
	*@param	:Vec2 pos window�ʒu
	*@return:bool �����ɐ�����true
	*/
	bool createWindow(
		const int x,
		const int y,
		char* name,
		const bool flag,
		const Vec2& pos);
	/**
	*@brief	:�A�C�R����ݒ肷��
	*@param	:string path �t�@�C���p�X
	*/
	void setIcon(const std::string& path);
	/**
	*@brief	:Window�̃T�C�Y�ƃA�X�y�N�g����Œ肷��
	*/
	void LimitsWindow();
	/**
	*@brief	:Window���A�C�R�����A�A�C�R���������������
	*/
	void WindowIcon();
	/**
	*@brief	:Window�������A���������������
	*/
	void Visualization();
	/**
	*@brief	:�}�E�X��\�������邩�����߂�
	*@param	:bool flag �\���ݒ�
	*/
	void InMouseMode(const bool flag);
	/**
	*@brief	:Window�̃T�C�Y��Ԃ�
	*@return:Vec2 Window�̃T�C�Y
	*/
	Vec2 GetSize() const;
	/**
	*@brief	:Window�̈ʒu��Ԃ�
	*@return:Vec2 Window�̈ʒu
	*/
	Vec2 GetPos() const;
	/**
	*@brief	:��������Window�̈ʒu��ݒ肷��
	*@param	:Vec2 pos Window�̈ʒu
	*/
	void SetWindowPos(const Vec2& pos);
	/**
	*@brief	:Window����Ԃ�
	*@return:GLFWWinfow* Window���
	*/
	GLFWwindow* GetWindow() const;
};