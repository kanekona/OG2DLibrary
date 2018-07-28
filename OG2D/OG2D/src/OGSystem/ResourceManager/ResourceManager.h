///���\�[�X�𐶐��A����A�Ǘ����s��class
///����GameEngine���g�p���Ă���ꍇ�͎����Ő��������
///�����ɓo�^���Ă�����͎̂�����delete�����̂Ŏ�����delete���Ȃ�����
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