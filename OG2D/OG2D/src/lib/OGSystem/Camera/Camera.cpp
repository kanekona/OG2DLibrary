#include "Camera.h"
#include "Shader\shader.h"
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
	this->angle = 0.0f;
	this->radius = { 1,1 };
}
Camera2D::~Camera2D()
{

}
void Camera2D::Initialize(const Box2D& pos)
{
	//�e�l���Z�b�g����
	this->cameraPos = pos;
	this->position = { 0,0 };
	this->Scale = { pos.w,pos.h };
	this->angle = 0.0f;
	this->radius = { 1,1 };
}
void Camera2D::Update()
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
	this->centerPos = { this->position.x + this->Scale.x / 2,this->position.y + this->Scale.y / 2 };
	this->direScale = this->Scale * 1.5f;
	this->collision.CreateHitBase(&this->centerPos, &this->direScale, &this->radius, &this->angle);
	//glOrtho(_camera.x, _camera.w, _camera.h, _camera.y, -1.0f, 1.0f);
	this->SetProjectionMatrix(_camera.x, _camera.w, _camera.h, _camera.y, -2000.0f, 2000.0f);
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
void Camera2D::SetPos_x(const float& x_)
{
	this->position.x = x_;
}
void Camera2D::SetPos_y(const float& y_)
{
	this->position.y = y_;
}
void Camera2D::SetSize_w(const float& w_)
{
	this->Scale.x = w_;
}
void Camera2D::SetSize_h(const float& h_)
{
	this->Scale.y = h_;
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
void Camera2D::SetProjectionMatrix(float cl, float cr, float cb, float ct, float cn, float cf)
{
	projectionMatrix[0] = 2.f / (cr - cl);
	projectionMatrix[1] = 0.f;
	projectionMatrix[2] = 0.f;
	projectionMatrix[3] = (cr + cl) / (cr - cl) * -1;
	projectionMatrix[4] = 0.f;
	projectionMatrix[5] = 2.f / (ct - cb);
	projectionMatrix[6] = 0.f;
	projectionMatrix[7] = (ct + cb) / (ct - cb) * -1;
	projectionMatrix[8] = 0.f;
	projectionMatrix[9] = 0.f;
	projectionMatrix[10] = 2.f / (cf - cn);
	projectionMatrix[11] = (cf + cn) / (cf - cn) * -1;
	projectionMatrix[12] = 0.f;
	projectionMatrix[13] = 0.f;
	projectionMatrix[14] = 0.f;
	projectionMatrix[15] = 1.0f;
}
GLfloat* Camera2D::GetProjectionMatrix()
{
	return this->projectionMatrix;
}
CollisionCircle* Camera2D::GetCollision()
{
	return &this->collision;
}