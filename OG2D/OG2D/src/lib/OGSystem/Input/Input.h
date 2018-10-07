
#pragma once
#include "OG\_OGsystem.h"
#include "OGSystem\Collision\Collision.h"

/**
*namespace In
*@brief	�ȈՈ����p
*/
namespace In
{
	/**
	*enum Button
	*@brief	�����R���g���[���̓��͐ݒ�
	*/
	enum Button
	{
		//!	1
		BUTTON_A,		
		//! 2
		BUTTON_B,
		//! 3
		BUTTON_X,
		//! 4
		BUTTON_Y,
		//! 5
		BUTTON_L1,
		//! 6
		BUTTON_R1,		
		//! 7
		BUTTON_BACK,
		//! 8
		BUTTON_START,
		//! 9
		BUTTON_L3,
		//! 10
		BUTTON_R3,
		//! 11
		BUTTON_U,
		//! 12
		BUTTON_R,
		//! 13
		BUTTON_D,
		//! 14
		BUTTON_L,
	};
	/**
	*enum AXIS
	*@brief	�R���g���[���̃X�e�B�b�N�Ɖ�������
	*/
	enum AXIS
	{
		//! ���X�e�B�b�NX�l
		AXIS_LEFT_X,		
		//! ���X�e�B�b�NY�l
		AXIS_LEFT_Y,	
		//! �E�X�e�B�b�NX�l
		AXIS_RIGHT_X,	
		//! �E�X�e�B�b�NY�l
		AXIS_RIGHT_Y,
		//!	R2
		AXIS_R2,
		//! L2
		AXIS_L2,
		//! AXISNumber
		AXIS_BUTTON_NUM,
	};
	/**
	*enum StickButton
	*@brief	�X�e�B�b�N���{�^��Button���͂ɂ��Ή�
	*/
	enum StickButton
	{
		//! ���X�e�B�b�N������
		LSTICK_LEFT,
		//! ���X�e�B�b�N�E����
		LSTICK_RIGHT,
		//! ���X�e�B�b�N�����
		LSTICK_UP,
		//! ���X�e�B�b�N������
		LSTICK_DOWN,
		//! �E�X�e�B�b�N������
		RSTICK_LEFT,
		//! �E�X�e�B���N�E����
		RSTICK_RIGHT,
		//! �E�X�e�B�b�N�����	
		RSTICK_UP,
		//! �E�X�e�B�b�N������
		RSTICK_DOWN,
		//! R2
		BUTTON_R2,
		//! L2
		BUTTON_L2,
		//! �X�e�B�b�N��
		STICK_NUM,
	};
	/**
	*enum IN
	*@brief	���z����
	*/
	enum IN
	{
		B1,
		B2,
		B3,
		B4,
		CD,
		CU,
		CR,
		CL,
		L1,
		R1,
		D1,
		D2,
		SR,
		SL,
		LD,
		LU,
		LR,
		LL,
		RD,
		RU,
		RR,
		RL,
		L2,
		R2,
	};
	/**
	*enum Key
	*@brief	�L�[�{�[�h����
	*/
	enum Key
	{
		A, S, D, W, Q, E, Z, X, C, R, F, V, T,
		G, B, Y, H, N, U, J, M, I, K, O, L, P,
		SPACE, ENTER, ESCAPE,
		UP, DOWN, LEFT, RIGHT,
	};
}
/**
*namespace Mouse
*@brief	�}�E�X�p�ȈՈ���
*/
namespace Mouse
{
	/**
	*enum Button
	*@brief	Mouse�̃{�^��
	*/
	enum Button
	{
		//! ��
		LEFT,
		//! �E
		RIGTH,
		//! ���S
		CENTER,
		BUTTON_4,
		BUTTON_5,
		BUTTON_6,
		BUTTON_7,
		BUTTON_8,
	};
}
/**
*@brief	�Q�[���p�b�h�A�L�[�{�[�h�A�}�E�X�̓��͂�����class
*
*����GameEngine���g�p���Ă���ꍇ�͎����Ő��������
*/
class Input : private NonCopyable
{
public:
	/**
	*enum in
	*@brief	���͗p���z����
	*/
	enum in {
		B1,
		B2,
		B3,
		B4,
		CD,
		CU,
		CR,
		CL,
		L1,
		R1,
		D1,
		D2,
		SR,
		SL,
		LD,
		LU,
		LR,
		LL,
		RD,
		RU,
		RR,
		RL,
		L2,
		R2,
	};
	/**
	*@brief	�Q�[���p�b�h����
	*/
	class GamePad
	{
	public:
		/**
		*enum Pad
		*@brief	�����R���g���[���̓��͐ݒ�
		*/
		enum Pad
		{
			//! 1
			BUTTON_A,
			//! 2
			BUTTON_B,
			//! 3
			BUTTON_X,
			//! 4
			BUTTON_Y,		
			//! 5
			BUTTON_L1,		
			//! 6
			BUTTON_R1,		
			//! 7
			BUTTON_BACK,	
			//! 8
			BUTTON_START,	
			//! 9
			BUTTON_L3,		
			//! 10
			BUTTON_R3,		
			//! 11
			BUTTON_U,		
			//! 12
			BUTTON_R,	
			//! 13
			BUTTON_D,	
			//! 14
			BUTTON_L,	
		};
		/**
		*enum AXIS
		*@brief	�����R���g���[���̓��͐ݒ�
		*/
		enum AXIS {
			//! ���X�e�B�b�NX�l
			AXIS_LEFT_X,
			//! ���X�e�B�b�NY�l
			AXIS_LEFT_Y,
			//! �E�X�e�B�b�NX�l
			AXIS_RIGHT_X,
			//! �E�X�e�B�b�NY�l
			AXIS_RIGHT_Y,
			//!	R2
			AXIS_R2,
			//! L2
			AXIS_L2,
			//! ButtonNumber
			AXIS_BUTTON_NUM,
		};
		/**
		*enum AXISBUTTON
		*@brief	�����R���g���[���̓��͐ݒ�
		*/
		enum AXISBUTTON
		{
			//! ���X�e�B�b�N������
			LSTICK_LEFT,
			//! ���X�e�B�b�N�E����
			LSTICK_RIGHT,
			//! ���X�e�B�b�N�����
			LSTICK_UP,
			//! ���X�e�B�b�N������
			LSTICK_DOWN,
			//! �E�X�e�B�b�N������
			RSTICK_LEFT,
			//! �E�X�e�B���N�E����
			RSTICK_RIGHT,
			//! �E�X�e�B�b�N�����	
			RSTICK_UP,
			//! �E�X�e�B�b�N������
			RSTICK_DOWN,
			//! R2
			BUTTON_R2,
			//! L2
			BUTTON_L2,
			//! �X�e�B�b�N��
			STICK_NUM,
		};
		/**
		*@brief	constructor
		*@param[in]	int id �Q�[���p�b�h�ԍ�
		*/
		explicit GamePad(const int id);
		/**
		*@brief	�����Ă��锻���Ԃ�
		*@param[in] int index ������s���������͔ԍ�
		*@return bool �����Ă����true
		*/
		bool on(const int index) const;
		/**
		*@brief	�������u�Ԃ̔����Ԃ�
		*@param[in] int index ������s���������͔ԍ�
		*@return bool �������u�Ԃł����true
		*/
		bool down(const int index) const;
		/**
		*@brief	�������u�Ԃ̔����Ԃ�
		*@param[in] int index ������s���������͔ԍ�
		*@return bool �������u�Ԃł����true
		*/
		bool up(const int index) const;
		/**
		*@brief	�S�Ă�down���͂̂����P�ł����肪���邩���ׂ�
		*@return 1�ȏ���͂���Ă����true
		*/
		bool EitherDown() const;
		/**
		*@brief	�S�Ă�on���͂̂����P�ł����肪���邩���ׂ�
		*@return 1�ȏ���͂���Ă����true
		*/
		bool EitherOn() const;
		/**
		*@brief	�S�Ă�up���͂̂����P�ł����肪���邩���ׂ�
		*@return 1�ȏ���͂���Ă����true
		*/
		bool EitherUp() const;
		/**
		*@brief	�w��l�̃X�e�B�b�N�̌X����Ԃ�
		*@param[in]	int index �X�e�B�b�N�w��
		*@return float �X���x(0~1)
		*/
		float axis(const int index) const;
		/**
		*@brief	�w��X�e�B�b�N�̉�����Ԃ�Ԃ�
		*@param[in]	int index �X�e�B�b�N�w��
		*@return bool �w�葤�ɓ|��Ă����true
		*/
		bool axis_on(const int index) const;
		/**
		*@brief	�w��X�e�B�b�N�̉�����Ԃ�Ԃ�
		*@param[in]	int index �X�e�B�b�N�w��
		*@return bool �w�葤�ɓ|���ꂽ�u�Ԃł����true
		*/
		bool axis_down(const int index) const;
		/**
		*@brief	�w��X�e�B�b�N�̉�����Ԃ�Ԃ�
		*@param[in]	int index �X�e�B�b�N�w��
		*@return bool �w�葤����オ�����u�Ԃł����true
		*/
		bool axis_up(const int index) const;
		/**
		*@brief	�Q�[���p�b�h�̗L����Ԃ�
		*@return bool ���݂����true
		*/
		bool isPresent() const;
		/**
		*@brief	���͏󋵂̍X�V
		*/
		void Update();
		/**
		*@brief	�e�l�̏�����
		*/
		void Initialize();
		/**
		*@brief	���͏�Ԃ̃��Z�b�g
		*/
		void Reset();
		/**
		*@brief	�X�e�B�b�N�͈̔͊O����
		*@param[in]	float axis_threshold_ ��؂�l
		*@return ����true
		*/
		bool registAxisButton(
			const float axis_threshold_);
		/**
		*@brief	�Q�[���p�b�h����Ԃ�
		*@return char* �Q�[���p�b�h��
		*/
		const char* GetName() const;
	private:
		//! �Q�[���p�b�h�����ɑΉ������邽�߂ɂP�P��id��U�蕪����
		int id_;
		//! �Q�[���p�b�h�̃{�^����
		int button_num;
		//! �Q�[���p�b�h�̃X�e�B�b�N��
		int axis_num;
		//! ���̓f�[�^���i�[����ϐ�
		int GPadData[14];
		//! �X�e�B�b�N�����i�[����ϐ�
		std::vector<float> axis_value;
		//! �X�e�B�b�N�̒��_�l
		float axis_threshold;
		//! button��on���i�[����ϐ�
		std::vector<u_char> button_on;
		//! button��down���i�[����ϐ�
		std::vector<u_char> button_down;
		//! button��up���i�[����ϐ�
		std::vector<u_char> button_up;
		//! axis��on���i�[����ϐ�
		std::vector<u_char> axis_button_on;
		//! axis��down���i�[����ϐ�
		std::vector<u_char> axis_button_down;
		//! axis��up���i�[����ϐ�
		std::vector<u_char> axis_button_up;
		//! �R���g���[����
		const char* name;
		/**
		*@brief	�{�^������Ԃ�
		*@return int �{�^����
		*/
		int buttons() const;
		/**
		*@brief	�X�e�B�b�N����Ԃ�
		*@return �X�e�B�b�N��
		*/
		int axes() const;
	};
	/**
	*@brief	�L�[�{�[�h����
	*/
	class KeyBoard
	{
	public:
		/**
		*enum Key
		*@brief	�L�[�{�[�h�̉����L�[�ݒ�
		*/
		enum Key
		{	
			A, S, D, W, Q, E, Z, X, C, R, F, V, T,
			G, B, Y, H, N, U, J, M, I, K, O, L, P,
			SPACE, ENTER, ESCAPE,
			UP, DOWN, LEFT, RIGHT,
		};
		/**
		*@brief	constructor
		*/
		explicit KeyBoard();
		/**
		*@brief	�������u�Ԃ̔����Ԃ�
		*@param[in] int index ������s���������͔ԍ�
		*@return bool �������u�Ԃł����true
		*/
		bool up(const int index) const;
		/**
		*@brief	�������u�Ԃ̔����Ԃ�
		*@param[in] int index ������s���������͔ԍ�
		*@return bool �������u�Ԃł����true
		*/
		bool down(const int index) const;
		/**
		*@brief	�����Ă��锻���Ԃ�
		*@param[in] int index ������s���������͔ԍ�
		*@return bool �����Ă����true
		*/
		bool on(const int index) const;
		/**
		*@brief	�S�Ă�down���͂̂����P�ł����肪���邩���ׂ�
		*@return 1�ȏ���͂���Ă����true
		*/
		bool EitherDown() const;
		/**
		*@brief	�S�Ă�on���͂̂����P�ł����肪���邩���ׂ�
		*@return 1�ȏ���͂���Ă����true
		*/
		bool EitherOn() const;
		/**
		*@brief	�S�Ă�up���͂̂����P�ł����肪���邩���ׂ�
		*@return 1�ȏ���͂���Ă����true
		*/
		bool EitherUp() const;
		/**
		*@brief	���͏󋵂̍X�V
		*/
		void Update();
		/**
		*@brief	���f������Window��o�^����
		*@param[in] GLFWWindow* w Window�̃|�C���^
		*/
		void SetWindow(GLFWwindow* w);
		//! �L�[�{�[�h�̗L��
		bool isPresent;
		//! button��on���i�[����ϐ�
		std::vector<u_char> button_on;
		//! button��down���i�[����ϐ�
		std::vector<u_char> button_down;
		//!button��up���i�[����ϐ�
		std::vector<u_char> button_up;
	private:
		//! ���̓f�[�^���i�[����ϐ�
		int KeyData[256];
		//! Window�����i�[����
		GLFWwindow* nowWindow;
	};
	/**
	*@brief	�}�E�X����
	*/
	class Mouse
	{
	public:
		/**
		*enum Mouse_
		*@brief	�}�E�X�̓��͐ݒ�
		*/
		enum Mouse_
		{
			//! �E
			LEFT,
			//! ��
			RIGHT,
			//! ���S
			CENTER,
			BUTTON_4,
			BUTTON_5,
			BUTTON_6,
			BUTTON_7,
			BUTTON_8,
		};
		/**
		*@brief	constructor
		*/
		explicit Mouse();
		/**
		*@brief	destructor
		*/
		virtual ~Mouse();
		/**
		*@brief	���͏󋵂̍X�V
		*/
		void Update();
		/**
		*@brief	���f������Window��o�^����
		*@param[in]	GLFWWindow* w Window�̃|�C���^
		*/
		void SetWindow(GLFWwindow *w);
		/**
		*@brief	Window����̃}�E�X�̈ʒu��Ԃ�
		*@return Vec2 �}�E�X�̈ʒu
		*/
		Vec2 GetPos() const;
		/**
		*@brief	�����Ă��锻���Ԃ�
		*@param[in] int index ������s���������͔ԍ�
		*@returnbool �����Ă����true
		*/
		bool on(const int index) const;
		/**
		*@brief	�������u�Ԃ̔����Ԃ�
		*@param[in] int index ������s���������͔ԍ�
		*@returnbool �������u�Ԃł����true
		*/
		bool down(const int index) const;
		/**
		*@brief	�������u�Ԃ̔����Ԃ�
		*@param[in] int index ������s���������͔ԍ�
		*@returnbool �������u�Ԃł����true
		*/
		bool up(const int index) const;
		/**
		*@brief	�S�Ă�down���͂̂����P�ł����肪���邩���ׂ�
		*@return 1�ȏ���͂���Ă����true
		*/
		bool EitherDown() const;
		/**
		*@brief	�Ă�on���͂̂����P�ł����肪���邩���ׂ�
		*@return 1�ȏ���͂���Ă����true
		*/
		bool EitherOn() const;
		/**
		*@brief	�S�Ă�up���͂̂����P�ł����肪���邩���ׂ�
		*@return 1�ȏ���͂���Ă����true
		*/
		bool EitherUp() const;
		/**
		*@brief	�}�E�X�̃z�C�[���l��Ԃ�
		*@return Vec2 �z�C�[���̒l
		*/
		Vec2 GetScroll() const;
		/**
		*@brief	�}�E�X�̓��͏󋵂����Z�b�g����
		*/
		void ResetMouse();
		/**
		*@brief	�}�E�X�̔�����擾����
		*@return CollisionPointer* �}�E�X��Collision
		*/
		CollisionPointer* GetCollision() const;
		//! �}�E�X�̗L��
		bool isPresent;
	private:
		//! MauseButton�f�[�^
		int MouseData[8];
		//! �}�E�X�̍��W��ۑ�����ϐ�
		Vec2 position;
		//! Window�̏����i�[����
		GLFWwindow* nowWindow;
		//! �z�C�[���l
		Vec2 _scroll;
		//! �}�E�X�̔���
		CollisionPointer* collision;
		//! button��on���i�[����ϐ�
		std::vector<u_char> button_on;
		//! button��down���i�[����ϐ�
		std::vector<u_char> button_down;
		//! button��up���i�[����ϐ�
		std::vector<u_char> button_up;
		//! Mouse�ʒu�擾���Ɏg�p����double�^
		double pos_x, pos_y;
		//! �z�C�[���l���̃R�[���o�b�N�œ����l������Ă���
		static Vec2 scroll;
		/**
		*@brief	�}�E�X�̃z�C�[����Ԃ��l������
		*@param[in]	GLFWWindow* w window���
		*@param[in]	double x x���W�̃z�C�[���l
		*@param[in] double y y���W�̃z�C�[���l
		*/
		static void scroll_callback(GLFWwindow* w, double x, double y);
	};
	/**
	*@brief	�Q�[���p�b�h�ƃL�[�{�[�h����ʂ���
	*/
	struct InputData
	{
		//! �Q�[���p�b�h�̃{�^��
		int button;
		//! �L�[�{�[�h�̃L�[
		int key;
	};
	//! �Q�[���p�b�h�z��
	std::vector<GamePad*> pad;
	//! �L�[�{�[�h
	KeyBoard* key;
	//! �}�E�X
	Mouse* mouse;
	//! �Q�[���p�b�h�̑��ݗL��
	bool pad_Connection;
	//�֐�
	/**
	*@brief	���͏�����
	*@param[in]	GLFWWindow* w �w�肷��Window�̃|�C���^
	*/
	void Inputinit(GLFWwindow *w);
	/**
	*@brief	�����Ă��锻���Ԃ�
	*@param[in] int index ������s���������͔ԍ�
	*@param[in]	int padNum ������s���Q�[���p�b�h�̔ԍ�
	*@return bool �����Ă����true
	*/
	bool on(const int index, const int padNum = 0) const;
	/**
	*@brief	�������u�Ԃ̔����Ԃ�
	*@param[in] int index ������s���������͔ԍ�
	*@param[in]	int padNum ������s���Q�[���p�b�h�̔ԍ�
	*@return bool �������u�Ԃł����true
	*/
	bool down(const int index, const int padNum = 0) const;
	/**
	*@brief	�������u�Ԃ̔����Ԃ�
	*@param[in] int index ������s���������͔ԍ�
	*@param[in]	int padNum ������s���Q�[���p�b�h�̔ԍ�
	*@return bool �������u�Ԃł����true
	*/
	bool up(const int index, const int padNum = 0) const;
	/**
	*@brief	�w��l�̃X�e�B�b�N�̌X����Ԃ�
	*@param[in]	int index �X�e�B�b�N�w��
	*@param[in]	int padNum ������s���Q�[���p�b�h�̔ԍ�
	*@return float �X���x(0~1)
	*/
	float axis(const int index, const int padNum = 0) const;
	/**
	*@brief	�S�ẴQ�[���p�b�h�̃X�e�B�b�N�̌X���͈͂𐧌�����
	*@param[in]	float regist �w��l
	*/
	void registAxis(const float regist);
	/**
	*@brief	���͏󋵂̍X�V
	*/
	void Update();
	/**
	*@brief	�S�Ă�down���͂̂����P�ł����肪���邩���ׂ�
	*@return bool 1�ȏ���͂���Ă����true
	*/
	bool EitherDown() const;
	/**
	*@brief	�S�Ă�on���͂̂����P�ł����肪���邩���ׂ�
	*@return bool 1�ȏ���͂���Ă����true
	*/
	bool EitherOn() const;
	/**
	*@brief	�S�Ă�up���͂̂����P�ł����肪���邩���ׂ�
	*@return bool 1�ȏ���͂���Ă����true
	*/
	bool EitherUp() const;
	/**
	*@brief	destructor
	*/
	virtual ~Input();
private:
	/**
	*@brief	���͏�Ԃ����Z�b�g
	*/
	void ResetInputData();
	//! ���̓f�[�^
	int inputData[256];
	/**
	*@brief	�Q�[���p�b�h������
	*@return vetor<GamePad*> ���������Q�[���p�b�h�B
	*/
	std::vector<Input::GamePad*> initGamePad();
	/**
	*@brief	�L�[�{�[�h������
	*return KeyBoard* ���������L�[�{�[�h
	*/
	KeyBoard* initkeyBoard();
	/**
	*@brief	�}�E�X������
	*@return Mouse* ���������}�E�X
	*/
	Mouse* initMouse();
	//! in���̃f�[�^
	InputData inputdata[24];
};