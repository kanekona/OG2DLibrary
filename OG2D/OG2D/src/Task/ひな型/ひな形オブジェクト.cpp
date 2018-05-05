#include "ひな形オブジェクト.h"
//別タスクや別オブジェクトを生成する場合ここにそのclassの書かれたhをインクルードする

bool 「生成するclass名」::Initialize()
{
	//-----------------------------
	//生成時に処理する初期化処理を記述
	//-----------------------------
	this->taskName = "";			//検索時に使うための名を登録する
	__super::Init(taskName);		//TaskObject内の処理を行う

	this->CreateObject(Cube, Vec2(100, 100), Vec2(128, 128), 0.0f);
	this->sampleImage.Create("Collision.png");

	return true;
}
void 「生成するclass名」::UpDate()
{
	//--------------------
	//更新時に行う処理を記述
	//--------------------
}

void 「生成するclass名」::Render2D()
{
	//--------------------
	//描画時に行う処理を記述
	//--------------------
	Box2D draw(this->position, this->Scale);
	draw.OffsetSize();
	this->sampleImage.Draw(draw, Box2D(0, 0, 128, 128));
}

bool 「生成するclass名」::Finalize()
{
	//-----------------------------------------
	//このオブジェクトが消滅するときに行う処理を記述
	//-----------------------------------------
	this->sampleImage.Finalize();
	//次のタスクを作るかかつアプリケーションが終了予定かどうか
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		//自分を消す場合はKillを使う
		this->Kill();
	}
	return true;
}

//----------------------------
//ここから下はclass名のみ変更する
//ほかは変更しないこと
//----------------------------
「生成するclass名」::「生成するclass名」()
{
	
}

「生成するclass名」::~「生成するclass名」()
{
	this->Finalize();
}

「生成するclass名」::SP 「生成するclass名」::Create(bool flag_)
{
	「生成するclass名」::SP to = 「生成するclass名」::SP(new 「生成するclass名」());
	if (to)
	{
		to->me = to;
		if (flag_)
		{
			OGge->SetTaskObject(to);
		}
		if (!to->Initialize())
		{
			to->Kill();
		}
		return to;
	}
	return nullptr;
}