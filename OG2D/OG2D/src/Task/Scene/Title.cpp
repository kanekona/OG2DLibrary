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
	//new‚ğ‚»‚Ì‚Ü‚Ü•Ô‚µ‚Ä‚¢‚é‚ªA‚±‚±‚Å‚È‚É‚©‘‚«‚½‚¢‚Æ‚«‚Ì‚½‚ß‚ÉŠÖ”‰»‚µ‚Ä‚¢‚é
	return new Title();
}
void Title::Update()
{

}