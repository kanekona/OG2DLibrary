#include "System.h"
OGSystem::OGSystem()
{
	ge = new EngineSystem();
	rm = new ResourceManager();
	ogtk = new OGTK();
	ogtk->Init();
}

OGSystem::~OGSystem()
{
	//�Q�[���G���W���̓��e�����
	OG::Destroy<EngineSystem>(ge);
	OG::Destroy<ResourceManager>(rm);
	OG::Destroy<OGTK>(ogtk);
	//GLFW�̃��C�u�������I������
	glfwTerminate();
}

bool OGSystem::Create()
{
	//FW�̏�����
	if (!glfwInit()) {
		return false;
	}
	//WinConfig

	//�Q�[���G���W���̏�����
	ge->Initialize();
	//�g�pOpenGL��Version�w��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//�g�p����E�B���h�E��ݒ肷��
	glfwMakeContextCurrent(ge->window->GetWindow());
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
	glViewport(0, 0, (GLsizei)ge->window->GetSize().x, (GLsizei)ge->window->GetSize().y);
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
	//TaskCreate
	ogtk->StartTaskObject();
	return true;
}

bool OGSystem::LibConfirmation()
{
	if (ge->fps->FrameCheck())
	{
		//�_�u���o�b�t�@
		glfwSwapBuffers(ge->window->GetWindow());
		//�E�B���h�E�A�}�E�X�A�L�[�{�[�h�̓��͂̏�Ԃ��A�b�v�f�[�g����
		glfwPollEvents();
		//GameEngine�̍X�V����
		ge->Update();
		//�{���Ώۂ̍s������f���r���[�s��ɕύX
		glMatrixMode(GL_MODELVIEW);
		//�o�b�t�@���N���A���Ēl��ݒ肷��
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//�L���ɂȂ��Ă���ꍇ�A�v�Z���ꂽ�t���O�����g�J���[�l���J���[�o�b�t�@�̒l�ƃu�����h���܂��B
		glEnable(GL_BLEND);
		//�s�N�Z�����Z���w�肷��
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//�e�^�X�N�̍X�V����
		ge->TaskGameUpdate();
		//�X�V����
		if (ge->in->key->down(In::ESCAPE) || ge->GetEnd())
		{
			//�E�B���h�E�̔j��
			glfwDestroyWindow(ge->window->GetWindow());
			ge->SetDeleteEngine(true);
			return false;
		}
	}
	return !glfwWindowShouldClose(ge->window->GetWindow());
}