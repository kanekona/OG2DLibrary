#include "Title.h"
#include "Game.h"
#include "Map\Map.h"
#include "Back\Back.h"
#include "Object\TestObject.h"
#include "Event\Event.h"
#include "SetUp.h"

/**
*@ voiceroid音声と表情を一致させる方法について
音声ファイルは一言ずつになっているため、
音声ファイルの再生時間/発言文字数で１文字あたりの再生時間を導き、そのたびに表情を変化させる。
、や空白などは閉じるに戻し、伸ばす系の言葉は変化させない

台詞で口を選び表情は別変数で持つ必要がある
そのため、立ち絵製作者で分ける必要がある。
class分けはしたくないのでどうにかしたい。(てか必要ないはず）
ある程度決まった形にしてしまえば楽ではあるが、配布ファイルを変更しなければならないのはちょっとめんどい
表情１つに１ファイルでその中身を読み込めばいけるがフォルダ分けがめんどくさそう
*/

Title::Title()
{
	//ge->SetGameObject(new Back("back"));
	ge->SetGameObject(new TestObject("kiri"));
	//movieImage.Load("./data/image/kiritan/TestMovie.mp4");
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
	//newをそのまま返しているが、ここでなにか書きたいときのために関数化している
	return new Title();
}
void Title::Update()
{
	//movieImage.Draw(Box2D(ge->camera->GetPos(),ge->camera->GetSize()));
}