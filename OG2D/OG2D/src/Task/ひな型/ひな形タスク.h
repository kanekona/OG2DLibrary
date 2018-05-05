#pragma once
//必要読み込みファイル
#include "OGSystem\OGsystem.h"

class 「生成するclass名」 : public TaskObject
{
	//-------------------------------------------
	//各自で制作するときに使用するものはここに記述する
	//-------------------------------------------
public:
private:

	//------------------
	//固定化されている処理
	//------------------
public:
	std::string taskName;
	virtual ~「生成するclass名」();
	typedef std::shared_ptr<「生成するclass名」> SP;
	static 「生成するclass名」::SP Create(bool);
	「生成するclass名」();
	//-------------
	//変更しないこと
	//-------------
	bool Initialize();		//初期化処理
	void UpDate();			//更新処理
	void Render2D();		//描画処理
	bool Finalize();		//解放処理
};