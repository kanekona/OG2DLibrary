#pragma once
//______________________________//
//|�T���v���^�X�N               |//
//|�����F2018/03/20���q��       |//
//|____________________________|//
#include "Win\WinMain.h"
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
class ObjectSample :public Object{
public:
	//Object object;
	Texture sampleimg;
	std::string fileName = "Collision.png";
	bool hitcheck;
	void Initialize();
	void UpDate();
	void Render();
	void Finalize();
};
class ObjectSample2 :public Object {
public:
	//Object object;
	Texture sampleimg;
	std::string fileName = "Collision.png";
	bool hitcheck;
	void Initialize();
	void UpDate();
	void Render();
	void Finalize();
};
class Sample
{
public:
	void Initialize();
	TaskFlag UpDate();
	void Render2D();
	void Finalize();
	//��������//
	//�ǉ��ϐ�//
	//��������//
	ObjectSample objsmp;
	ObjectSample2 objsmp2;
};