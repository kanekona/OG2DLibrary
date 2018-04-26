#include "FPS.h"
FPS::FPS()
{
	fps = 0.f;
	//glfw内のTimeを初期化
	glfwSetTime(0.0);
	count = 0;
	//fps計測用
	lastTime = (float)glfwGetTime();
	this->Setfps = 60.f;
	//1秒間動作の関数用
	this->setlast = (float)glfwGetTime();
}
void FPS::Initialize() {
	fps = 0.f;
	glfwSetTime(0.0);
	count = 0;
	lastTime = (float)glfwGetTime();
	this->Setfps = 60.f;
	this->setlast = (float)glfwGetTime();
}
void FPS::Update() {
	//60回動作したらその時の時間と前の時間からfpsを求める
	if (count == 60) {
		fps = count / ((float)glfwGetTime() - lastTime);
		std::cout << fps << std::endl;
		count = 0;
		lastTime = (float)glfwGetTime();
	}
	count++;
	float current = glfwGetTime();
	float elapsed = current - this->setlast;
	//秒が1秒すぎると動く
	if (elapsed >= 1.0)
	{
		for (int i = 0; i < data.size(); ++i)
		{
			this->data[i]();
		}
		this->setlast = glfwGetTime();
	}
}
	
void FPS::SetData(void data_())
{
	//関数登録する
	this->data.push_back(data_);
}
void FPS::DeleteData()
{
	//全解放
	this->data.clear();
}
FPS::~FPS()
{
	//前解放
	this->data.clear();
}
FPS::SP FPS::Create()
{
	//スマートポインタを返す
	return FPS::SP(new FPS());
}