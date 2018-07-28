///リソースを生成、解放、管理を行うclass
///既存GameEngineを使用している場合は自動で生成される
///ここに登録しているものは自動でdeleteされるので自分でdeleteしないこと
#pragma once
#include "OGSystem\Audio\Sound.h"
#include "OGSystem\Texture\Texture.h"

class ResourceManager
{
	//std::vector<S_Data> soundData;
	std::vector<std::pair<std::string, Sound*>> soundData;
	//std::vector<T_Data> textureData;
	std::vector<std::pair<std::string, Texture*>> textureData;
public:
	void SetSoundData(const std::string&,Sound*);
	bool CreateSound(const std::string&, const std::string&);
	Sound* GetSoundData(const std::string&);
	void SetTextureData(const std::string&,Texture*);
	bool CreateTexture(const std::string&, const std::string&);
	Texture* GetTextureData(const std::string&);
	bool DeleteTexture(const std::string&);
	bool DeleteSound(const std::string&);
	virtual ~ResourceManager();
};