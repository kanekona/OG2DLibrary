#include "ResourceManager.h"

void ResourceManager::SetSoundData(const std::string& dataname,Sound* sound)
{
	for (auto id = this->soundData.begin(); id != soundData.end(); ++id)
	{
		if ((*id).first == dataname)
		{
			return;
		}
	}
	std::pair<std::string, Sound*> d;
	d.first = dataname;
	d.second = sound;
	this->soundData.emplace_back(d);
}

bool ResourceManager::CreateSound(const std::string& name,const std::string& path)
{
	for (auto id = this->soundData.begin(); id != this->soundData.end(); ++id)
	{
		if ((*id).first == name)
		{
			return false;
		}
	}
	Sound* so = new Sound();
	so->Create(path);
	std::pair<std::string, Sound*> d;
	d.first = name;
	d.second = so;
	this->soundData.emplace_back(d);
	return true;
}

void ResourceManager::SetTextureData(const std::string& dataname, Texture* texture)
{
	for (auto id = this->textureData.begin(); id != this->textureData.end(); ++id)
	{
		if ((*id).first == dataname)
		{
			return;
		}
	}
	std::pair<std::string, Texture*> d;
	d.first = dataname;
	d.second = texture;
	this->textureData.emplace_back(d);
}

bool ResourceManager::CreateTexture(const std::string& name, const std::string& path)
{
	for (auto id = this->textureData.begin(); id != this->textureData.end(); ++id)
	{
		if ((*id).first == name)
		{
			return false;
		}
	}
	Texture* tex = new Texture(path);
	std::pair<std::string, Texture*> d;
	d.first = name;
	d.second = tex;
	this->textureData.emplace_back(d);
	return true;
}

Sound* ResourceManager::GetSoundData(const std::string& dataname)
{
	for (auto id = this->soundData.begin(); id != this->soundData.end(); ++id)
	{
		if ((*id).first == dataname)
		{
			return (*id).second;
		}
	}
	return nullptr;
}

Texture* ResourceManager::GetTextureData(const std::string& dataname)
{
	for (auto id = this->textureData.begin(); id != this->textureData.end(); ++id)
	{
		if ((*id).first == dataname)
		{
			return (*id).second;
		}
	}
	return nullptr;
}

ResourceManager::~ResourceManager()
{
	for (auto& d : this->soundData)
	{
		if (d.second)
		{
			delete d.second;
		}
	}
	for (auto& d : this->textureData)
	{
		if (d.second)
		{
			delete d.second;
		}
	}
	for (auto& d : this->shaderData)
	{
		if (d.second)
		{
			delete d.second;
		}
	}
	for (auto& d : this->layerData)
	{
		if (d.second)
		{
			delete d.second;
		}
	}
	this->soundData.clear();
	this->textureData.clear();
	this->shaderData.clear();
	this->layerData.clear();
}

bool ResourceManager::DeleteTexture(const std::string& name)
{
	for (auto id = this->textureData.begin(); id != this->textureData.end(); ++id)
	{
		if ((*id).first == name)
		{
			if ((*id).second)
			{
				delete (*id).second;
			}
			this->textureData.erase(id);
			return true;
		}
	}
	return false;
}

bool ResourceManager::DeleteSound(const std::string& name)
{
	for (auto id = this->soundData.begin(); id != this->soundData.end(); ++id)
	{
		if ((*id).first == name)
		{
			if ((*id).second)
			{
				delete (*id).second;
			}
			this->soundData.erase(id);
			return true;
		}
	}
	return false;
}

bool ResourceManager::CreateShader(const std::string& name, const std::string& path)
{
	for (auto id = this->shaderData.begin(); id != this->shaderData.end(); ++id)
	{
		if ((*id).first == name)
		{
			return false;
		}
	}
	Shader* shader = new Shader();
	shader->Read(path);
	shader->Use();
	std::pair<std::string, Shader*> d;
	d.first = name;
	d.second = shader;
	this->shaderData.emplace_back(d);
	return true;
}

Shader* ResourceManager::GetShaderData(const std::string& dataname)
{
	for (auto id = this->shaderData.begin(); id != this->shaderData.end(); ++id)
	{
		if ((*id).first == dataname)
		{
			return (*id).second;
		}
	}
	return nullptr;
}

bool ResourceManager::CreateLayer(const std::string& name)
{
	for (auto id = this->layerData.begin(); id != this->layerData.end(); ++id)
	{
		if ((*id).first == name)
		{
			return false;
		}
	}
	LayerTexture* layer = new LayerTexture();
	std::pair<std::string, LayerTexture*> d;
	d.first = name;
	d.second = layer;
	this->layerData.emplace_back(d);
	return true;
}

bool ResourceManager::DeleteLayer(const std::string& name)
{
	for (auto id = this->layerData.begin(); id != this->layerData.end(); ++id)
	{
		if ((*id).first == name)
		{
			if ((*id).second)
			{
				delete (*id).second;
			}
			this->layerData.erase(id);
			return true;
		}
	}
	return false;
}

LayerTexture* ResourceManager::GetLayer(const std::string& dataname)
{
	for (auto id = this->layerData.begin(); id != this->layerData.end(); ++id)
	{
		if ((*id).first == dataname)
		{
			return (*id).second;
		}
	}
	return nullptr;
}

ResourceManager* ResourceManager::Create()
{
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}
	return ResourceManager::Get();
}
ResourceManager* ResourceManager::Get()
{
	return instance;
}
void ResourceManager::Destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}