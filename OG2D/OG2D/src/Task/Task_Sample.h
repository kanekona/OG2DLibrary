
#include "OG\OGsystem.h"
class Sample : public SceneTask
{
	Sample();
	void Update() override;
public:
	~Sample();
	static Sample* Create();
};