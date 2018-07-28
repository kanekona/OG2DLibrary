#pragma once
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"

class TestObject : public GameObject
{
public:
	TestObject(bool = false);
	bool TestCheck();
	std::string taskName = "TestObject";
	virtual ~TestObject();
	static TestObject* Create(bool, bool = true);
	TestObject();
	bool Initialize();
	void UpDate() override;
	void Render2D() override;
	bool isMove;
	bool isHit;
};