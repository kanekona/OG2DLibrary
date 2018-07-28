#pragma once
//_____________________________
//|�T���v���^�X�N   
//|�����F2018/03/20
//|____________________________

#include "OGSystem\OGsystem.h"

class Sample : public TaskObject
{
public:
	virtual ~Sample();
	static Sample* Create(bool);
	Sample();
	bool Initialize();
	void UpDate() override;
	void Render2D() override;
	bool Finalize();
};