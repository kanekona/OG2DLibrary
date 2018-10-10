#include "Title.h"
#include "Game.h"
#include "Map\Map.h"
Title::Title()
{
	ge->SetOtherScene(Map::Create());
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