#pragma once
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"

class TestObject : public GameObject , public TaskObject
{
public:
	TestObject(bool = false);
	bool TestCheck();
	std::string taskName = "TestObject";
	virtual ~TestObject();
	typedef std::shared_ptr<TestObject> SP;
	static TestObject::SP Create(bool, bool = true);
	TestObject();
	bool Initialize();
	void UpDate();
	void Render2D();
	bool Finalize();
	Texture sampleImage;
	bool isMove;
	bool isHit;
};