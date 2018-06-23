#pragma once
//_____________________________
//|サンプルタスク   
//|履歴：2018/03/20
//|____________________________

#include "OGSystem\OGsystem.h"

class Sample : public TaskObject
{
public:
	class Param
	{
	public:
		bool on;
		unsigned int cnt;
		std::mutex mutex;
		FPS fps;
		Param() { on = true; cnt = 0; }
	};
private:
	Texture testImg;
	Time time;
	std::shared_ptr<Param> param;

public:
	
	std::string taskName = "Sample";
	virtual ~Sample();
	typedef std::shared_ptr<Sample> SP;
	static Sample::SP Create(bool);
	Sample();
	static void Render(Texture* tex, std::shared_ptr<Sample::Param>& param);
	bool Initialize();
	void UpDate();
	void Render2D();
	void Pause();
	bool Finalize();
};