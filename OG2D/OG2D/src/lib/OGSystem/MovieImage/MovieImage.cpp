#include "MovieImage.h"

MovieImage::MovieImage()
{
	Init();
}
MovieImage::MovieImage(const std::string& filePath)
{
	Init();
	this->Load(filePath);
}
MovieImage::~MovieImage()
{
	OG::Destroy<FPS>(fps);
}
void MovieImage::Init()
{
	this->enablePlay = true;
	this->loop = true;
	fps = new FPS();
}
bool MovieImage::Load(const std::string& filePath)
{
	//Openしている場合閉じて読み込む
	if (!this->videoCapture.open(filePath)) 
	{
		OG::OutDebugData("log.txt", "MovieLoadError");
		return false;
	}
	//動画のフレームレートの取得
	this->videoFramerate = (float)videoCapture.get(CV_CAP_PROP_FPS);
	//動画描画用にテクスチャIDを１つ取得
	texture.CreateID(1);
	//動画の映像枚数の取得
	//videoCapture.get(CV_CAP_PROP_FRAME_COUNT);
	//1frame目を行列に渡す
	videoCapture >> mat;
	//行列データからTextureデータを生成
	texture.Create(mat);
	//更新速度を指定する
	fps->SetFrameRate(this->videoFramerate);
	return true;
}
void MovieImage::Draw(const Box2D& draw)
{
	if (this->active)
	{
		texture.Draw(draw, Box2D(Vec2(), texture.GetTextureSize()));
	}
}
void MovieImage::SoundLoad(const std::string& filePath)
{
	this->sound->Create(filePath);
	sound->Play();
}
void MovieImage::Update()
{
	//フレーム数から更新フレームを計算する
	if (fps->FrameCheck())
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
	}
}
void MovieImage::EnableLoop(const bool isLoop)
{
	this->loop = isLoop;
}
void MovieImage::SetPlay(const bool isPlay)
{
	this->enablePlay = isPlay;
}
void MovieImage::SetActive(const bool enable)
{
	this->active = enable;
}