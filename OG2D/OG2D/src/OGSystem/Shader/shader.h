#pragma once
//�K�v�t�@�C���̃C���N���[�h
#include "OGSystem\_OGsystem.h"

//�V�F�[�_�[�̃Z�b�g�A�b�v

namespace Shader {
	static GLuint programID;
	static GLfloat promaterix[16];
	//�R���p�C��
	GLuint compile(GLuint type, const std::string &text);
	//����
	void setup(const GLuint program, const std::string &v_source, const std::string &f_source);
	//�ǂݍ���
	GLuint read(const std::string &file);
	//�V�F�[�_�[���A�g���r���[�g�ϐ��̎��ʎq���擾
	GLint attrib(const GLint program, const std::string &name);
	//�V�F�[�_�[�����j�t�H�[���ϐ��̎��ʎq���擾
	GLint uniform(const GLuint program, const std::string &name);
	//�V�F�[�_�[�v���O�����̎g�p�J�n
	void use(const GLuint program);
	//�r���[�s���o�^����
	void SetViewPort(float, float, float, float, float, float);
}