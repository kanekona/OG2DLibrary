/**
*既存GameEngineClassを使用する場合OGSystem
*使用しない場合_OGSystem
*/
#pragma once
#include "OGsystem.h"
///#include "_OGsystem.h"

class OGSystem : private NonCopyable
{
public:
	OGSystem();
	bool Create();
	bool LibConfirmation();
	virtual ~OGSystem();
};