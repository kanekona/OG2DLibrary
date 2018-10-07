#pragma once

#if !defined (_DEBUG)
// Degub�ł̂݃R���\�[����\������ݒ�
#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
#endif

// Windows:GLEW���X�^�e�B�b�N���C�u�����`���ŗ��p
#define GLEW_STATIC
// GLFW�̃w�b�_���ő��̃��C�u��������荞��	
#define GLFW_INCLUDE_GLEXT
#define GLFW_INCLUDE_GLU
#define GLM_FORCE_SWIZZLE

//GLM�x��
#pragma warning (disable : 4201)
//type_traits�x��
#pragma warning (disable : 4239)
//xutility�x��
#pragma warning (disable : 4244)
//stb_image�x��
#pragma warning (disable : 4100)

#pragma comment(lib, "OPENGL32.lib")
#pragma comment(lib, "GLU32.lib")
#pragma comment(lib, "Win64/OpenAL32.lib")
//LNK4098
//#pragma comment(lib, "freetype.lib")

#if defined(_MSC_VER)
// Windows:�O�����C�u�����̃����N�w��
#if defined (_DEBUG)
#pragma comment(lib, "glew32sd.lib")
#pragma comment(lib, "glfw3d.lib")
#else
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#endif
#endif

//���l���Z�萔
#define _USE_MATH_DEFINES
//�����_�덷�C��
#define _OX_EPSILON_ 0.0000001f

#define PI 3.1415926f

#if defined(_MSC_VER)
//EW���ɃC���N���[�h����K�v������B
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "al\al.h"
#include "al\alc.h"

#include <memory>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>


#include "OGlib.h"
#include "randmais.h"

typedef unsigned char u_char;
typedef unsigned int u_int;
typedef unsigned long u_long;
/**
*namespace OG
*@brief	�֗��@�\�֐��␔�w�v�Z
*/
namespace OG 
{
	void MulitMatrixf(GLfloat*, GLfloat*, GLfloat*);
	void Normalize(GLfloat*);
	void _Rotate(const float _angle, Vec2*);
	void LineBoxDraw(const Box2D* box, const Color& color = { 1,1,1,1 }, const float linewidth = 1.0f);
	void LineBoxDraw(const Box2D* box, const float linewidth, const Color& color = { 1,1,1,1 });
	void LineBoxDraw(const Vec2* vec, const Color& color = { 1,1,1,1 }, const float linewidth = 1.0f);
	void LineBoxDraw(const Vec2* vec, const float linewidth, const Color& color = { 1,1,1,1 });
	void LineDraw(const Vec2* vec, const Color& color = { 1,1,1,1 }, const float linewidth = 1.0f);
	void LineDraw(const Vec2* vec, const float linewidth, const Color& color = { 1,1,1,1 });
	void LineOvalDraw(const int x, const int y, const float ovalx, const float ovaly, const float linewidth = 1.0f, const Color& color = { 1,1,1,1 });
	void LineOvalDraw(const Vec2* pos, const Vec2* scale, const float linewidth = 1.0f, const Color& color = { 1,1,1,1 });
	void PointDraw(const Vec2* pos, const float linewidth, const Color& color = { 1,1,1,1 });
	void PointDraw(const Vec2* pos, const Color& color = { 1,1,1,1 }, const float linewidth = 1.0f);
	void BackColor(const Color& color);
	void BackColor(const float&red, const float&green, const float&blue, const float&alpha);
	int mbclen(const char* c);
	void cout(const Box2D&);
	void cout(const Vec2&);
	void cout(const Color&);
	bool Data_Cipher(const std::string& in_path, const std::string& out_path);
	std::string Data_Composite(std::ifstream& ifs);
	void OutDebugData(const std::string& out_path, const std::string& text);
	void DataClear(const std::string& path);
	template <class T> bool Destroy(T* t)
	{
		if (t)
		{
			delete t;
			t = nullptr;
			return true;
		}
		return false;
	}
	template <class T> bool Destroy(const T* t)
	{
		if (t)
		{
			delete t;
			t = nullptr;
			return true;
		}
		return false;
	}
}