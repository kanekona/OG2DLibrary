#pragma once
#include "OG\_OGsystem.h"

/**
*@brief	�V�F�[�_�[�̐����Ǝg�p���s��class
*/
class Shader
{
	//! ��������Shader��ID
	GLuint id;
	/**
	*@brief	Shader�̃R���p�C��
	*@param[in] GLuint type CompileShaderType
	*@param[in] const string& text ShaderSource
	*@return GLuint
	*/
	GLuint Compile(GLuint type, const std::string &text);
	/**
	*@brief	Shader�̏���
	*@param[in] const GLuint program ShaderID
	*@param[in] const string& v_source vertexShaderSource
	*@param[in] const string& f_source fragmentShaderSource
	*/
	void Setup(const GLuint program,
		const std::string &v_source, const std::string &f_source);
public:
	/**
	*@brief	Shader�ǂݍ���
	*@param[in] const string& file �V�F�[�_�[�t�@�C����
	*@return GLuint ShaderID
	*/
	GLuint Read(const std::string &file);
	/**
	*@brief	�V�F�[�_�[���A�g���r���[�g�ϐ��̎��ʎq���擾
	*@param[in]	const string& name �w��ϐ���
	*@return GLint ���ʎqID
	*/
	GLint Attrib(const std::string &name);
	/**
	*@brief	�V�F�[�_�[�����j�t�H�[���ϐ��̎��ʎq���擾
	*@param[in]	const string& name �w��ϐ���
	*@return GLint ���ʎqID
	*/
	GLint Uniform(const std::string &name);
	/**
	*@brief	�V�F�[�_�[�v���O�����̎g�p�J�n
	*/
	void Use();
	/**
	*@brief	ShaderID���擾����
	*@return GLuint ShaderID
	*/
	GLuint GetID() const;
};