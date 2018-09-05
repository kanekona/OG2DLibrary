#include "FPS.h"
FPS::FPS()
{
	this->fps = 0.f;
	//glfw����Time��������
	glfwSetTime(0.0);
	this->count = 0;
	//fps�v���p
	this->lastTime = (float)glfwGetTime();
	this->framerate = 60;
	this->oneFrameTime = (float)glfwGetTime();
	OG::DataClear("fpsrate.og");
}
void FPS::Update() 
{
	//60�񓮍삵���炻�̎��̎��ԂƑO�̎��Ԃ���fps�����߂�
	if (this->count == this->framerate) {
		this->fps = this->count / ((float)glfwGetTime() - this->lastTime);
#if(_DEBUG)
		std::cout << this->fps << std::endl;		//�f�o�b�O���̂�fps���o��
		OG::OutDebugData("fpsrate.og", std::to_string(this->fps) + "\n");
#endif
		this->count = 0;
		this->lastTime = (float)glfwGetTime();
	}
	this->count++;
}
FPS::~FPS()
{

}
void FPS::SetFrameRate(const int rate)
{
	this->framerate = rate;
}
bool FPS::FrameCheck()
{
	if ((float)glfwGetTime() - this->oneFrameTime >= 1.f / (float)this->framerate)
	{
		this->oneFrameTime = (float)glfwGetTime();
		return true;
	}
	return false;
}