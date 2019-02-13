#include "Title.h"
#include "Game.h"
#include "Map\Map.h"
#include "Back\Back.h"
#include "Object\TestObject.h"
#include "Event\Event.h"
#include "SetUp.h"
Title::Title()
{
	//ge->SetGameObject(new Back("back"));
	//ge->SetGameObject(new TestObject("kiri"));
	movieImage.Load("./data/image/kiritan/TestMovie.mp4");
	//EventTask ev;
	//ev.Load(Event::RESOURCE_LOAD, "./data/event/kiritanFile.og");
	//LOADFILE lf;
}
Title::~Title()
{
	if (this->GetNextTask() && !ge->GetDeleteEngine())
	{
		ge->SetScene(Game::Create());
	}
}
Title* Title::Create()
{
	//new�����̂܂ܕԂ��Ă��邪�A�����łȂɂ����������Ƃ��̂��߂Ɋ֐������Ă���
	return new Title();
}
void Title::Update()
{
	movieImage.Draw(Box2D(ge->camera->GetPos(),ge->camera->GetSize()));
}