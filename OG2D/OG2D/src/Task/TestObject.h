
#include "OG\OGsystem.h"
#include "Object\GameObject.h"

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