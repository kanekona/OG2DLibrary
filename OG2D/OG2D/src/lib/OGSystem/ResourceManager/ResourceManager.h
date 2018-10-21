
#pragma once
#include "OGSystem\Audio\Sound.h"
#include "OGSystem\Texture\Texture.h"
#include "OGSystem\Shader\shader.h"
/**
*@brief	リソースを生成、解放、管理を行うclass
*
*既存GameEngineを使用している場合は自動で生成される
*
*ここに登録しているものはEngine終了時自動でdeleteされるので自分でdeleteしないこと
*
*newせず登録したものは自分でDeleteResource呼んで消しておくこと
*/
class ResourceManager : private NonCopyable
{
	//! サウンドデータ
	std::vector<std::pair<std::string, Sound*>> soundData;
	//! テクスチャデータ
	std::vector<std::pair<std::string, Texture*>> textureData;
	//! シェーダーデータ
	std::vector<std::pair<std::string, Shader*>> shaderData;
public:
	/**
	*@brief	存在するサウンドデータのポインタを登録する
	*@param[in] string name 登録名
	*@param[in]	Sound* sound サウンドデータのポインタ
	*/
	void SetSoundData(const std::string& name,Sound* sound);
	/**
	*@brief	新しくサウンドを生成しデータに登録する
	*@param[in] string name 登録名
	*@param[in]	string path ファイルのパス
	*@return bool 生成に成功でtrueを返す
	*/
	bool CreateSound(const std::string& name, const std::string& path);
	/**
	*@brief	登録されているサウンドデータを返す
	*@param[in] string name　登録名
	*@return Sound* 登録されているサウンドを返す
	*/
	Sound* GetSoundData(const std::string& name);
	/**
	*@brief	存在するテクスチャデータのポインタを登録する
	*@param[in]	string 登録名
	*@param[in]	Texture* tex テクスチャデータのポインタ
	*/
	void SetTextureData(const std::string& name,Texture* tex);
	/**
	*@brief	新しくテクスチャを生成しデータを登録する
	*@param[in]	string name 登録名
	*@param[in]	string path ファイルのパス
	*@return bool 生成に成功でtrueを返す
	*/
	bool CreateTexture(const std::string& name, const std::string& path);
	/**
	*@brief	登録されているテクスチャデータを返す
	*@param[in] string name 登録名
	*@return Sound* 登録されているテクスチャを返す
	*/
	Texture* GetTextureData(const std::string& name);
	/**
	*@brief	登録されているテクスチャデータを破棄,deleteする
	*@param[in]	string name 登録名
	*@return bool 削除に成功でtrue
	*/
	bool DeleteTexture(const std::string& name);
	/**
	*@brief	登録されているサウンドデータを破棄,deleteする
	*@param[in]	string name 登録名
	*@return bool 削除に成功でtrue
	*/
	bool DeleteSound(const std::string& name);
	/**
	*@brief	新しくシェーダーを生成しデータを登録する
	*@param[in] const string& name 登録名
	*@param[in] const string& path ファイルパス
	*@return bool 生成に成功でtrueを返す
	*/
	bool CreateShader(const std::string& name, const std::string& path);
	/**
	*@brief	登録されているシェーダーデータを取得する
	*@param[in] const string& name 登録名
	*@return Shader* 登録されているシェーダーデータ
	*/
	Shader* GetShaderData(const std::string& name);
	/**
	*@brief	destructor 
	*全データを破棄,deleteする
	*/
	virtual ~ResourceManager();
};