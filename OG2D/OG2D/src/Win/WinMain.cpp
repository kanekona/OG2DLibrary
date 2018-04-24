//______________________________//
//|���C���V�X�e��               |//
//|�����F2018/03/20���q��       |//
//|�����F2018/03/23���q��       |//
//|____________________________|//
#define _USE_MATH_DEFINES
//�����_�덷�C��
#define _OX_EPSILON_ 0.0000001f
#include "OGSystem\OGTask.h"
//------------------
//class��`
//------------------
_OGTK OGTK;
//------------------
//�^�X�N�V�X�e��
//------------------
void TaskSystem()
{
	OGTK._myGameUpdate();
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
	if (gameEngine->in.key.down(In::ESCAPE) || gameEngine->GetEnd())
	{
		TaskFinalize();
		//�E�B���h�E�̔j��
		glfwDestroyWindow(gameEngine->window->window);
		return true;
	}
	return false;
}
//------------------
//���C��
//------------------
int main() {
	//FW�̏�����
	if (!glfwInit()) {
		return -1;
	}
	gameEngine = new EngineSystem();
	OGTK._myGameInitialize();
	gameEngine->Initialize();
	//�g�pOpenGL��Version�w��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//�g�p����E�B���h�E��ݒ肷��
	glfwMakeContextCurrent(gameEngine->window->window);
	//����(�_�u���o�b�t�@�̓���ւ��^�C�~���O�̎w��)
	glfwSwapInterval(1);
#if defined(_MSC_VER)
	//GLEW������
	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		return -1;
	}
#endif
	// �����ϊ��s���ݒ�
	glMatrixMode(GL_PROJECTION);
	//�`��͈͂̎w��
	glViewport(0, 0, gameEngine->window->_widht, gameEngine->window->_height);
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
	//�E�B���h�E�̐����ʒu�̎w��
	glfwSetWindowPos(gameEngine->window->window, 1920 - gameEngine->window->_widht, 50);
	//�E�B���h�E�����݂���ꍇ���[�v
	while (!glfwWindowShouldClose(gameEngine->window->window)) {
		//�G���W�����̍X�V����
		gameEngine->Update();
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
		glfwSwapBuffers(gameEngine->window->window);
		//�E�B���h�E�A�}�E�X�A�L�[�{�[�h�̓��͂̏�Ԃ��A�b�v�f�[�g����
		glfwPollEvents();
	}
	//���
	Finalize();
	//�Q�[���G���W���̓��e�����
	delete gameEngine;
	//GLFW�̃��C�u�������I������
	glfwTerminate();
}