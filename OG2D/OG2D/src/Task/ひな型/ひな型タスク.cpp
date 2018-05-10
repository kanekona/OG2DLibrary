#include "ひな形タスク.h"
//別タスクや別オブジェクトを生成する場合ここにそのclassの書かれたhをインクルードする
#include "ひな形オブジェクト.h"

bool 「生成するclass名」::Initialize()
{
	//-----------------------------
	//生成時に処理する初期化処理を記述
	//-----------------------------
	this->taskName = "";			//検索時に使うための名を登録する
	__super::Init(taskName);		//TaskObject内の処理を行う
	//生成例
	auto ひな形 = 「ひな形オブジェクト」::Create(true);
	return true;
}

void 「生成するclass名」::UpDate()
{
	//--------------------
	//更新時に行う処理を記述
	//--------------------
	if(OGge->in->key.down(In::X))
	{
		//自分を消す場合はKillを使う
		this->Kill();
	}
}

void 「生成するclass名」::Render2D()
{
	//--------------------
	//描画時に行う処理を記述
	//--------------------
}
bool 「生成するclass名」::Finalize()
{
	//-----------------------------------------
	//このオブジェクトが消滅するときに行う処理を記述
	//-----------------------------------------
	//次のタスクを作るかかつアプリケーションが終了予定かどうか
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		
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