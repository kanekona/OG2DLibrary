#include "Camera.h"
//--------------------------------------------------
//@:Camera2Dclass									
//--------------------------------------------------
Camera2D::Camera2D()
{

}
Camera2D::Camera2D(const Box2D& pos)
{
	//�e�l���Z�b�g����
	this->cameraPos = pos;
	this->position = { 0,0 };
	this->Scale = { pos.w,pos.h };
}
Camera2D::~Camera2D()
{

}
void Camera2D::Initialize(const Box2D& pos)
{
	//�e�l���Z�b�g����
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
void Camera2D::MovePos(const Vec2& est)
{
	//�ʒu�����Z����
	this->position += est;
}
void Camera2D::SetPos(const Vec2& est)
{
	//�ʒu���㏑������
	this->position = est;
}
void Camera2D::SetSize(const Vec2& size_)
{
	//�T�C�Y���㏑������
	this->Scale = size_;
}
void Camera2D::MoveSize(const Vec2& size_)
{
	//�T�C�Y�����Z����
	this->Scale += size_;
}
Vec2 Camera2D::GetPos() const
{
	//�ʒu��Ԃ�
	return this->position;
}
Vec2 Camera2D::GetSize() const
{
	//�T�C�Y��Ԃ�
	return this->Scale;
}