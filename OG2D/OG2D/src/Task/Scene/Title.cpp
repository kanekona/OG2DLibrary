#include "Title.h"
#include "Game.h"
#include "Map\Map.h"
#include "Back\Back.h"
Title::Title()
{
	ge->SetGameObject(new Back("back"));
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

}