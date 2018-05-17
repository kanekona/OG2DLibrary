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
#include "OGSystem\Random\Random.h"
//#include "ft2build.h"
//#include FT_FREETYPE_H
//���������[�N���m
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

OGTK* ogtk;
//------------------
//�^�X�N�V�X�e��
//------------------
void TaskSystem()
{
	OGge->TaskGameUpDate();
}
void TaskRender()
{
	
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
	ogtk->StartTaskObject();
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
	if (OGge->in->key.down(In::ESCAPE) || OGge->GetEnd())
	{
		TaskFinalize();
		//�E�B���h�E�̔j��
		glfwDestroyWindow(OGge->window->GetWindow());
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
	ogtk = new OGTK();
	rm = new ResourceManager();
	//�^�X�N�̏���������
	ogtk->_myGameInitialize();
	//�Q�[���G���W���̏�����
	OGge->Initialize();
	//�g�pOpenGL��Version�w��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//�g�p����E�B���h�E��ݒ肷��
	glfwMakeContextCurrent(OGge->window->GetWindow());
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
	glViewport(0, 0, (GLsizei)OGge->window->GetSize().x, (GLsizei)OGge->window->GetSize().y);
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
	delete ogtk;
	//�E�B���h�E�����݂���ꍇ���[�v
	while (!glfwWindowShouldClose(OGge->window->GetWindow())) {
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
		glfwSwapBuffers(OGge->window->GetWindow());
		//�E�B���h�E�A�}�E�X�A�L�[�{�[�h�̓��͂̏�Ԃ��A�b�v�f�[�g����
		glfwPollEvents();
	}
	//���
	Finalize();
	//�Q�[���G���W���̓��e�����
	delete OGge;
	delete rm;
	//GLFW�̃��C�u�������I������
	glfwTerminate();
}