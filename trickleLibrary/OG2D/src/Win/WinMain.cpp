//______________________________//
//|���C���V�X�e��               |//
//|�����F2018/03/20���q��       |//
//|____________________________|//
#define _USE_MATH_DEFINES
//�����_�덷�C��
#define _OX_EPSILON_ 0.0000001f
#define STB_IMAGE_IMPLEMENTATION
#include "ft2build.h"
#include FT_FREETYPE_H
#include "OGSystem\OGTask.h"
//------------------
//class��`
//------------------
FPS fps;
_OGTK OGTK;
//------------------
//�^�X�N�V�X�e��
//------------------
void TaskSystem()
{
	OGTK._myGameUpDate();
}
void TaskRender()
{
	OGTK._myGameRender2D();
	OGTK._myGameRender3D();
}
void TaskFinalize()
{
	OGTK._myGameFinalize();
}
//------------------
//������
//------------------
void Initialize() {
	fps.Initialize();
	Key::Initialize(OGTK._window.window);
}
//------------------
//�X�V
//------------------
void Update() {
	if (Key::KeyInputDown(GLFW_KEY_ESCAPE))
	{
		TaskFinalize();
		//�E�B���h�E�̔j��
		glfwDestroyWindow(OGTK._window.window);
		//GLFW�̃��C�u�������I������
		glfwTerminate();
		//�A�v���P�[�V�������I������
		exit(0);
	}
	fps.Update();
}
//------------------
//���
//------------------
void Finalize() 
{
	Key::Finalize();
}
//------------------
//���C��
//------------------
int main() {
	//FW�̏�����
	if (!glfwInit()) {
		return -1;
	}
	OGTK._myGameInitialize();
	//�g�pOpenGL��Version�w��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//�g�p����E�B���h�E��ݒ肷��
	glfwMakeContextCurrent(OGTK._window.window);
	//����(�_�u���o�b�t�@�̓���ւ��^�C�~���O�̎w��)
	glfwSwapInterval(1);
#if defined(_MSC_VER)
	//GLEW������
	if (glewInit()) {
		glfwTerminate();
		return -1;
	}
#endif
	// �����ϊ��s���ݒ�
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, OGTK._window._widht, OGTK._window._height);
	glLoadIdentity();
	glOrtho(0.f, OGTK._window._widht, 0.f, OGTK._window._height, -1.f, 1.f);
	//glOrtho(0.f, OGTK._window._widht,OGTK._window._height, 0.f, 0.f, 1.f);
	// ����Ώۂ̍s������f�����O�r���[�s��ɐ؂�ւ��Ă���
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//�E�C���h�E�̍��W�̊����Ɋ�Â��ă|���S�����J�����O����
	glEnable(GL_CULL_FACE);
	//�[���̔�r���s���A�[�x�o�b�t�@���X�V����
	glEnable(GL_DEPTH_TEST);
	//�@���x�N�g���̐ݒ�A���K��
	glEnable(GL_NORMALIZE);
	//�w�icolor
	glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
	//����������
	Initialize();
	while (!glfwWindowShouldClose(OGTK._window.window)) {
		//�o�b�t�@���N���A���Ēl��ݒ肷��
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//�L���ɂȂ��Ă���ꍇ�A�v�Z���ꂽ�t���O�����g�J���[�l���J���[�o�b�t�@�̒l�ƃu�����h���܂��B
		glEnable(GL_BLEND);
		//�s�N�Z�����Z���w�肷��
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//�X�V����
		Update();
		TaskSystem();
		//�`�揈��
		TaskRender();
		//�w�肵���E�B���h�E�̃_�u���o�b�t�@���s��
		glfwSwapBuffers(OGTK._window.window);
		//�E�B���h�E�A�}�E�X�A�L�[�{�[�h�̓��͂̏�Ԃ��A�b�v�f�[�g����
		glfwPollEvents();
	}
	//���
	Finalize();
	//�E�B���h�E�̔j��
	glfwDestroyWindow(OGTK._window.window);
	//GLFW�̃��C�u�������I������
	glfwTerminate();
}