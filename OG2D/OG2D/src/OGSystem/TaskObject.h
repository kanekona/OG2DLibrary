#pragma once
#include "_OGsystem.h"
///KillCount 0 : 通常更新
///			 1~: 終了予定
///			 -1: 更新停止
/**
*TaskObject
*/
class TaskObject
{
private:
	//! 終了時に次のタスクを生成できるか
	bool NextTask;
	//! 削除するかどうかの判断用
	int KillCount;
	//! タスクに名をつける
	std::string taskName;
	//! 描画順番
	float order;
	//! 呼ばれる更新分岐
	bool isPause;
public:
	//! 子オブジェクトの情報
	std::vector<TaskObject*> Child;
	/**
	*@brief	:constructor
	*/
	TaskObject();
	/**
	*@brief	:destructor
	*/
	virtual ~TaskObject();
	/**
	*@brief	:初期化処理
	*@param	:string name タスク名
	*@return:bool 成功でtrue
	*/
	bool Init(const std::string& name);
	/**
	*@brief	:更新処理
	*/
	void T_UpDate();
	/**
	*@brief	:更新処理
	*/
	virtual void UpDate();
	/**
	*@brief	:描画処理
	*/
	virtual void Render2D();
	/**
	*@brief	:ポーズ処理
	*/
	virtual void PauseUpDate();
	/**
	*@brief	:削除命令
	*@param :bool flag 次タスクの生成を行うかの設定
	*/
	void Kill(const bool flag = true);
	/**
	*@brief	:削除状況を返す
	*@return:int 削除カウント
	*/
	int GetKillCount() const;
	/**
	*@brief	:次タスクの生成の許可を返す
	*@return:bool 生成許可
	*/
	bool GetNextTask() const;
	/**
	*@brief	:キルカウントをリセットする
	*/
	void ResetKillCount();
	/**
	*@brief	:描画順を指定する
	*@param	:float order 描画順
	*/
	void SetDrawOrder(const float order);
	/**
	*@brief	:描画順を返す
	*@return:描画順
	*/
	float GetDrawOrder() const;
	/**
	*@brief	:登録されているタスク名を返す
	*@return:string タスク名
	*/
	std::string GetTaskName() const;
	/**
	*@brief	:ポーズ中かを返す
	*@return:bool タスクの状態
	*/
	bool GetPause() const;
	/**
	*@brief	:ポーズ設定を行う
	*@param	:bool flag ポーズ設定
	*/
	void SetPause(const bool flag);
	/**
	*@brief	:停止処理を行う
	*@param	:bool flag 停止処理設定
	*/
	void Stop(const bool flag = true);
	/**
	*@brief	:停止処理設定を返す
	*@return:bool 停止設定
	*/
	bool GetIsStop() const;
private:
};