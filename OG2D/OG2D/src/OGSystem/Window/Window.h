#pragma once
#include "OGSystem\_OGsystem.h"

class Window {
private:
	GLFWimage image[1];				//�A�C�R�����
	GLuint id_;						//�A�C�R���摜��ID
	bool isIcon;					//�E�B���h�E�̃A�C�R������
	bool isVisualization;			//������
	int _widht;						//��
	int _height;					//����
	char* _Name;					//Window�̖�
	bool _Screen;					//�t���X�N
	Vec2 position;					//Window�̈ʒu
	GLFWwindow *window;				//Window���
public:
	Window();						//�R���X�g���N�^
	Window(							//���L�R���X�g���N�^
		const int,
		const int,
		char*,
		const bool,
		const Vec2&);
	~Window();						//�f�X�g���N�^
	bool createWindow(				//Window�𐶐�����
		const int,
		const int,
		char*,
		const bool,
		const Vec2&);
	void setIcon(const std::string&);		//�A�C�R����ݒ肷��
	void LimitsWindow();			//Window�̃T�C�Y�ƃA�X�y�N�g����Œ肷��
	void WindowIcon();				//Window���A�C�R�����A�A�C�R���������������
	void Visualization();			//Window�������A���������������
	void InMouseMode(const bool);	//�}�E�X��\�������邩�����߂�
	Vec2 GetSize() const;			//Window�̃T�C�Y��Ԃ�
	Vec2 GetPos() const;			//Window�̈ʒu��Ԃ�
	void SetWindowPos(const Vec2&);		//��������Window�̈ʒu��ݒ肷��
	GLFWwindow* GetWindow() const;	//Window����Ԃ�
};