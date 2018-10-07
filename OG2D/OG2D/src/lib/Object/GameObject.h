#pragma once
#include "OGSystem\Collision\Collision.h"
/**
*enum Objform
*@brief	オブジェクトの形の設定
*/
enum Objform
{
	//! 無
	Non,
	//!	円
	Circle,
	//! 矩形
	Box,
	//! 点
	Pointer,
	//! 線
	Line,
};
/**
*namespace	GO
*@brief	GameObjectに関するデータ
*/
namespace GO
{
	/**
	*enum Mode
	*@brief	状態の設定
	*/
	enum Mode
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
*@brief	GameObject
*当たり判定や更新、描画処理を行うことが出来る
*/
class GameObject :private NonCopyable
{
	//! Position
	Vec2 _position;
	//! Scale
	Vec2 _scale;
	//! DistanceScale
	Vec2 _distanceScale;
	//! Radius
	Vec2 _radius;
	//! Angle
	float _angle;
	//! CollisionData
	CollisionBase* _collision;
	//! ObjectTag
	std::string _tag;
	//! Mass
	float _mass;
	//! DistanceCollision
	CollisionCircle* _distanceCollision;
	//! isCollisionCheck
	bool enableCollision;
	//! Mode
	GO::Mode _mode;
	//! ObjectForm
	Objform _form;
	//! 描画順
	/*?unsigned intのバイト数必要かどうか疑問ではある*/
	unsigned int _order;
	/**
	*@brief	データ型の値のリセット
	*/
	void ResetData();
	/**
	*@brief	Collisionの生成
	*現在のform状況に応じてCollisionを生成する
	*/
	void CreateCollision();
public:
	/**
	*@brief	constructor
	*/
	explicit GameObject();
	/**
	*@brief constructor
	*@param[in]	Objform form オブジェクトの状態
	*@param[in]	string tag オブジェクトタグ名
	*@param[in]	Vec2 pos 位置
	*@param[in]	Vec2 scale 拡縮
	*@param[in] float angle 回転値
	*/
	explicit GameObject(
		const Objform& form,
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.0f);
	/**
	*@brief	destructor
	*/
	virtual ~GameObject();
	/**
	*@brief	オブジェクト初期化
	*@param[in]	Objform form オブジェクトの状態
	*@param[in]	string tag オブジェクトタグ名
	*@param[in]	Vec2 pos 位置
	*@param[in]	Vec2 scale 拡縮
	*@param[in] float angle 回転値
	*/
	void Init(
		const Objform& form,
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.0f);
	/**
	*@brief	当たり判定
	*@param[in]	GameObjet* object 相手のオブジェクト
	*@return bool hit true
	*/
	bool Hit(GameObject* object);
	/**
	*@brief	当たり判定
	*@param[in]	CollisionBase* object 相手のオブジェクト
	*@return bool hit true
	*/
	bool Hit(CollisionBase* object);
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
	*@brief	当たり判定確認
	*@param[in]	float lineWidth Lineの太さ
	*/
	void LineDraw(const float lineWidth = 1.0f);
	/**
	*@brief	大まかな範囲の判定を返す
	*@param[in]	GameObject* object 相手のオブジェクト
	*@return bool 判定内であればtrue
	*/
	bool IsObjectDistanceCheck(GameObject* object);
	/**
	*@brief	大まかな範囲の判定を返す
	*@param[in]	CollisionCircle* object 相手のオブジェクト
	*@return bool 判定内であればtrue
	*/
	bool IsObjectDistanceCheck(CollisionCircle* object);
	/**
	*@brief	大きな判定範囲を表示する
	*@param[in]	float lineWidth Lineの太さ
	*/
	void LineDistanceDraw(const float lineWidth = 1.0f);
	/**
	*@brief	当たり判定設定
	*@param[in]	bool flag 判定有無
	*/
	void CollisionConfig(const bool flag);
	/**
	*@brief	当たり判定設定の確認
	*@return bool 判定有無
	*/
	bool IsCollision() const;
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
	Vec2 GetPosition() const;
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
	*@brief	 回転設定
	*@param[in] float angle 回転角度
	*/
	void SetRotate(const float angle);
	/**
	*@brief	回転情報取得
	*@return float angle
	*/
	float GetRotate() const;
	/**
	*@brief	判定倍率
	*@param[in] Vec2 radius 倍率
	*/
	void SetRadius(const Vec2& radius);
	/**
	*@brief	判定倍率
	*@param[in] float x x座標倍率
	*@param[in]	float y y座標倍率
	*/
	void SetRadius(const float x, const float y);
	/**
	*@brief	判定倍率情報取得
	*@return[in] Vec2 radius
	*/
	Vec2 GetRadius() const;
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
	*@brief	質量設定
	*@param[in]	float mass 質量
	*/
	void SetMass(const float mass);
	/**
	*@brief	質量情報取得
	*@return float mass
	*/
	float GetMass() const;
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
	GO::Mode GetMode() const;
	/**
	*@brief	モード確認
	*@parma[in]	Mode mode 比較対象
	*@return bool 比較対象と同じならtrue
	*/
	bool ModeCheck(const GO::Mode& mode) const;
	/**
	*@brief	現在のformを返す
	*@return Objform 現在のform
	*/
	Objform Getform() const;
	/**
	*@brief	描画順指定
	*高い方が前に描画される
	*@param[in] unsigned int order 描画順値
	*/
	void SetDrawOrder(const unsigned int order);
	/**
	*@brief	描画順を取得
	*/
	unsigned int GetDrawOrder() const;
};