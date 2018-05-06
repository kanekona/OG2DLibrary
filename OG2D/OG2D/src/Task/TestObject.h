#pragma once
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"

class TestObject : public GameObject , public TaskObject
{
public:
	bool TestCheck();
	std::string taskName = "TestObject";
	virtual ~TestObject();
	typedef std::shared_ptr<TestObject> SP;
	static TestObject::SP Create(bool);
	TestObject();
	bool Initialize();
	void UpDate();
	void Render2D();
	bool Finalize();
	Texture sampleImage;
};