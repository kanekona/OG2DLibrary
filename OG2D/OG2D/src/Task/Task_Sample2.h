#pragma once
//____________________________
//|タスクサンプル              
//|履歴：2018/03/20  
//|___________________________

#include "OGSystem\OGsystem.h"

class Sample2 : public TaskObject
{
public:
	bool CheckOn();
	std::string taskName = "Sample2";
	virtual ~Sample2();
	typedef std::shared_ptr<Sample2> SP;
	static Sample2::SP Create(bool);
	Sample2();
	bool Initialize();
	void UpDate();
	void Render2D();
	bool Finalize();
};