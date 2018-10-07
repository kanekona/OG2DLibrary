
#include "OG\OGsystem.h"

class Sample2 : public SceneTask
{
	Sample2();
	void Update() override;
public:
	~Sample2();
	static Sample2* Create();
};