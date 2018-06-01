#pragma once
#include "OGSystem\_OGsystem.h"

class Texture {
public:
	Texture();							//�R���X�g���N�^
	~Texture();							//�f�X�g���N�^	
	bool Create(const std::string&);	//�摜�f�[�^�̐���
	void Draw(							//�`�揈��
		const Box2D&, 
		const Box2D&,
		const Color = { 1.0f,1.0f,1.0f,1.0f });
	bool Finalize();					//�������
	void Rotate(const float);			//��]�̓K��
	Vec2 GetTextureSize() const;
private:
	GLuint _TexId;						//�e�N�X�`����ID
	Vec2 TextureSize;					//�摜�T�C�Y
	Vec2 _materix[4];					//���_���
	const std::string FileName;			//�摜�t�@�C���p�X
	void _Rotate(const float,			//���_���W����]������
				GLfloat*);
	float angle;						//��]�l
};