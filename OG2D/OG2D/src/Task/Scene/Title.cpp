#include "Title.h"
#include "Game.h"
#include "Map\Map.h"
#include "Back\Back.h"
#include "Object\TestObject.h"
#include "Event\Event.h"
#include "SetUp.h"

/**
*@ voiceroid�����ƕ\�����v��������@�ɂ���
�����t�@�C���͈ꌾ���ɂȂ��Ă��邽�߁A
�����t�@�C���̍Đ�����/�����������łP����������̍Đ����Ԃ𓱂��A���̂��тɕ\���ω�������B
�A��󔒂Ȃǂ͕���ɖ߂��A�L�΂��n�̌��t�͕ω������Ȃ�

�䎌�Ō���I�ѕ\��͕ʕϐ��Ŏ��K�v������
���̂��߁A�����G����҂ŕ�����K�v������B
class�����͂������Ȃ��̂łǂ��ɂ��������B(�Ă��K�v�Ȃ��͂��j
������x���܂����`�ɂ��Ă��܂��Ίy�ł͂��邪�A�z�z�t�@�C����ύX���Ȃ���΂Ȃ�Ȃ��̂͂�����Ƃ߂�ǂ�
�\��P�ɂP�t�@�C���ł��̒��g��ǂݍ��߂΂����邪�t�H���_�������߂�ǂ�������
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
	//new�����̂܂ܕԂ��Ă��邪�A�����łȂɂ����������Ƃ��̂��߂Ɋ֐������Ă���
	return new Title();
}
void Title::Update()
{
	//movieImage.Draw(Box2D(ge->camera->GetPos(),ge->camera->GetSize()));
}