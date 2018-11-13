#pragma once
#include "Collision\Collision.h"
/**
*namespace	OG
*@brief	GameObjectに関するデータ
*/
namespace OG
{
	/**
	*enum class Mode
	*@brief	状態の設定
	*/
	enum class Mode
	{
		//! 通常処理
		NORMAL,
		//! ポーズ用処理
		PAUSE,
		//! 更新停止
		STOP,
		//! 描画更新共に停止
		ALLSTOP,
		//! 削除
		KILL,
	};
}
/**
*@brief	描画オブジェクト関連class
*
*まだ制作中
*
*/
class RenderObject : private NonCopyable
{
	//! 描画順
	/*?unsigned intのバイト数必要かどうか疑問ではある*/
	unsigned int order;
	// Mode
	OG::Mode mode;
public:
	/**
	*@brief	描画処理
	*/
	virtual void Render2D();
	/**
	*@brief	描画順指定
	*高い方が前に描画される
	*@param[in] unsigned int order 描画順値
	*/
	void SetDrawOrder(const unsigned int order);
	/**
	*@brief	描画順を取得
	*@return unsigned int 描画順
	*/
	unsigned int GetDrawOrder() const;
	/**
	*@brief	現状の状態を返す
	*@return Mode 状態
	*/
	OG::Mode GetMode() const;
	/**
	*@brief	モード確認
	*@parma[in]	Mode mode 比較対象
	*@return bool 比較対象と同じならtrue
	*/
	bool ModeCheck(const OG::Mode& mode) const;
};