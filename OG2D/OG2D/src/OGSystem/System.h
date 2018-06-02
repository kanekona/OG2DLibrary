#pragma once
//既存GameEngineClassを使用する場合OGSystem
//使用しない場合_OGSystem
//#include "_OGsystem.h"
#include "OGsystem.h"

class OGSystem
{
public:
	OGSystem();
	bool Create();
	bool LibConfirmation();
	virtual ~OGSystem();
};