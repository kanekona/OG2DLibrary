/**
*����GameEngineClass���g�p����ꍇOGSystem
*�g�p���Ȃ��ꍇ_OGSystem
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