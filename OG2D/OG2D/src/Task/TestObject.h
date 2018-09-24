#include "OGSystem\OGsystem.h"
#include "Object\Object.h"

class TestObject : public GameObject
{
	TestObject();
	void Update() override;
	void Render2D() override;
public:
	bool isInput;
	bool isHit;
	static TestObject* Create();
	~TestObject();
};