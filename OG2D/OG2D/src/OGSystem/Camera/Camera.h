#pragma once
#include "OGSystem\_OGsystem.h"
class Camera2D
{
public:
	Camera2D();							//�R���X�g���N�^
	Camera2D(const Box2D&);					//�R���X�g���N�^
	~Camera2D();						//�f�X�g���N�^
	void Initialize(const Box2D&);			//������
	void CameraUpdate() const;			//�X�V����
	void MovePos(const Vec2&);				//�ʒu�����Z����
	void SetPos(const Vec2&);					//�ʒu��ݒ肷��	
	void SetSize(const Vec2&);				//�T�C�Y��ݒ肷��
	void MoveSize(const Vec2&);				//�T�C�Y�����Z����
	Vec2 GetPos() const;				//�ʒu��Ԃ�
	Vec2 GetSize() const;				//�T�C�Y��Ԃ�
private:
	Box2D cameraPos;					//���ۈʒu
	Vec2 position;						//�ʒu
	Vec2 Scale;							//�T�C�Y
};