#pragma once
//_____________________________
//|�V�X�e���N���X�P             
//|�����F2018/03/20       
//|____________________________

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

//GLinclude���O��windows��include������K�v������
#include <Windows.h>

// �������̗]�v�Ȍx����\�����Ȃ��悤�ɂ���
//#pragma warning (disable:4244)
//#pragma warning (disable:4522)
//#pragma warning (disable:4800)
//#pragma warning (disable:4996)

#pragma comment(lib, "OPENGL32.lib")
#pragma comment(lib, "GLU32.lib")
#pragma comment(lib, "Win64/OpenAL32.lib")
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
#include <utility>

#include "OGlib.h"

#define PI 3.1415926f
typedef unsigned char u_char;
typedef unsigned int u_int;
typedef unsigned long u_long;

namespace OG {
	//�֗��@�\�֐��␔�w�v�Z
	void MulitMatrixf(GLfloat*, GLfloat*, GLfloat*);
	void Normalize(GLfloat*);
	void _Rotate(const float _angle, Vec2*);
	void LineHitDraw(Vec2*);
	void LineHitDraw(Vec2*,const Color&);
	void LineHitDraw(Box2D*);
}