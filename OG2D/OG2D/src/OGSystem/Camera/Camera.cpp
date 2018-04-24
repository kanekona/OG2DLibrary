#include "Camera.h"
//--------------------------------------------------
//@:Camera2Dclass									
//--------------------------------------------------
Camera2D::Camera2D(Box2D pos)
{
	this->cameraPos = pos;
	this->position = { 0,0 };
	this->Scale = { pos.w,pos.h };
}
Camera2D::~Camera2D()
{

}
void Camera2D::Initialize(Box2D pos)
{
	this->cameraPos = pos;
	this->position = {0,0 };
	this->Scale = { pos.w,pos.h };
}
void Camera2D::CameraUpdate() const
{
	//�s����v���W�F�N�V�������[�h�ɕύX
	glMatrixMode(GL_PROJECTION);
	//�s��̏�����
	glLoadIdentity();
	//���f�[�^�����������Ȃ��悤�l�̑��
	Box2D _camera(cameraPos);
	//�����ݒ�l����̕ύX�l
	_camera.x += this->position.x;
	_camera.y += this->position.y;
	_camera.w = this->Scale.x;
	_camera.h = this->Scale.y;
	_camera.OffsetSize();
	//�`��c���T�C�Y�̎w��
	glOrtho(_camera.x, _camera.w, _camera.h, _camera.y, -1.0f, 1.0f);
}
void Camera2D::MovePos(Vec2 est)
{
	this->position += est;
}
void Camera2D::SetPos(Vec2 est)
{
	this->position = est;
}
void Camera2D::SetSize(Vec2 size_)
{
	this->Scale = size_;
}
void Camera2D::MoveSize(Vec2 size_)
{
	this->Scale += size_;
}
Vec2 Camera2D::GetPos() const
{
	return this->position;
}
Vec2 Camera2D::GetSize() const
{
	return this->Scale;
}
Camera2D::SP Camera2D::Create(Box2D pos)
{
	return Camera2D::SP(new Camera2D(pos));
}