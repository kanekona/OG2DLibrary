#pragma once
#include <Windows.h>
#include "OG\_OGsystem.h"
class WindowsEvent : private NonCopyable
{
	std::vector<std::string>* loadPath;
	std::vector<std::string>* notLoadFileName;
	void FileLoad(const std::string& filepath, std::vector<std::string>* vec);
public:
	explicit WindowsEvent();
	virtual ~WindowsEvent();
	std::vector<std::string> ResourceFileNameLoad(const std::string& filepath);
	void SetLoadPath(const std::string& path);
	void SetNotLoadFileName(const std::string& name);
};