#include "ResourceLoad.h"
#include "ResourceManager\ResourceManager.h"
ResourceLoad::ResourceLoad(std::ifstream& ifs)
{
	std::string lineText;
	while (std::getline(ifs, lineText))
	{
		//'/'�����ɂ��Ă�����͓̂ǂݍ��܂Ȃ�
		if (lineText.at(0) == '/')
		{
			continue;
		}
		this->DataCreate(lineText);
	}
}
ResourceLoad::~ResourceLoad()
{

}
void ResourceLoad::DataCreate(const std::string& text)
{
	//'>'�̑O�ƌ��string�f�[�^���킯��
	std::string::size_type t = text.find(">");
	this->dataPath = text.substr(0, t);
	this->dataName = text.substr(t + 1);
	//������̒��Ɉȉ��̕������܂܂�Ă���΂��̕������󔒂֕ύX����
	while ((t = dataName.find_first_of("(,);")) != std::string::npos)
	{
		dataName[t] = ' ';
	}
	std::stringstream ss;
	ss << dataName;

	std::string path, name;

	if (dataPath == "Texture")
	{
		ss >> path >> name;
		ResourceManager::Get()->CreateTexture(name, path);
	}
	else if (dataPath == "Sound")
	{
		ss >> path >> name;
		ResourceManager::Get()->CreateSound(name, path);
	}
	else if (dataPath == "Shader")
	{
		ss >> path >> name;
		ResourceManager::Get()->CreateShader(name, path);
	}
	else
	{
		std::cout << "ResourceLoad>>���o�^�̌`���ł�\n";
	}
}