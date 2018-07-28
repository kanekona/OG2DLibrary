#pragma once
//_____________________________
//|サンプルタスク   
//|履歴：2018/03/20
//|____________________________

#include "OGSystem\OGsystem.h"

class Sample : public TaskObject
{
private:
	Texture testImg;

public:
	
	std::string taskName = "Sample";
	virtual ~Sample();
	typedef std::shared_ptr<Sample> SP;
	static Sample::SP Create(bool);
	Sample();
	bool Initialize();
	void UpDate();
	void Render2D();
	void Pause();
	bool Finalize();
};