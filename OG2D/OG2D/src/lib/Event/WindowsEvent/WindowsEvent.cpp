#include "WindowsEvent.h"
WindowsEvent::WindowsEvent()
{
	this->loadPath = nullptr;
	this->notLoadFileName = nullptr;
}
WindowsEvent::~WindowsEvent()
{
	OG::Destroy<std::vector<std::string>>(this->loadPath);
	OG::Destroy<std::vector<std::string>>(this->notLoadFileName);
}
void WindowsEvent::SetLoadPath(const std::string& path)
{
	if (this->loadPath)
	{
		this->loadPath->emplace_back(path);
	}
	else
	{
		this->loadPath = new std::vector<std::string>;
		this->loadPath->emplace_back(path);
	}
}
void WindowsEvent::SetNotLoadFileName(const std::string& name)
{
	if (this->notLoadFileName)
	{
		this->notLoadFileName->emplace_back(name);
	}
	else
	{
		this->notLoadFileName = new std::vector<std::string>;
		this->notLoadFileName->emplace_back(name);
	}
}

std::vector<std::string> WindowsEvent::ResourceFileNameLoad(const std::string& filepath)
{
	std::vector<std::string> filename;
	this->FileLoad(filepath, &filename);
	return filename;
}


void WindowsEvent::FileLoad(const std::string& filepath, std::vector<std::string>* vec)
{
	WIN32_FIND_DATA findData;
	std::string allFilePath =  filepath + "\\*.*";
	HANDLE hfile = FindFirstFile(allFilePath.c_str(), &findData);
	if (INVALID_HANDLE_VALUE == hfile)
	{
		return;
	}
	do
	{
		if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if ('.' == findData.cFileName[0])
			{
				if (('\0' == findData.cFileName[1]) || ('.' == findData.cFileName[1] && '\0' == findData.cFileName[2]))
				{
					continue;
				}
			}
			if (this->notLoadFileName)
			{
				std::string tmp = findData.cFileName;
				for (int i = 0; i < this->notLoadFileName->size(); ++i)
				{
					std::cout << findData.cFileName << ":" << *this->notLoadFileName[i].data() << "\n";
					//if (!OG::CheckText(&tmp, &(*notLoadFileName)[i]))
					if(tmp != this->notLoadFileName->at(i))
					{
						FileLoad(allFilePath.substr(0, allFilePath.size() - 4) + "\\" + findData.cFileName, vec);
						break;
					}
				}
			}
			else
			{
				FileLoad(allFilePath.substr(0, allFilePath.size() - 4) + "\\" + findData.cFileName, vec);
			}
		}
		else
		{
			if (this->loadPath)
			{
				std::string tmp = findData.cFileName;
				for (int i = 0; i < loadPath->size(); ++i)
				{
					if (OG::CheckText(&tmp, &(*loadPath)[i]))
					{
						vec->emplace_back(std::string(allFilePath.substr(0, allFilePath.size() - 4) + "\\" + findData.cFileName));
						break;
					}
				}
			}
			else
			{
				vec->emplace_back(std::string(allFilePath.substr(0, allFilePath.size() - 4) + "\\" + findData.cFileName));
			}
		}
	} while (FindNextFile(hfile, &findData));
	FindClose(hfile);
}