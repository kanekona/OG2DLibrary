#pragma once
#include "OGSystem\ResourceManager\ResourceManager.h"
#include "OG\_OGsystem.h"
#include "Object\GameObject.h"
/**
*State�Ɠ��l�ɐ݌v���邪�A
*�X�V�����͕`�揈����EngineSystem�ɓo�^���Ď����I�ɍs�킹��
*���̂��ߑ匳��GameObject���g�p����
*�����蔻��n��nullptr�ɂ���Όy���Ȃ�H
*/
class EffectManager : private NonCopyable
{
	ResourceManager* rm;
public:
	explicit EffectManager(ResourceManager* manager);
};