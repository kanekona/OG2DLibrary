#include "Title.h"
#include "Game.h"
#include "Map\Map.h"
#include "Back\Back.h"
#include "Object\TestObject.h"
Title::Title()
{
	ge->SetGameObject(new Back("back"));
	ge->SetGameObject(new TestObject("kiri"));
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
	//newをそのまま返しているが、ここでなにか書きたいときのために関数化している
	return new Title();
}
void Title::Update()
{

}