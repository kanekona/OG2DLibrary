#pragma once
#include "OG\_OGsystem.h"

/**
*@brief	シェーダーの生成と使用を行うclass
*/
class Shader
{
	//! 生成したShaderのID
	GLuint id;
	/**
	*@brief	Shaderのコンパイル
	*@param[in] GLuint type CompileShaderType
	*@param[in] const string& text ShaderSource
	*@return GLuint
	*/
	GLuint Compile(GLuint type, const std::string &text);
	/**
	*@brief	Shaderの準備
	*@param[in] const GLuint program ShaderID
	*@param[in] const string& v_source vertexShaderSource
	*@param[in] const string& f_source fragmentShaderSource
	*/
	void Setup(const GLuint program,
		const std::string &v_source, const std::string &f_source);
public:
	/**
	*@brief	Shader読み込み
	*@param[in] const string& file シェーダーファイル名
	*@return GLuint ShaderID
	*/
	GLuint Read(const std::string &file);
	/**
	*@brief	シェーダー内アトリビュート変数の識別子を取得
	*@param[in]	const string& name 指定変数名
	*@return GLint 識別子ID
	*/
	GLint Attrib(const std::string &name);
	/**
	*@brief	シェーダー内ユニフォーム変数の識別子を取得
	*@param[in]	const string& name 指定変数名
	*@return GLint 識別子ID
	*/
	GLint Uniform(const std::string &name);
	/**
	*@brief	シェーダープログラムの使用開始
	*/
	void Use();
	/**
	*@brief	ShaderIDを取得する
	*@return GLuint ShaderID
	*/
	GLuint GetID() const;
};