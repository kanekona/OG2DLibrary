#pragma once
//_____________________________
//|ゲームオブジェクト            
//|履歴：2018/03/20   
//|____________________________
#include "OGSystem\_OGsystem.h"
#include "OGSystem\Collision\Collision.h"
/**
*enum Objform
*オブジェクトの形の設定
*/
enum Objform
{
	//! 無
	Non,
	//!	円
	Ball,
	//! 矩形
	Cube,
	//! 点
	Pointer,
	//! 線
	Line,
};
/**
*enum Mode
*状態の設定
*/
namespace GO
{
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
	Collision* _collision;
	CollisionBase* base;
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
	*@brief	:データ型の値のリセット
	*/
	void ResetData();
	/**
	*@brief	:Collisionの生成
	*現在のform状況に応じてCollisionを生成する
	*/
	void CreateCollision();
public:
	/**
	*@brief	:constructor
	*/
	explicit GameObject();
	/**
	*@brief	:constructor
	*@param	:Objform form オブジェクトの状態
	*@param	:string tag オブジェクトタグ名
	*@param	:Vec2 pos 位置
	*@param	:Vec2 scale 拡縮
	*@param :float angle 回転値
	*/
	explicit GameObject(
		const Objform& form,
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.0f);
	/**
	*@brief	:destructor
	*/
	virtual ~GameObject();
	/**
	*@brief	:オブジェクト初期化
	*@param	:Objform form オブジェクトの状態
	*@param	:string tag オブジェクトタグ名
	*@param	:Vec2 pos 位置
	*@param	:Vec2 scale 拡縮
	*@param :float angle 回転値
	*/
	void Init(
		const Objform& form,
		const std::string& tag,
		const Vec2& pos,
		const Vec2& scale,
		const float angle = 0.0f);
	/**
	*@brief	:当たり判定
	*@param	:GameObjet* object 相手のオブジェクト
	*@return:bool hit true
	*/
	bool Hit(GameObject* object);
	/**
	*@brief	:当たり判定
	*@param	:CollisionBase* object 相手のオブジェクト
	*@return:bool hit true
	*/
	bool Hit(CollisionBase* object);
	/**
	*@brief	:更新処理
	*/
	virtual void Update();
	/**
	*@brief	:停止処理
	*/
	virtual void Pause();
	/**
	*@brief	:描画処理
	*/
	virtual void Render2D();
	/**
	*@brief	:更新管理
	*/
	void UpdateManager();
	/**
	*@brief	:描画管理
	*/
	void RenderManager();
	/**
	*@brief	:当たり判定確認
	*@param	:float lineWidth Lineの太さ
	*/
	void LineDraw(const float lineWidth = 1.0f);
	/**
	*@brief	:大まかな範囲の判定を返す
	*@param	:GameObject* object 相手のオブジェクト
	*@return:bool 判定内であればtrue
	*/
	bool IsObjectDistanceCheck(GameObject* object);
	/**
	*@brief	:大まかな範囲の判定を返す
	*@param	:CollisionCircle* object 相手のオブジェクト
	*@return:bool 判定内であればtrue
	*/
	bool IsObjectDistanceCheck(CollisionCircle* object);
	/**
	*@brief	:大きな判定範囲を表示する
	*@param	:float lineWidth Lineの太さ
	*/
	void LineDistanceDraw(const float lineWidth = 1.0f);
	/**
	*@brief	:当たり判定設定
	*@param	:bool flag 判定有無
	*/
	void CollisionConfig(const bool flag);
	/**
	*@brief	:当たり判定設定の確認
	*@return:bool 判定有無
	*/
	bool IsCollision() const;
	/**
	*@brief	:位置設定
	*@param	:Vec2 pos 位置
	*/
	void SetPosition(const Vec2& pos);
	/**
	*@brief	:位置設定
	*@param	:float x 位置X座標
	*@param	:float y 位置Y座標
	*/
	void SetPosition(const float x, const float y);
	/**
	*@brief	:位置情報取得
	*@return:Vec2 Position
	*/
	Vec2 GetPosition() const;
	/**
	*@brief	:拡縮設定
	*@param	:Vec2 scale 拡縮
	*/
	void SetScale(const Vec2& scale);
	/**
	*@brief	:拡縮設定
	*@param	:float x 拡縮X
	*@param	:float y 拡縮Y
	*/
	void SetScale(const float x, const float y);
	/**
	*@brief	:拡縮情報取得
	*@return:Vec2 Scale
	*/
	Vec2 GetScale() const;
	/**
	*@brief	:回転設定
	*@param	:float angle 回転角度
	*/
	void SetRotate(const float angle);
	/**
	*@brief	:回転情報取得
	*@return:float angle
	*/
	float GetRotate() const;
	/**
	*@brief	:判定倍率
	*@param :Vec2 radius 倍率
	*/
	void SetRadius(const Vec2& radius);
	/**
	*@brief	:判定倍率
	*@param :float x x座標倍率
	*@param	:float y y座標倍率
	*/
	void SetRadius(const float x, const float y);
	/**
	*@brief	:判定倍率情報取得
	*@return:Vec2 radius
	*/
	Vec2 GetRadius() const;
	/**
	*@brief	:タグ設定
	*@param	:string name tagname
	*/
	void SetTag(const std::string& name);
	/**
	*@brief	:タグ情報取得
	*@return:string objecttag
	*/
	std::string GetTag() const;
	/**
	*@brief	:質量設定
	*@param	:float mass 質量
	*/
	void SetMass(const float mass);
	/**
	*@brief	:質量情報取得
	*@return:float mass
	*/
	float GetMass() const;
	/**
	*@brief	:オブジェクトを削除する
	*/
	void Kill();
	/**
	*@brief	:削除命令をキャンセルする
	*/
	void CancelKill();
	/**
	*@brief	:Pause設定
	*@param	:bool flag trueでPause化
	*/
	void SetPause(const bool flag = true);
	/**
	*@brief	:停止設定
	*@param	:bool flag trueで停止
	*/
	void SetStop(const bool flag = true);
	/**
	*@brief	:全機能停止
	*@param	:bool flag trueで全停止
	*/
	void SetAllStop(const bool flag = true);
	/**
	*@brief	:現状の状態を返す
	*@return:Mode 状態
	*/
	GO::Mode GetMode() const;
	/**
	*@brief	:モード確認
	*@parma	:Mode mode 比較対象
	*@return:bool 比較対象と同じならtrue
	*/
	bool ModeCheck(const GO::Mode& mode) const;
	/**
	*@brief	:現在のformを返す
	*@return:Objform 現在のform
	*/
	Objform Getform() const;
	/**
	*@brief	:描画順指定
	*@param :unsigned int order 描画順値
	*高い方が前に描画される
	*/
	void SetDrawOrder(const unsigned int order);
	/**
	*@brief	:描画順を取得
	*/
	unsigned int GetDrawOrder() const;
};

/**
*enum Objform
*オブジェクトの形
*/
//enum Objform
//{
//	//! 無
//	Non,
//	//!	円
//	Ball,
//	//! 矩形
//	Cube,
//	//! 点
//	Pointer,
//	//! 線
//	Line,
//};
/**
*@brief	:ゲームで使用するオブジェクト用class
*/
//class GameObject : public TaskObject
//{
//	//! 当たり判定を行う有無
//	bool isCheck;
//public:
//	//! オブジェクトの状態
//	Objform objform;
//	//! 位置
//	Vec2 position;
//	//! サイズ
//	Vec2 Scale;
//	//! 半径
//	Vec2 Radius;
//	//! 回転度
//	float angle;
//	//! 矩形当たり判定
//	CollisionBox collisionCube;
//	//! 円当たり判定
//	CollisionCircle collisionBall;
//	//! 重力の有無
//	bool isGravity;
//	//! 質量
//	float mass;
//	//! オブジェクトのタグ名
//	std::string objectTag;
//	/**
//	*@brief	:GameObject同士の当たり判定
//	*@param	:GameObject o 相手のオブジェクト
//	*@return:bool 当たっていればtrue
//	*/
//	bool hit(GameObject& o);
//	/**
//	*@fn
//	*回転を行わない当たり判定
//	*@brief	:矩形Object同士の簡易当たり判定
//	*@param	:GameObject o 相手のオブジェクト
//	*@return:bool 当たっていればtrue
//	*/
//	bool CubeHit(GameObject& o);
//	/**
//	*@brief	:constructor
//	*/
//	GameObject();
//	/**
//	*@brief	:constructor
//	*@param	:Objform form オブジェクトの形
//	*@param	:Vec2 _posi 位置
//	*@param	:Vec2 _Sca 大きさ
//	*@param	:float _ang	回転値
//	*/
//	GameObject(
//		const Objform& form, 
//		const Vec2& _posi, 
//		const Vec2& _Sca, 
//		float _ang = 0.0f
//	);
//	/**
//	*@brief	:destructor
//	*/
//	~GameObject();
//	/**
//	*@brief	:オブジェクトの情報を登録する
//	*@param	:Objform form オブジェクトの形
//	*@param	:Vec2 _posi 位置
//	*@param	:Vec2 _Sca 大きさ
//	*@param	:float _ang	回転値
//	*/
//	void CreateObject(
//		const Objform& form,
//		const Vec2& _posi,
//		const Vec2& _Sca,
//		const float _ang = 0.0f
//	);
//	/**
//	*@brief	:当たり判定に線を引く
//	*/
//	void LineDraw();
//	/**
//	*@brief	:当たり判定を付ける
//	*@param	:bool flag 当たり判定を行う設定
//	*/
//	void HitCheck(bool flag = true);
//	/**
//	*@brief	:当たり判定を行う範囲かを返す
//	*@param	:Vec2 pos 相手の位置
//	*@param	:Vec2 size 相手の大きさ
//	*@return:bool 判定内であればtrue
//	*/
//	bool IsObjectDistanceCheck(const Vec2& pos, const Vec2& size);
//	/**
//	*@brief	:大きな判定範囲を表示する
//	*/
//	void LineDistanceDraw();
//	/**
//	*@brief	:初期設定移動処理(未実装)
//	*/
//	virtual void Move();
//	/**
//	*@brief	:初期設定重力処理(未実装)
//	*/
//	virtual void Friction();
//private:
//};