#pragma once
#include "OGSystem\_OGsystem.h"
class Camera2D
{
public:
	Camera2D();							//�R���X�g���N�^
	Camera2D(Box2D&);					//�R���X�g���N�^
	~Camera2D();						//�f�X�g���N�^
	void Initialize(Box2D&);			//������
	void CameraUpdate() const;			//�X�V����
	void MovePos(Vec2&);				//�ʒu�����Z����
	void SetPos(Vec2&);					//�ʒu��ݒ肷��	
	void SetSize(Vec2&);				//�T�C�Y��ݒ肷��
	void MoveSize(Vec2&);				//�T�C�Y�����Z����
	Vec2 GetPos() const;				//�ʒu��Ԃ�
	Vec2 GetSize() const;				//�T�C�Y��Ԃ�
	typedef std::shared_ptr<Camera2D> SP;//�X�}�[�g�|�C���^�̐���
	static SP Create(Box2D&);			//�X�}�[�g�|�C���^��Ԃ�
private:
	Box2D cameraPos;					//���ۈʒu
	Vec2 position;						//�ʒu
	Vec2 Scale;							//�T�C�Y
};