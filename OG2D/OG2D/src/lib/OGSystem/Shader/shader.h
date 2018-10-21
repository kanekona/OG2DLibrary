#pragma once
#include "OG\_OGsystem.h"

/**
*@brief	�V�F�[�_�[�̐����Ǝg�p���s��class
*/
class Shader
{
public:
	//! ��������Shader��ID
	GLuint id;
	//! ���e�s���ۑ����Ă����z��
	GLfloat projectionMatrix[16];
	/**
	*@brief	Shader�̃R���p�C��
	*@param[in] GLuint type
	*@param[in] const string& text
	*@return GLuint
	*/
	GLuint compile(GLuint type, const std::string &text);
	/**
	*@brief	Shader�̏���
	*@param[in] const GLuint program
	*@param[in] const string& v_source
	*@param[in] const string& f_source
	*/
	void setup(const GLuint program,
		const std::string &v_source, const std::string &f_source);
	/**
	*@brief	Shader�ǂݍ���
	*@param[in] const string& file
	*@return GLuint ShaderID
	*/
	GLuint read(const std::string &file);
	//�V�F�[�_�[���A�g���r���[�g�ϐ��̎��ʎq���擾
	GLint attrib(const GLuint program, const std::string &name);
	//�V�F�[�_�[�����j�t�H�[���ϐ��̎��ʎq���擾
	GLint uniform(const GLuint program, const std::string &name);
	//�V�F�[�_�[�v���O�����̎g�p�J�n
	void use(const GLuint program);
	//���e�s���o�^����
	void SetProjectionMatrix(float left, float right, float buttom, float top, float nearVal, float farVal);
};