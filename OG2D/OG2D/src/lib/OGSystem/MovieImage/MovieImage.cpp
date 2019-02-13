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
	//Open���Ă���ꍇ���ēǂݍ���
	if (!this->videoCapture.open(filePath)) 
	{
		OG::OutDebugData("log.txt", "MovieLoadError");
		return false;
	}
	this->videoFramerate = (float)videoCapture.get(CV_CAP_PROP_FPS);
	std::cout << videoFramerate << std::endl;
	texture.CreateID(1);
	//����̉f�������̎擾
	//videoCapture.get(CV_CAP_PROP_FRAME_COUNT);
	videoCapture >> mat;
	texture.Create(mat);
	//�X�V���x���w�肷��
	fps.SetFrameRate(this->videoFramerate);
	return true;
}
void MovieImage::Draw(const Box2D& draw)
{
	//�t���[��������X�V�t���[�����v�Z����
	if (fps.FrameCheck())
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
		std::cout << "�X�V����\n";
	}
	else
	{
		std::cout << "�X�V���Ȃ�����\n";
	}
	texture.Draw(draw, Box2D(Vec2(), texture.GetTextureSize()));
}