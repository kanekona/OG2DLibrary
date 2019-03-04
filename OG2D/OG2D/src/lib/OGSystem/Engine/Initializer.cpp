#include "Initializer.h"
#include "Event\Event.h"
WindowParameter Initializer::ConfigWindow()
{
	return WindowParameter(Vec2Int(0, 30), Vec2Int(960, 540), "WindowName", false);
}
Scene* Initializer::SceneAdaptation()
{
	EventTask ev;
	ev.Load(Event::RESOURCE_LOAD, "./data/event/sampleLoad.og");
	return nullptr;
}