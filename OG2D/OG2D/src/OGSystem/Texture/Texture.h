#pragma once
#include "OGSystem\_OGsystem.h"

class Texture {
public:
	Texture();							//�R���X�g���N�^
	~Texture();							//�f�X�g���N�^	
	void Create(std::string _path);		//�摜�f�[�^�̐���
	void Draw(							//�`�揈��
		Box2D draw, 
		Box2D src, 
		Color color_ = { 1.0f,1.0f,1.0f,1.0f });
	void Finalize();					//�������
	void Rotate(float radian);			//��]�̓K��
private:
	GLuint _TexId;						//�e�N�X�`����ID
	Vec2 TextureSize;					//�摜�T�C�Y
	Vec2 _materix[4];					//���_���
	const std::string FileName = "./data/image/";//�摜�t�@�C���p�X
	void _Rotate(float radian,			//���_���W����]������
				GLfloat *mate);
	float angle;						//��]�l
};