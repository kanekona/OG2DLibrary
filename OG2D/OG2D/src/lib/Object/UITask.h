#pragma once
#include "OG\_OGsystem.h"
/**
*namespace UO
*@brief	UIObjectに関するデータ
*/
namespace UO
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
*@brief	UI表示のためのオブジェクト
*
*更新と描画のみを行える
*/
class UIObject
{
	//! Position
	Vec2 _position;
	//! Scale
	Vec2 _scale;
	//! Angle
	float _angle;
	//! TaskTag
	std::string _tag;
	//! Mode
	UO::Mode _mode;
	//! 描画順
	unsigned int _order;
	/**
	*@brief	値のリセット
	*/
	void ResetData();
public:
	/**
	*@brief	constructor
	*/
	explicit UIObject();
	/**
	*@brief	constructor
	*@param[in]	string& tag TaskName
	*@param[in]	const Vec2& pos Position
	*@param[in]	const Vec2& scale Scale
	*@param[in]	float angle Angle
	*/
	explicit UIObject(
		const std::string& tag, 
		const Vec2& pos,
		const Vec2& scale, 
		const float angle = 0.f);
	/**
	*@brief[in]	destructor
	*/
	virtual ~UIObject();
	/**
	*@brief	Initialize
	*@param[in]	string& tag TaskName
	*@param[in]	const Vec2& pos Position
	*@param[in]	const Vec2& scale Scale
	*@param[in]	float angle Angle
	*/
	void Init(
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.f);
	/**
	*@brief	更新処理
	*/
	virtual void Update();
	/**
	*@brief	停止処理
	*/
	virtual void Pause();
	/**
	*@brief	描画処理
	*/
	virtual void Render2D();
	/**
	*@brief	更新管理
	*/
	void UpdateManager();
	/**
	*@brief	描画管理
	*/
	void RenderManager();
	/**
	*@brief	位置設定
	*@param[in]	Vec2 pos 位置
	*/
	void SetPosition(const Vec2& pos);
	/**
	*@brief	位置設定
	*@param[in]	float x 位置X座標
	*@param[in]	float y 位置Y座標
	*/
	void SetPosition(const float x, const float y);
	/**
	*@brief	位置情報取得
	*@return Vec2 Position
	*/
	Vec2 GetPosition();
	/**
	*@brief	拡縮設定
	*@param[in]	Vec2 scale 拡縮
	*/
	void SetScale(const Vec2& scale);
	/**
	*@brief	拡縮設定
	*@param[in]	float x 拡縮X
	*@param[in]	float y 拡縮Y
	*/
	void SetScale(const float x, const float y);
	/**
	*@brief	拡縮情報取得
	*@return Vec2 Scale
	*/
	Vec2 GetScale() const;
	/**
	*@brief	回転設定
	*@param[in]	float angle 回転角度
	*/
	void SetRotate(const float angle);
	/**
	*@brief	回転情報取得
	*@return float angle
	*/
	float GetRotate() const;
	/**
	*@brief	タグ設定
	*@param[in]	string name tagname
	*/
	void SetTag(const std::string& name);
	/**
	*@brief	タグ情報取得
	*@return string objecttag
	*/
	std::string GetTag() const;
	/**
	*@brief	オブジェクトを削除する
	*/
	void Kill();
	/**
	*@brief	削除命令をキャンセルする
	*/
	void CancelKill();
	/**
	*@brief	Pause設定
	*@param[in]	bool flag trueでPause化
	*/
	void SetPause(const bool flag = true);
	/**
	*@brief	停止設定
	*@param[in]	bool flag trueで停止
	*/
	void SetStop(const bool flag = true);
	/**
	*@brief	全機能停止
	*@param[in]	bool flag trueで全停止
	*/
	void SetAllStop(const bool flag = true);
	/**
	*@brief	現状の状態を返す
	*@return Mode 状態
	*/
	UO::Mode GetMode() const;
	/**
	*@brief	モード確認
	*@parma[in]	Mode mode 比較対象
	*@return bool 比較対象と同じならtrue
	*/
	bool ModeCheck(const UO::Mode& mode) const;
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
};