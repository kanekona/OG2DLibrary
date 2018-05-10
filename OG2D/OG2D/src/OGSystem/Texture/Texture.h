#pragma once
#include "OGSystem\_OGsystem.h"

class Texture {
public:
	Texture();							//�R���X�g���N�^
	~Texture();							//�f�X�g���N�^	
	bool Create(std::string&);			//�摜�f�[�^�̐���
	void Draw(							//�`�揈��
		Box2D, 
		Box2D, 
		Color = { 1.0f,1.0f,1.0f,1.0f });
	bool Finalize();					//�������
	void Rotate(float);				//��]�̓K��
private:
	GLuint _TexId;						//�e�N�X�`����ID
	Vec2 TextureSize;					//�摜�T�C�Y
	Vec2 _materix[4];					//���_���
	const std::string FileName = "./data/image/";//�摜�t�@�C���p�X
	void _Rotate(float,					//���_���W����]������
				GLfloat*);
	float angle;						//��]�l
};