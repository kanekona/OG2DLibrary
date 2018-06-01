#include "FPS.h"
FPS::FPS()
{
	this->fps = 0.f;
	//glfw����Time��������
	glfwSetTime(0.0);
	this->count = 0;
	//fps�v���p
	this->lastTime = (float)glfwGetTime();
}
void FPS::Update() 
{
	//60�񓮍삵���炻�̎��̎��ԂƑO�̎��Ԃ���fps�����߂�
	if (this->count == 60) {
		this->fps = this->count / ((float)glfwGetTime() - this->lastTime);
#if(_DEBUG)
		std::cout << this->fps << std::endl;		//�f�o�b�O���̂�fps���o��
#endif
		this->count = 0;
		this->lastTime = (float)glfwGetTime();
	}
	this->count++;
}
FPS::~FPS()
{

}