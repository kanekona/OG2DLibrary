
#pragma once
#include "System\System_.h"
#include "OG\OGlib.h"
class WindowParameter;
class Window;
/**
*@brief	Window�̐����A�Ǘ����s��class
*/
class Window : private NonCopyable
{
	//! �A�C�R�����
	GLFWimage image[1];	
	//! �A�C�R���摜��ID
	GLuint id;
	//! �E�B���h�E�̃A�C�R������
	bool enableIcon;
	//! ������
	bool isVisualization;
	//! ��
	int widht;
	//! ����
	int height;
	//! Window�̖�
	const char* name;
	//! �t���X�N�ݒ�
	bool enableFullScreen;
	//! Window�̈ʒu
	Vec2Int position;
	//! Window���
	GLFWwindow *window;	
public:
	/**
	*@brief	constructor
	*/
	explicit Window();
	/**
	*@brief	constructor
	*@param[in]	int x windowX�T�C�Y
	*@param[in] int y windowY�T�C�Y
	*@param[in]	char* name window��
	*@param[in] bool flag �t���X�N�ݒ�
	*@param[in]	Vec2Int pos window�ʒu
	*/
	explicit Window(
		const int x,
		const int y,
		const char* name,
		const bool flag,
		const Vec2Int& pos);
	/**
	*@brief	destructor
	*/
	virtual ~Window();
	/**
	*@brief	Create Window
	*@param[in]	int x windowX�T�C�Y
	*@param[in] int y windowY�T�C�Y
	*@param[in]	char* name window��
	*@param[in] bool flag �t���X�N�ݒ�
	*@param[in]	Vec2Int pos window�ʒu
	*@return bool �����ɐ�����true
	*/
	bool Create(
		const int x,
		const int y,
		char* name,
		const bool flag,
		const Vec2Int& pos);
	/**
	*@brief	Create Window
	*@param[in] WindowParameter windowParameter
	*@return bool �����ɐ�����true
	*/
	bool Create(const WindowParameter& windowParameter);
	/**
	*@brief	Create Window
	*@return bool �����ɐ�����true
	*/
	bool Create();
	/**
	*@brief	�A�C�R����ݒ肷��
	*@param[in]	string path �t�@�C���p�X
	*/
	void SetIcon(const std::string& path);
	/**
	*@brief	Window�̃T�C�Y�ƃA�X�y�N�g����Œ肷��
	*/
	void Limits();
	/**
	*@brief	Window�̃T�C�Y�ƃA�X�y�N�g����Œ肷��
	*@param[in]	int w WindowSize_w
	*@param[in]	int h WindowSize_h
	*/
	void Limits(const int w, const int h);
	/**
	*@brief	Window���A�C�R�����A�A�C�R���������������
	*/
	void Enable();
	/**
	*@brief	Window�������A���������������
	*/
	void Visualization();
	/**
	*@brief	�}�E�X��\�������邩�����߂�
	*@param[in]	bool flag �\���ݒ�
	*/
	void InMouseMode(const bool flag);
	/**
	*@brief	Window�̃T�C�Y��Ԃ�
	*@return Vec2Int Window�̃T�C�Y
	*/
	Vec2Int GetSize() const;
	/**
	*@brief	Window�̈ʒu��Ԃ�
	*@return Vec2Int Window�̈ʒu
	*/
	Vec2Int GetPos() const;
	/**
	*@brief	��������Window�̈ʒu��ݒ肷��
	*@param[in]	Vec2Int pos Window�̈ʒu
	*/
	void CreatePosition(const Vec2Int& pos);
	/**
	*@brief	Window����Ԃ�
	*@return GLFWWinfow* Window���
	*/
	GLFWwindow* GetFWWindow() const;
	/**
	*@brief	Window�̈ʒu��ݒ肷��
	*@param[in]	const Vec2Int& pos �ʒu
	*/
	void SetPos(const Vec2Int& pos);
	/**
	*@brief	Window�̈ʒu��ݒ肷��
	*@param[in]	int x WindowPosition_x
	*@param[in]	int y WindowPosition_y
	*/
	void SetPos(const int x, const int y);
	/**
	*@brief	Window�̃T�C�Y��ݒ肷��
	*@param[in]	const Vec2Int& size �T�C�Y
	*/
	void SetSize(const Vec2Int& size);
	/**
	*@brief	Window�̃T�C�Y��ݒ肷��
	*@param[in]	int w WindowSize_w
	*@param[in]	int h WindowSize_h
	*/
	void SetSize(const int w,const int h);
	/**
	*@brief	ChengeWindowTitle
	*@param[in]	const char* name TitleName
	*/
	void ChengeTitle(const char* name);
	/**
	*@brief	Window���[�h��ύX
	*@param[in]	int x WindowPosition_x
	*@param[in]	int y WindowPosition_y
	*@param[in]	int w WindowSize_x
	*@param[in]	int h WindowSize_h
	*@param[in]	bool flag true hullScreen
	*/
	void ChangeMode(const int x,const int y,const int w, const int h, const bool flag);
	/**
	*@brief	Window���[�h��ύX
	*@param[in]	const Vec2Int& pos WindowPosition
	*@param[in]	const Vec2Int& size WindowSize
	*@param[in]	bool flag true fullScreen
	*/
	void ChangeMode(const Vec2Int& pos, const Vec2Int& size, const bool flag);
};
class WindowParameter
{
public:
	Vec2Int position;
	Vec2Int size;
	const char* name;
	bool enableFullScreen;
	WindowParameter(const Vec2Int& pos, const Vec2Int& scale, const char* name, const bool screen);
};