#include "FPS.h"
FPS::FPS()
	:startDeltaTime((float)glfwGetTime())
{
	this->fps = 0.f;
	//glfw内のTimeを初期化
	//glfwSetTime(0.0);
	this->count = 0;
	//fps計測用
	this->lastTime = (float)glfwGetTime();
	this->framerate = 60;
	this->oneFrameTime = (float)glfwGetTime();
	this->frameCount = 1;
	OG::DataClear("./data/debug/fpsrate.og");
	delta = 0.0f;
}
void FPS::Update() 
{
	//60回動作したらその時の時間と前の時間からfpsを求める
	if (this->count == this->framerate) {
		this->fps = this->count / ((float)glfwGetTime() - this->lastTime);
		std::cout << this->fps << std::endl;		//デバッグ時のみfpsを出力
		OG::OutDebugData("fpsrate.og", std::to_string(this->fps) + "\n");
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
	//( (float)glfwGetTime() - startTime ) / (1.f / (float)framerate) 何フレーム目かの計算
	//
	//if( ( (float)glfwGetTime() - startTime ) / (1.f / (float)framerate) == 0 )
	if ((float)glfwGetTime() - this->startDeltaTime >= (1.f / (float)this->framerate) * this->frameCount)
	{
		//this->oneFrameTime = (float)glfwGetTime();
		delta = (float)glfwGetTime() - oneFrameTime;
		oneFrameTime = (float)glfwGetTime();
		++frameCount;
		return true;
	}
	return false;
}
float FPS::DeltaTime()
{
	return this->delta;
}