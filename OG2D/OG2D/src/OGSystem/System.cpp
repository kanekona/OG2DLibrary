#include "System.h"
OGSystem::OGSystem()
{
	OGge = new EngineSystem();
	rm = new ResourceManager();
}

OGSystem::~OGSystem()
{
	//�Q�[���G���W���̓��e�����
	delete OGge;
	delete rm;
	//GLFW�̃��C�u�������I������
	glfwTerminate();
}

bool OGSystem::Create()
{
	//FW�̏�����
	if (!glfwInit()) {
		return false;
	}
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
		return false;
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
	random::Init();
	return true;
}

bool OGSystem::LibConfirmation()
{
	//�_�u���o�b�t�@
	glfwSwapBuffers(OGge->window->GetWindow());
	//�E�B���h�E�A�}�E�X�A�L�[�{�[�h�̓��͂̏�Ԃ��A�b�v�f�[�g����
	glfwPollEvents();
	//GameEngine�̍X�V����
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
	if (OGge->in->key.down(In::ESCAPE) || OGge->GetEnd())
	{
		OGge->SetDeleteEngine(true);
		//�E�B���h�E�̔j��
		glfwDestroyWindow(OGge->window->GetWindow());
		return false;
	}
	//�e�^�X�N�̍X�V����
	OGge->TaskGameUpDate();
	return !glfwWindowShouldClose(OGge->window->GetWindow());
}