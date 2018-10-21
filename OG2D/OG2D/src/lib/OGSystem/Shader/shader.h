#pragma once
#include "OG\_OGsystem.h"

/**
*@brief	シェーダーの生成と使用を行うclass
*/
class Shader
{
public:
	//! 生成したShaderのID
	GLuint id;
	//! 投影行列を保存しておく配列
	GLfloat projectionMatrix[16];
	/**
	*@brief	Shaderのコンパイル
	*@param[in] GLuint type
	*@param[in] const string& text
	*@return GLuint
	*/
	GLuint compile(GLuint type, const std::string &text);
	/**
	*@brief	Shaderの準備
	*@param[in] const GLuint program
	*@param[in] const string& v_source
	*@param[in] const string& f_source
	*/
	void setup(const GLuint program,
		const std::string &v_source, const std::string &f_source);
	/**
	*@brief	Shader読み込み
	*@param[in] const string& file
	*@return GLuint ShaderID
	*/
	GLuint read(const std::string &file);
	//シェーダー内アトリビュート変数の識別子を取得
	GLint attrib(const GLuint program, const std::string &name);
	//シェーダー内ユニフォーム変数の識別子を取得
	GLint uniform(const GLuint program, const std::string &name);
	//シェーダープログラムの使用開始
	void use(const GLuint program);
	//投影行列を登録する
	void SetProjectionMatrix(float left, float right, float buttom, float top, float nearVal, float farVal);
};