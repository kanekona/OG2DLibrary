#pragma once
//�t�@�C�����͉��u��
//engine.cpp
//OGSystem_.hpp
#if !defined (_DEBUG)
// Degub�ł̂݃R���\�[����\������ݒ�
#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
#endif

// Windows:GLEW���X�^�e�B�b�N���C�u�����`���ŗ��p
#define GLEW_STATIC
// GLFW�̃w�b�_���ő��̃��C�u��������荞��	
#define GLFW_INCLUDE_GLEXT
#define GLFW_INCLUDE_GLU

#define GLM_SWIZZLE
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
//OpenCV
#pragma comment(lib, "opencv_core342.lib")
#pragma comment(lib, "opencv_videoio342.lib")
//LNK4098
#pragma comment(lib, "freetype.lib")

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

#define STR(var) #var

//GLM
//#include <glm/glm.hpp>

#include <Windows.h>

#if defined(_MSC_VER)
//EW���ɃC���N���[�h����K�v������B
#include <GL/glew.h>
#endif
//GLFW
#include <GLFW/glfw3.h>
//OpenAL
#include "al\al.h"
#include "al\alc.h"
//OpenCV
#include "opencv2\opencv.hpp"