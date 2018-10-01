#pragma once
#include "_OGsystem.h"
///KillCount 0 : 通常更新
///			 1~: 終了予定
///			 -1: 更新停止
/**
*enum Mode
*状態の設定
*/
namespace Scene
{
	enum Mode
	{
		//! 通常処理
		NORMAL,
		//! ポーズ用処理
		PAUSE,
		//! 更新停止
		STOP,
		//! 削除
		KILL,
	};
}
/**
*TaskObject
*/
class SceneTask : private NonCopyable
{
private:
	//! 終了時に次のタスクを生成できるか
	bool NextTask;
	//! タスクに名をつける
	std::string taskName;
	//! 状態管理
	Scene::Mode _mode;
	//! 終了時にGameObjectを破棄するか
	bool enableDestroyGameObjectWhenExitng;
public:
	/**
	*@brief	:constructor
	*/
	explicit SceneTask();
	/**
	*@brief	:destructor
	*/
	virtual ~SceneTask();
	/**
	*@brief	:初期化処理
	*@param	:string name タスク名
	*@return:bool 成功でtrue
	*/
	bool Init(const std::string& name);
	/**
	*@brief	:更新処理
	*/
	void UpdateManager();
	/**
	*@brief	:更新処理
	*/
	virtual void Update();
	/**
	*@brief	:ポーズ処理
	*/
	virtual void Pause();
	/**
	*@brief	:削除命令
	*@param :bool flag 次タスクの生成を行うかの設定
	*/
	void Kill(const bool flag = true);
	/**
	*@brief	:次タスクの生成の許可を返す
	*@return:bool 生成許可
	*/
	bool GetNextTask() const;
	/**
	*@brief	:登録されているタスク名を返す
	*@return:string タスク名
	*/
	std::string GetTaskName() const;
	/**
	*@brief	:ポーズ設定を行う
	*@param	:bool flag ポーズ設定
	*/
	void SetPause(const bool flag = true);
	/**
	*@brief	:停止処理を行う
	*@param	:bool flag 停止処理設定
	*/
	void SetStop(const bool flag = true);
	/**
	*@brief	:現状の状態を返す
	*@return:Mode 状態
	*/
	Scene::Mode GetMode() const;
	/**
	*@brief	:モード確認
	*@parma	:Mode mode 比較対象
	*@return:bool 比較対象と同じならtrue
	*/
	bool ModeCheck(const Scene::Mode& mode) const;
	/**
	*@brief	:終了時にGameObjectを削除させる設定
	*@param	:bool flag trueなら削除させる
	*/
	void EnableGameObjectDestroy(const bool flag);
	/**
	*@brief	:終了時にGameObjectを削除させる設定を取得
	*@return:bool trueなら削除させる
	*/
	bool GetGameObjectDestroy() const;
};