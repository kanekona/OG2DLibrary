#pragma once
#include "_OGsystem.h"

class TaskObject
{
public:
	typedef std::shared_ptr<TaskObject> SP;	//スマートポインタ
	typedef std::weak_ptr<TaskObject> WP;	//サブオーバー
	WP me;									//自分の情報
	std::string taskName;					//タスクに名をつける
private:
	bool NextTask;							//終了時に次のタスクを生成できるか
	int KillCount;							//削除するかどうかの判断用
public:
	bool Init(std::string&);				//初期化処理
	void T_UpDate();						//更新処理
	void Draw2D();							//描画処理
	void Delete();							//削除処理
	virtual void UpDate() = 0;				//子達の更新処理
	virtual void Render2D() = 0;			//子達の描画処理
	virtual bool Finalize() = 0;			//子達の解放処理
	void Kill(bool = true);					//削除処理
	int GetKillCount();						//削除状況を返す
	bool GetNextTask();						//次のタスクが作れるかどうかを返す
	void ResetKillCount();					//削除状況をリセットする
private:
};