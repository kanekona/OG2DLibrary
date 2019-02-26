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
	//Open���Ă���ꍇ���ēǂݍ���
	if (!this->videoCapture.open(filePath)) 
	{
		OG::OutDebugData("log.txt", "MovieLoadError");
		return false;
	}
	//����̃t���[�����[�g�̎擾
	this->videoFramerate = (float)videoCapture.get(CV_CAP_PROP_FPS);
	//����`��p�Ƀe�N�X�`��ID���P�擾
	texture.CreateID(1);
	//����̉f�������̎擾
	//videoCapture.get(CV_CAP_PROP_FRAME_COUNT);
	//1frame�ڂ��s��ɓn��
	videoCapture >> mat;
	//�s��f�[�^����Texture�f�[�^�𐶐�
	texture.Create(mat);
	//�X�V���x���w�肷��
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
	//�t���[��������X�V�t���[�����v�Z����
	if (fps->FrameCheck())
	{
		videoCapture >> mat;
		//����f�[�^�������Texture�𐶐�����
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