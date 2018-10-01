#include "OGSystem\OGsystem.h"
#include "Object\Object.h"

class TestObject : public GameObject
{
	TestObject();
	void Update() override;
	void Render2D() override;
	Box2D* draw;
	Box2D* src;
public:
	static TestObject* Create();
	~TestObject();
};