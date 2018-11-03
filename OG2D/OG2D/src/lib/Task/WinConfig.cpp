#include "WinConfig.h"
#include "OGSystem\Button\Button.h"
#include "Task\Scene\Title.h"
#include "Event\WindowEvent\WindowEvent.h"
ConfigTask::ConfigTask()
{
	this->Init("Config");
	auto button1 = Button::Create(Vec2(ge->window->GetSize().x / 4, ge->window->GetSize().y / 2), Vec2(ge->window->GetSize().x / 2, ge->window->GetSize().y), "Yes");
	button1->SetText("YES");
	ge->SetGameObject(button1);
	auto button2 = Button::Create(Vec2(ge->window->GetSize().x / 2 + ge->window->GetSize().x / 4, ge->window->GetSize().y / 2), Vec2(ge->window->GetSize().x / 2, ge->window->GetSize().y), "No");
	button2->SetText("NO");
	ge->SetGameObject(button2);
	this->nextWindowMode = false;
}
ConfigTask::~ConfigTask()
{
	if (this->GetNextTask() && !ge->GetDeleteEngine())
	{
		int x, y;
		std::ifstream ifs("./data/event/windowSize.og");
		WindowEvent(ifs, &x, &y);
		ge->WindowChenge(0, 30, x, y, "WindowName", this->nextWindowMode);
		ge->SetScene(Title::Create());
	}
}
void ConfigTask::Update()
{
	auto yesButton = ge->GetObject<Button>("Yes");
	if (yesButton->IsMouseHit() && ge->in->mouse->down(Mouse::LEFT))
	{
		this->Destroy(true);
	}
	auto noButton = ge->GetObject<Button>("No");
	if (noButton->IsMouseHit() && ge->in->mouse->down(Mouse::LEFT))
	{
		this->Destroy(false);
	}
}
void ConfigTask::Destroy(const bool flag)
{
	this->EnableGameObjectDestroy(true);
	this->Kill();
	this->nextWindowMode = flag;
}
ConfigTask* ConfigTask::Create()
{
	ConfigTask* to = new ConfigTask();
	return to;
}