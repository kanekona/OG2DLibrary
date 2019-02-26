#pragma once
//ファイル名は仮置き
//engine.cpp
//OGSystem_.hpp
#if !defined (_DEBUG)
// Degub版のみコンソールを表示する設定
#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
#endif

// Windows:GLEWをスタティックライブラリ形式で利用
#define GLEW_STATIC
// GLFWのヘッダ内で他のライブラリを取り込む	
#define GLFW_INCLUDE_GLEXT
#define GLFW_INCLUDE_GLU

#define GLM_SWIZZLE
#define GLM_FORCE_SWIZZLE

//GLM警告
#pragma warning (disable : 4201)
//type_traits警告
#pragma warning (disable : 4239)
//xutility警告
#pragma warning (disable : 4244)
//stb_image警告
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
// Windows:外部ライブラリのリンク指定
#if defined (_DEBUG)
#pragma comment(lib, "glew32sd.lib")
#pragma comment(lib, "glfw3d.lib")
#else
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#endif
#endif

//数値演算定数
#define _USE_MATH_DEFINES
//小数点誤差修正
#define _OX_EPSILON_ 0.0000001f

#define PI 3.1415926f

#define STR(var) #var

//GLM
//#include <glm/glm.hpp>

#include <Windows.h>

#if defined(_MSC_VER)
//EWを先にインクルードする必要がある。
#include <GL/glew.h>
#endif
//GLFW
#include <GLFW/glfw3.h>
//OpenAL
#include "al\al.h"
#include "al\alc.h"
//OpenCV
#include "opencv2\opencv.hpp"