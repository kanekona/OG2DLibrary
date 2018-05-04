#pragma once
#include "OGSystem\_OGsystem.h"

class Window {
private:
	GLFWimage image[1];				//�A�C�R�����
	GLuint id_;						//�A�C�R���摜��ID
	bool isIcon;					//�E�B���h�E�̃A�C�R������
	bool isVisualization;			//������
public:
	int _widht;						//��
	int _height;					//����
	char* _Name;					//Window�̖�
	bool _Screen;					//�t���X�N
	Vec2 position;					//Window�̈ʒu
	GLFWwindow *window;				//Window���
public:
	Window();						//�R���X�g���N�^
	Window(							//���L�R���X�g���N�^
		int,
		int,
		char*,
		bool,
		Vec2&);
	~Window();						//�f�X�g���N�^
	void createWindow(				//Window�𐶐�����
		int,
		int,
		char*,
		bool,
		Vec2&);
	void setIcon(std::string&);		//�A�C�R����ݒ肷��
	void LimitsWindow();			//Window�̃T�C�Y�ƃA�X�y�N�g����Œ肷��
	void WindowIcon();				//Window���A�C�R�����A�A�C�R���������������
	void Visualization();			//Window�������A���������������
	void InMouseMode(const bool);	//�}�E�X��\�������邩�����߂�
	Vec2 GetSize() const;			//Window�̃T�C�Y��Ԃ�
	Vec2 GetPos() const;			//Window�̈ʒu��Ԃ�
	void SetWindowPos(Vec2&);		//��������Window�̈ʒu��ݒ肷��
	typedef std::shared_ptr<Window> SP;//�X�}�[�g�|�C���^
	static SP Create(				//�X�}�[�g�|�C���^��Ԃ�
		int, 
		int,
		char*,
		bool,
		Vec2&);
};