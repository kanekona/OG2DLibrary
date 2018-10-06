#include "WinConfig.h"
#include "OGSystem\Button\Button.h"
#include "Task_Sample.h"
ConfigTask::ConfigTask()
{
	this->Init("Config");
	auto button1 = Button::Create(Vec2(ge->window->GetSize().x / 4, ge->window->GetSize().y / 2), Vec2(ge->window->GetSize().x / 2, ge->window->GetSize().y), "Yes");
	button1->SetText("‚Í‚¢");
	ge->SetGameObject(button1);
	auto button2 = Button::Create(Vec2(ge->window->GetSize().x / 2 + ge->window->GetSize().x / 4, ge->window->GetSize().y / 2), Vec2(ge->window->GetSize().x / 2, ge->window->GetSize().y), "No");
	button2->SetText("‚¢‚¢‚¦");
	ge->SetGameObject(button2);
	this->nextWindowMode = false;
}
ConfigTask::~ConfigTask()
{
	if (this->GetNextTask() && !ge->GetDeleteEngine())
	{
		ge->WindowChenge(0, 30, 1920, 1080, "WindowName", this->nextWindowMode);
		ge->SetTask(Sample::Create());
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