#pragma once
#include "OG\OGsystem.h"
/**
*@brief	Window���t���X�N���[����Window�ŊJ�����ݒ���s��Scene
*/
class ConfigTask : public SceneTask
{
	//! ��Scene�����WindowMode�l
	bool nextWindowMode;
	/**
	*@brief	constructor
	*/
	explicit ConfigTask();
	/**
	*@brief	�X�V����
	*/
	void Update() override;
	/**
	*@brief	�����폜����
	*@param[in]	bool flag NextWindowMode
	*/
	void Destroy(const bool flag);
public:
	/**
	*@brief	destructor
	*/
	virtual ~ConfigTask();
	/**
	*@brief	Scene����
	*@return ConfigTask* ����Scene
	*/
	static ConfigTask* Create();
};