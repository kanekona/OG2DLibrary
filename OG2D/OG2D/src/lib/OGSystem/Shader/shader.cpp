#include "shader.h"

//namespace Shader
//{
//	GLuint compile(GLuint type, const std::string &text) {
//		//shaderの生成
//		GLuint shader = glCreateShader(type);
//
//		const char* text_ptr = text.c_str();
//		//char**が必要
//		//オブジェクトへシェーダーを渡す
//		glShaderSource(shader, 1, &text_ptr, 0);
//		//コンパイル
//		glCompileShader(shader);
//#ifdef _DEBUG
//		//コンパイルエラーチェック
//		GLint compiled;
//		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
//		if (compiled == GL_FALSE) {
//			GLint length;
//			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
//			//エラー内容を出力
//			std::string log(length + 1, ' ');
//			glGetShaderInfoLog(shader, length, &length, &log[0]);
//			std::cout << "Compaile Error:" << log << std::endl;
//
//			return GL_FALSE;
//		}
//#endif // _DEBUG
//		return shader;
//	}
//
//	void setup(const GLuint program, const std::string &v_source, const std::string &f_source) {
//		//シェーダーのコンパイル
//		GLint status;
//		GLuint vertex_shader = compile(GL_VERTEX_SHADER, v_source);
//		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &status);
//		if (status != GL_TRUE) {
//			std::cout << "VertexShader Compile is Failed " << std::endl;
//			system("pause");
//
//			return;
//		}
//
//		GLuint fragment_shader = compile(GL_FRAGMENT_SHADER, f_source);
//		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &status);
//		if (status != GL_TRUE) {
//			std::cout << "FragmentShader Compile is Failed " << std::endl;
//			system("pause");
//
//			return;
//		}
//
//		//オブジェクトにシェーダーオブジェクトをアタッチする
//		glAttachShader(program, vertex_shader);
//		glAttachShader(program, fragment_shader);
//		//シェーダーのリンク
//		glLinkProgram(program);
//
//#ifdef _DEBUG
//		//リンクエラーチェック
//		//GLint status;
//		glGetProgramiv(program, GL_LINK_STATUS, &status);
//		if (status == GL_FALSE) {
//			GLint length;
//			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
//
//			//エラー出力
//			std::string log(length + 1, ' ');
//			glGetProgramInfoLog(program, length, &length, &log[0]);
//			std::cout << "Link Error:" << log << std::endl;
//		}
//#endif // _DEBUG
//		//リンクしたら元データを解放する
//		if (vertex_shader) {
//			//シェーダーから切り離す
//			glDetachShader(program, vertex_shader);
//			//シェーダーの破棄
//			glDeleteShader(vertex_shader);
//		}
//		if (fragment_shader) {
//			//シェーダーから切り離す
//			glDetachShader(program, fragment_shader);
//			//シェーダーの破棄
//			glDeleteShader(fragment_shader);
//		}
//	}
//	//読み込み
//	GLuint read(const std::string &file) {
//		//vertexshaderの読み込み(.vsh)
//		std::string vsh_path = "./data/shader/" + file + ".vsh";
//		std::ifstream vsh_fs(vsh_path);
//		//読み込みエラー
//		if (!vsh_fs) {
//			return (GLuint)-1;
//		}
//		//テキストデータをstring型に変換
//		std::string v_source((std::istreambuf_iterator<char>(vsh_fs)), std::istreambuf_iterator<char>());
//
//		//fragmentshaderの読み込み(.fsh)
//		std::string fsh_path = "./data/shader/" + file + ".fsh";
//		std::ifstream fsh_fs(fsh_path);
//		//読み込みエラー
//		if (!fsh_fs) {
//			return (GLuint)-1;
//		}
//		//テキストデータをstring型に変換
//		std::string f_source((std::istreambuf_iterator<char>(fsh_fs)), std::istreambuf_iterator<char>());
//
//		//プログラム識別子を生成
//		GLuint program = glCreateProgram();
//
//		//vertexとfragmentのシェーダーの生成
//		setup(program, v_source, f_source);
//
//		return program;
//	}
//
//	GLint attrib(const GLuint program, const std::string &name) {
//		return glGetAttribLocation(program, name.c_str());
//	}
//	//シェーダー内ユニフォーム変数の識別子を取得
//	GLint uniform(const GLuint program, const std::string &name) {
//		return glGetUniformLocation(program, name.data());
//	}
//	//シェーダープログラムの使用開始
//	void use(const GLuint program) {
//		glUseProgram(program);
//	}
//	void SetViewPort(float cl, float cr, float cb, float ct, float cn, float cf)
//	{
//		/*viewMatrix[0] = 2.f / (cr - cl);
//		viewMatrix[1] = 0.f;
//		viewMatrix[2] = 0.f;
//		viewMatrix[3] = (cr + cl) / (cr - cl) * -1;
//		viewMatrix[4] = 0.f;
//		viewMatrix[5] = 2.f / (ct - cb);
//		viewMatrix[6] = 0.f;
//		viewMatrix[7] = (ct + cb) / (ct - cb) * -1;
//		viewMatrix[8] = 0.f;
//		viewMatrix[9] = 0.f;
//		viewMatrix[10] = 2.f / (cf - cn);
//		viewMatrix[11] = (cf + cn) / (cf - cn) * -1;
//		viewMatrix[12] = 0.f;
//		viewMatrix[13] = 0.f;
//		viewMatrix[14] = 0.f;
//		viewMatrix[15] = 1.0f;*/
//	}
//	void SetProjection(float cl, float cr, float cb, float ct, float cn, float cf)
//	{
//		//projectionMatrix[0] = 0.f;
//	}
//}

GLuint Shader::Compile(GLuint type, const std::string &text)
{
	//shaderの生成
	GLuint shader = glCreateShader(type);

	const char* text_ptr = text.c_str();
	//char**が必要
	//オブジェクトへシェーダーを渡す
	glShaderSource(shader, 1, &text_ptr, 0);
	//コンパイル
	glCompileShader(shader);
#ifdef _DEBUG
	//コンパイルエラーチェック
	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE) {
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		//エラー内容を出力
		std::string log(length + 1, ' ');
		glGetShaderInfoLog(shader, length, &length, &log[0]);
		std::cout << "Compaile Error:" << log << std::endl;

		return GL_FALSE;
	}
#endif // _DEBUG
	return shader;
}
void Shader::Setup(const GLuint program, const std::string &v_source, const std::string &f_source) {
	//シェーダーのコンパイル
	GLint status;
	GLuint vertex_shader = Compile(GL_VERTEX_SHADER, v_source);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		std::cout << "VertexShader Compile is Failed " << std::endl;
		system("pause");

		return;
	}

	GLuint fragment_shader = Compile(GL_FRAGMENT_SHADER, f_source);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		std::cout << "FragmentShader Compile is Failed " << std::endl;
		system("pause");

		return;
	}

	//オブジェクトにシェーダーオブジェクトをアタッチする
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	//シェーダーのリンク
	glLinkProgram(program);

#ifdef _DEBUG
	//リンクエラーチェック
	//GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		GLint length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

		//エラー出力
		std::string log(length + 1, ' ');
		glGetProgramInfoLog(program, length, &length, &log[0]);
		std::cout << "Link Error:" << log << std::endl;
	}
#endif // _DEBUG
	//リンクしたら元データを解放する
	if (vertex_shader) {
		//シェーダーから切り離す
		glDetachShader(program, vertex_shader);
		//シェーダーの破棄
		glDeleteShader(vertex_shader);
	}
	if (fragment_shader) {
		//シェーダーから切り離す
		glDetachShader(program, fragment_shader);
		//シェーダーの破棄
		glDeleteShader(fragment_shader);
	}
}
	//読み込み
GLuint Shader::Read(const std::string &file) {
	//vertexshaderの読み込み(.vsh)
	std::string vsh_path = "./data/shader/" + file + ".vsh";
	std::ifstream vsh_fs(vsh_path);
	//読み込みエラー
	if (!vsh_fs) {
		return (GLuint)-1;
	}
	//テキストデータをstring型に変換
	std::string v_source((std::istreambuf_iterator<char>(vsh_fs)), std::istreambuf_iterator<char>());

	//fragmentshaderの読み込み(.fsh)
	std::string fsh_path = "./data/shader/" + file + ".fsh";
	std::ifstream fsh_fs(fsh_path);
	//読み込みエラー
	if (!fsh_fs) {
		return (GLuint)-1;
	}
	//テキストデータをstring型に変換
	std::string f_source((std::
		istreambuf_iterator<char>(fsh_fs)), std::istreambuf_iterator<char>());

	//プログラム識別子を生成
	GLuint program = glCreateProgram();
	//vertexとfragmentのシェーダーの生成
	Setup(program, v_source, f_source);
	this->id = program;
	return program;
}
GLint Shader::Attrib(const std::string &name) {
	return glGetAttribLocation(this->id, name.c_str());
}
//シェーダー内ユニフォーム変数の識別子を取得
GLint Shader::Uniform(const std::string &name) {
	return glGetUniformLocation(this->id, name.data());
}
//シェーダープログラムの使用開始
void Shader::Use() {
	glUseProgram(this->id);
}
GLuint Shader::GetID() const
{
	return this->id;
}