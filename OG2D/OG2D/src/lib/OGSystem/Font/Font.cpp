//#include "Font.h"
//Font::Font()
//{
//	FT_Init_FreeType(&this->ft_library);
//	if (!this->ft_library)
//	{
//		std::cout << "FontInitError" << std::endl;
//		return;
//	}
//	//"" -> �g�p�t�H���g�w��
//	FT_Error error = FT_New_Face(this->ft_library, "data/font/msgothic.ttc", 0, &this->face);
//	FT_Set_Char_Size(this->face, 0, 16 * 64, 300, 300);
//	glGenTextures(1, &this->texID);
//}
//Font::~Font()
//{
//	glDeleteTextures(1, &this->texID);
//	FT_Done_Face(this->face);
//	FT_Done_FreeType(this->ft_library);
//}
//void Font::Draw(const std::string& text, unsigned int fontSize, const Vec2& pos)
//{
//	FT_Load_Char(this->face, 'a', FT_LOAD_RENDER);
//	FT_Bitmap bm = this->face->glyph->bitmap;
//	GLfloat vtx[] = {
//		100,228,
//		228,228,
//		228,100,
//		100,100,
//	};
//	glVertexPointer(2, GL_FLOAT, 0, vtx);
//	glBindTexture(GL_TEXTURE_2D, this->texID);
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bm.width, bm.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, bm.buffer);
//	//�\���p�ݒ�
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	//�摜���W
//	const GLfloat texuv[] = {
//		0,1,
//		1,1,
//		1,0,
//		0,0,
//	};
//	//0.1�ȉ��̃J���[��\�����Ȃ��A����œ��߂���Ă镔����؂蔲�����Ƃœ��߂��ꂽ�摜�ɂȂ�
//	glAlphaFunc(GL_GREATER, (GLclampf)0.0);
//	glTexCoordPointer(2, GL_FLOAT, 0, texuv);
//	//�`��
//	//glMatrixMode(GL_TEXTURE);
//	glEnable(GL_ALPHA_TEST);
//	glEnable(GL_TEXTURE_2D);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//	glDrawArrays(GL_QUADS, 0, 4);
//	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisable(GL_TEXTURE_2D);
//	glDisable(GL_ALPHA_TEST);
//	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//	glBindTexture(GL_TEXTURE_2D, 0);
//}