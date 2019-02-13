#include "MovieImage.h"

MovieImage::MovieImage()
{

}
MovieImage::MovieImage(const std::string& filePath)
{

}
MovieImage::~MovieImage()
{

}
bool MovieImage::Load(const std::string& filePath)
{
	//Openしている場合閉じて読み込む
	if (!this->videoCapture.open(filePath)) 
	{
		OG::OutDebugData("log.txt", "MovieLoadError");
		return false;
	}
	this->videoFramerate = (float)videoCapture.get(CV_CAP_PROP_FPS);
	std::cout << videoFramerate << std::endl;
	texture.CreateID(1);
	//動画の映像枚数の取得
	//videoCapture.get(CV_CAP_PROP_FRAME_COUNT);
	videoCapture >> mat;
	texture.Create(mat);
	//更新速度を指定する
	fps.SetFrameRate(this->videoFramerate);
	return true;
}
void MovieImage::Draw(const Box2D& draw)
{
	//フレーム数から更新フレームを計算する
	if (fps.FrameCheck())
	{
		videoCapture >> mat;
		//動画データがあればTextureを生成する
		if (!mat.empty())
		{
			texture.Create(mat);
		}
		else
		{
			videoCapture.set(CV_CAP_PROP_POS_FRAMES, 0.0);
		}
		std::cout << "更新した\n";
	}
	else
	{
		std::cout << "更新しなかった\n";
	}
	texture.Draw(draw, Box2D(Vec2(), texture.GetTextureSize()));
}