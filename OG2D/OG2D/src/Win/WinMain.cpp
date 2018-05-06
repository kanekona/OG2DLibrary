//_____________________________
//|���C���V�X�e��               
//|�����F2018/03/20       
//|�����F2018/03/23
//|�����F2018/04/26
//|____________________________
//���l���Z�萔
#define _USE_MATH_DEFINES
//�����_�덷�C��
#define _OX_EPSILON_ 0.0000001f
#include "OGSystem\OGTask.h"
//#include "ft2build.h"
//#include FT_FREETYPE_H
//���������[�N���m
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

//class Font
//{
//public:
//	Font();
//	~Font();
//	FT_Library library;
//	FT_Face face;
//	FT_GlyphSlot slot;
//	void Draw(char*, Box2D, Color = { 1,1,1,1 });
//};
//Font::Font()
//{
//	FT_Init_FreeType(&this->library);
//	FT_New_Face(this->library, "./data/font/msgothic.ttc", 0, &this->face);
//	this->slot = this->face->glyph;
//	FT_Set_Char_Size(face, 0, 16 * 64, 300, 300);
//	//�摜�f�[�^��OpenGL�֑���
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//	//�\���p�ݒ�
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//}
//Font::~Font()
//{
//	FT_Done_Face(this->face);
//	FT_Done_FreeType(this->library);
//}
//void Font::Draw(char* text, Box2D draw, Color color_)
//{
//	GLuint id;
//	glGenTextures(1, &id);
//	for (int i = 0; text[i] != '\0'; ++i)
//	{
//		draw.x = i * 128;
//		draw.OffsetSize();
//		FT_Load_Glyph(this->face, FT_Get_Char_Index(this->face, text[i]), FT_LOAD_RENDER);
//		const FT_Bitmap &bitmap = this->face->glyph->bitmap;
//
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmap.width, bitmap.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap.buffer);
//		//���W
//		GLfloat vtx[] = {
//			draw.x,draw.h,
//			draw.w,draw.h,
//			draw.w,draw.y,
//			draw.x,draw.y,
//		};
//		//_Rotate(angle, &vtx[0]);
//		glVertexPointer(2, GL_FLOAT, 0, vtx);
//		//�摜���W
//		const GLfloat texuv[] = {
//			0.f,1.f,
//			1.f,1.f,
//			1.f,0.f,
//			0.f,0.f,
//		};
//		//0.1�ȉ��̃J���[��\�����Ȃ��A����œ��߂���Ă镔����؂蔲�����Ƃœ��߂��ꂽ�摜�ɂȂ�
//		glAlphaFunc(GL_GREATER, (GLclampf)0.0);
//		glTexCoordPointer(2, GL_FLOAT, 0, texuv);
//		//OpenGL�ɓo�^����Ă���e�N�X�`����R�Â�
//		glBindTexture(GL_TEXTURE_2D, id);
//		glColor4f(color_.red, color_.green, color_.blue, color_.alpha);
//		//�`��
//		//glMatrixMode(GL_TEXTURE);
//		glEnable(GL_ALPHA_TEST);
//		glEnable(GL_TEXTURE_2D);
//		glEnableClientState(GL_VERTEX_ARRAY);
//		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//		glDrawArrays(GL_QUADS, 0, 4);
//		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//		glDisableClientState(GL_VERTEX_ARRAY);
//		glDisable(GL_TEXTURE_2D);
//		glDisable(GL_ALPHA_TEST);
//		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//
//	}
//	glDeleteTextures(1, &id);
//}
//------------------
//class��`
//------------------
_OGTK* OGTK;
//Font font;
//------------------
//�^�X�N�V�X�e��
//------------------
void TaskSystem()
{
	OGge->TaskGameUpDate();
}
void TaskRender()
{
	//font.Draw("Aa", Box2D(0, 128, 128, 128));
}
void TaskFinalize()
{
	//�������
	OGge->SetDeleteEngine(true);
}
//------------------
//������
//------------------
void Initialize() 
{
	random::Init();
	OGTK->StartTaskObject();
}
//------------------
//���
//------------------
void Finalize()
{
	
}
//------------------
//�X�V
//------------------
bool Update() {
	if (OGge->in.key.down(In::ESCAPE) || OGge->GetEnd())
	{
		TaskFinalize();
		//�E�B���h�E�̔j��
		glfwDestroyWindow(OGge->window->window);
		return true;
	}
	return false;
}
//------------------
//���C��
//------------------
int main() {
	//���������[�N���m
#if(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	//FW�̏�����
	if (!glfwInit()) {
		return -1;
	}
	//�Q�[���G���W���̐���
	OGge = new EngineSystem();
	OGTK = new _OGTK();
	//�^�X�N�̏���������
	OGTK->_myGameInitialize();
	//�Q�[���G���W���̏�����
	OGge->Initialize();
	//�g�pOpenGL��Version�w��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//�g�p����E�B���h�E��ݒ肷��
	glfwMakeContextCurrent(OGge->window->window);
	//����(�_�u���o�b�t�@�̓���ւ��^�C�~���O�̎w��)
	glfwSwapInterval(1);
#if defined(_MSC_VER)
	//GLEW������
	if (glewInit() != GLEW_OK) {
		//�E�B���h�E�ƃJ�[�\�������ׂĔj�������\�[�X��������܂��B
		glfwTerminate();
		return -1;
	}
#endif
	// �����ϊ��s���ݒ�
	glMatrixMode(GL_PROJECTION);
	//�`��͈͂̎w��
	glViewport(0, 0, OGge->window->_widht, OGge->window->_height);
	//�s��̏�����
	glLoadIdentity();
	// ����Ώۂ̍s������f�����O�r���[�s��ɐ؂�ւ��Ă���
	glMatrixMode(GL_MODELVIEW);
	//�s��̏�����
	glLoadIdentity();
	//�E�C���h�E�̍��W�̊����Ɋ�Â��ă|���S�����J�����O����
	glEnable(GL_CULL_FACE);
	//�[���̔�r���s���A�[�x�o�b�t�@���X�V����(3D�p)
	//glEnable(GL_DEPTH_TEST);
	//�@���x�N�g���̐ݒ�A���K��
	glEnable(GL_NORMALIZE);
	//�w�icolor
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//����������
	Initialize();
	delete OGTK;
	//�E�B���h�E�����݂���ꍇ���[�v
	while (!glfwWindowShouldClose(OGge->window->window)) {
		//�G���W�����̍X�V����
		OGge->Update();
		//�{���Ώۂ̍s������f���r���[�s��ɕύX
		glMatrixMode(GL_MODELVIEW);
		//�o�b�t�@���N���A���Ēl��ݒ肷��
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//�L���ɂȂ��Ă���ꍇ�A�v�Z���ꂽ�t���O�����g�J���[�l���J���[�o�b�t�@�̒l�ƃu�����h���܂��B
		glEnable(GL_BLEND);
		//�s�N�Z�����Z���w�肷��
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//�X�V����
		if (Update()) { break; }
		TaskSystem();
		//�`�揈��
		TaskRender();
		//�w�肵���E�B���h�E�̃_�u���o�b�t�@���s��
		glfwSwapBuffers(OGge->window->window);
		//�E�B���h�E�A�}�E�X�A�L�[�{�[�h�̓��͂̏�Ԃ��A�b�v�f�[�g����
		glfwPollEvents();
	}
	//���
	Finalize();
	//�Q�[���G���W���̓��e�����
	delete OGge;
	//GLFW�̃��C�u�������I������
	glfwTerminate();
}