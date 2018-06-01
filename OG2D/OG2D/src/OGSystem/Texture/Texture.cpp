#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
//--------------------------------------------------
//@:Textureclass									
//--------------------------------------------------
bool Texture::Create(const std::string& path)
{
	//GLuint id;
	//�e�N�X�`����1������������
	glGenTextures(1, &this->_TexId);
	//�e�N�X�`�����o�C���h����
	glBindTexture(GL_TEXTURE_2D, this->_TexId);
	//�摜��ǂݍ���
	int width;
	int height;
	int comp;
	std::string filepath = FileName + path;
	//�摜�f�[�^��ǂݍ���
	unsigned char *data = stbi_load(filepath.c_str(), &width, &height, &comp, 0);
	//�f�[�^�`����I��
	GLint type = (comp == 3) ? GL_RGB : GL_RGBA;
	//�摜�f�[�^��OpenGL�֑���
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data);
	this->TextureSize = Vec2(width, height);
	//���f�[�^�̔j��
	stbi_image_free(data);
	//�\���p�ݒ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	this->_materix[0] = { 0,0 };
	this->_materix[1] = { width,0 };
	this->_materix[2] = { width,height };
	this->_materix[3] = { 0,height };
	this->angle = 0.f;
	return true;
}
Texture::Texture()
	:FileName("./data/image/")
{

}
void Texture::Draw(const Box2D& draw, const Box2D& src,const Color color_) {
	//���W
	GLfloat vtx[] = {
		draw.x,draw.h,
		draw.w,draw.h,
		draw.w,draw.y,
		draw.x,draw.y,
	};
	_Rotate(angle, &vtx[0]);
	glVertexPointer(2, GL_FLOAT, 0, vtx);
	//�摜���W
	const GLfloat texuv[] = {
		src.x / TextureSize.x,src.h / TextureSize.y,
		src.w / TextureSize.x,src.h / TextureSize.y,
		src.w / TextureSize.x,src.y / TextureSize.y,
		src.x / TextureSize.x,src.y / TextureSize.y,
	};
	//0.1�ȉ��̃J���[��\�����Ȃ��A����œ��߂���Ă镔����؂蔲�����Ƃœ��߂��ꂽ�摜�ɂȂ�
	glAlphaFunc(GL_GREATER, (GLclampf)0.0);
	glTexCoordPointer(2, GL_FLOAT, 0, texuv);
	//OpenGL�ɓo�^����Ă���e�N�X�`����R�Â�
	glBindTexture(GL_TEXTURE_2D, this->_TexId);
	glColor4f(color_.red, color_.green, color_.blue, color_.alpha);
	//�`��
	//glMatrixMode(GL_TEXTURE);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA_TEST);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, 0);
}
bool Texture::Finalize()
{
	glBindTexture(GL_TEXTURE_2D, 0);
	glDeleteTextures(1, &this->_TexId);
	return true;
}
void Texture::Rotate(const float radian)
{
	this->angle = radian;
}
void Texture::_Rotate(const float radian, GLfloat *_mate)
{
	//���W�A���̒l�ɕύX
	float tora = OG::ToRadian(radian);
	//���_���w��
	Vec2 Center((*(_mate + 2) + *(_mate)) / 2, (*(_mate + 5) + *(_mate + 1)) / 2);
	//��]���̌��_�̒l�𓱂�
	GLfloat v[]
	{
		*(_mate)-Center.x,*(_mate + 1) - Center.y,
		*(_mate + 2) - Center.x,*(_mate + 3) - Center.y,
		*(_mate + 4) - Center.x,*(_mate + 5) - Center.y,
		*(_mate + 6) - Center.x,*(_mate + 7) - Center.y,
	};
	//��]�s��̐���
	GLfloat ma[4] = {
		cosf(tora),-sinf(tora),
		sinf(tora),cosf(tora),
	};
	//��]�s��̌v�Z
	*(_mate) = (*(v) * *(ma)) + (*(v + 1)* *(ma + 1));
	*(_mate + 1) = (*(v)* *(ma + 2)) + (*(v + 1)* *(ma + 3));

	*(_mate + 2) = (*(v + 2)* *(ma)) + (*(v + 3)* *(ma + 1));
	*(_mate + 3) = (*(v + 2)* *(ma + 2)) + (*(v + 3)* *(ma + 3));

	*(_mate + 4) = (*(v + 4)* *(ma)) + (*(v + 5)* *(ma + 1));
	*(_mate + 5) = (*(v + 4)* *(ma + 2)) + (*(v + 5)* *(ma + 3));

	*(_mate + 6) = (*(v + 6)* *(ma)) + (*(v + 7)* *(ma + 1));
	*(_mate + 7) = (*(v + 6)* *(ma + 2)) + (*(v + 7)* *(ma + 3));

	//��]���̌��_�̈ړ������������ɖ߂�
	*(_mate) = *(_mate)+Center.x;
	*(_mate + 1) = *(_mate + 1) + Center.y;

	*(_mate + 2) = *(_mate + 2) + Center.x;
	*(_mate + 3) = *(_mate + 3) + Center.y;

	*(_mate + 4) = *(_mate + 4) + Center.x;
	*(_mate + 5) = *(_mate + 5) + Center.y;

	*(_mate + 6) = *(_mate + 6) + Center.x;
	*(_mate + 7) = *(_mate + 7) + Center.y;
}
Vec2 Texture::GetTextureSize() const
{
	return this->TextureSize;
}
Texture::~Texture()
{
	//glDeleteTextures(1, &this->_TexId);
}