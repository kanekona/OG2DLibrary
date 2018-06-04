#pragma once
#include "OGSystem\_OGsystem.h"
//�ȈՈ����p
namespace In
{
	enum
	{
		//�����R���g���[���̓��͐ݒ�
		BUTTON_A,		//1
		BUTTON_B,		//2
		BUTTON_X,		//3
		BUTTON_Y,		//4
		BUTTON_L1,		//5
		BUTTON_R1,		//6
		BUTTON_BACK,	//7
		BUTTON_START,	//8
		BUTTON_L3,		//9
		BUTTON_R3,		//10
		BUTTON_U,		//11
		BUTTON_R,		//12
		BUTTON_D,		//13
		BUTTON_L,		//14
	};
	enum AXIS
	{
		AXIS_LEFT_X,		//���X�e�B�b�NX�l
		AXIS_LEFT_Y,		//���X�e�B�b�NY�l
		AXIS_RIGHT_X,		//�E�X�e�B�b�NX�l
		AXIS_RIGHT_Y,		//�E�X�e�B�b�NY�l
		AXIS_BUTTON_NUM,
	};
	enum
	{
		LSTICK_LEFT,
		LSTICK_RIGHT,
		LSTICK_UP,
		LSTICK_DOWN,
		RSTICK_LEFT,
		RSTICK_RIGHT,
		RSTICK_UP,
		RSTICK_DOWN,
		STICK_NUM,
	};
	enum
	{
		//���z����
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
	};
	enum
	{
		//�L�[�{�[�h�̉����L�[�ݒ�
		A, S, D, W, Q, E, Z, X, C, R, F, V, T,
		G, B, Y, H, N, U, J, M, I, K, O, L, P,
		SPACE, ENTER, ESCAPE,
		UP, DOWN, LEFT, RIGHT,
	};
}
//�}�E�X�p�ȈՈ���
namespace Mouse
{
	enum
	{
		LEFT,
		RIGTH,
		CENTER,
		BUTTON_4,
		BUTTON_5,
		BUTTON_6,
		BUTTON_7,
		BUTTON_8,
	};
}

class Input
{
public:
	//enum
	//���͗p���z����
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
	};
	//class
	//�Q�[���p�b�h
	class GamePad
	{
	public:
		enum Pad
		{
			//�����R���g���[���̓��͐ݒ�
			BUTTON_A,		//1
			BUTTON_B,		//2
			BUTTON_X,		//3
			BUTTON_Y,		//4
			BUTTON_L1,		//5
			BUTTON_R1,		//6
			BUTTON_BACK,	//7
			BUTTON_START,	//8
			BUTTON_L3,		//9
			BUTTON_R3,		//10
			BUTTON_U,		//11
			BUTTON_R,		//12
			BUTTON_D,		//13
			BUTTON_L,		//14
		};
		enum AXIS {
			AXIS_LEFT_X,		//���X�e�B�b�NX�l
			AXIS_LEFT_Y,		//���X�e�B�b�NY�l
			AXIS_RIGHT_X,		//�E�X�e�B�b�NX�l
			AXIS_RIGHT_Y,		//�E�X�e�B�b�NY�l
			AXIS_BUTTON_NUM,
		};
		enum AXISBUTTON
		{
			LSTICK_LEFT,
			LSTICK_RIGHT,
			LSTICK_UP,
			LSTICK_DOWN,
			RSTICK_LEFT,
			RSTICK_RIGHT,
			RSTICK_UP,
			RSTICK_DOWN,
			STICK_NUM,
		};
		explicit GamePad(const int id);		//�R���X�g���N�^
		bool on(const int index) const;		//index��on��bool��Ԃ�
		bool down(const int index) const;	//index��down��bool��Ԃ�
		bool up(const int index) const;		//index��up��bool��Ԃ�
		float axis(const int index) const;	//index�̃X�e�B�b�N�̒l��Ԃ�(0~1)
		bool axis_on(const int index) const;
		bool axis_down(const int index) const;
		bool axis_up(const int index) const;
		bool isPresent() const;				//�Q�[���p�b�h�̗L��
		void upDate();						//���͏󋵂̍X�V
		void Initialize();					//����������
		void Reset();						//���͏󋵂̃��Z�b�g
		bool registAxisButton(				//�X�e�B�b�N�͈̔͊O����
			const float axis_threshold_);
	private:
		
		int id_;							//�Q�[���p�b�h�����ɑΉ������邽�߂ɂP�P��id��U�蕪����
		int button_num;						//�Q�[���p�b�h�̃{�^����
		int axis_num;						//�Q�[���p�b�h�̃X�e�B�b�N��
		int GPadData[14];					//���̓f�[�^���i�[����ϐ�
		std::vector<float> axis_value;		//�X�e�B�b�N�����i�[����ϐ�
		float axis_threshold;				//�X�e�B�b�N�̒��_�lz
		std::vector<u_char> button_on;		//button��on���i�[����ϐ�
		std::vector<u_char> button_down;	//button��down���i�[����ϐ�
		std::vector<u_char> button_up;		//button��up���i�[����ϐ�
		std::vector<u_char> axis_button_on;	//axis��on���i�[����ϐ�
		std::vector<u_char> axis_button_down;//axis��down���i�[����ϐ�
		std::vector<u_char> axis_button_up;	//axis��up���i�[����ϐ�
		int buttons() const;				//�{�^������Ԃ��֐�
		int axes() const;					//�X�e�B�b�N����Ԃ��֐�
	};
	//�L�[�{�[�h
	class KeyBoard
	{
	public:
		enum Key
		{
			//�L�[�{�[�h�̉����L�[�ݒ�
			A, S, D, W, Q, E, Z, X, C, R, F, V, T,
			G, B, Y, H, N, U, J, M, I, K, O, L, P,
			SPACE, ENTER, ESCAPE,
			UP, DOWN, LEFT, RIGHT,
		};
		explicit KeyBoard();				//�R���X�g���N�^
		bool up(const int index) const;		//index��up��bool��Ԃ�
		bool down(const int index) const;	//index��down��bool��Ԃ�
		bool on(const int index) const;		//index��on��bool��Ԃ�
		void upDate();						//���͏󋵂̍X�V
		void SetWindow(GLFWwindow* w);		//���f������Window��o�^����
		bool isPresent;						//�L�[�{�[�h�̗L��(�����炭�K�v�Ȃ����p�b�h�ɂ���̂ňꉞ������ł��������Ă���)
		std::vector<u_char> button_on;		//button��on���i�[����ϐ�
		std::vector<u_char> button_down;	//button��down���i�[����ϐ�
		std::vector<u_char> button_up;		//button��up���i�[����ϐ�
	private:
		int KeyData[256];					//���̓f�[�^���i�[����ϐ�
		GLFWwindow* nowWindow;				//Window�����i�[����
	};
	//�}�E�X
	class Mouse
	{
	public:
		enum Mouse_
		{
			LEFT,
			RIGHT,
			CENTER,
			BUTTON_4,
			BUTTON_5,
			BUTTON_6,
			BUTTON_7,
			BUTTON_8,
		};
		
		explicit Mouse();					//�R���X�g���N�^
		void upDate();						//���͏󋵂̍X�V
		void SetWindow(GLFWwindow *w);		//���f������Window��o�^����
		Vec2 GetPos() const;				//Window��0,0���W���猩���ʒu��Ԃ�
		bool on(const int index) const;		//index��on��bool��Ԃ�
		bool down(const int index) const;	//index��down��bool��Ԃ�
		bool up(const int index) const;		//index��up��bool��Ԃ�
		bool isPresent;						//�}�E�X�̗L���̏��
		std::vector<u_char> button_on;		//button��on���i�[����ϐ�
		std::vector<u_char> button_down;	//button��down���i�[����ϐ�
		std::vector<u_char> button_up;		//button��up���i�[����ϐ�
	private:
		int MouseData[8];					//MauseButton�f�[�^
		Vec2 position;						//�}�E�X�̍��W��ۑ�����ϐ�
		GLFWwindow* nowWindow;				//Window�̏����i�[����
	};
	//�Q�[���p�b�h�ƃL�[�{�[�h����ʂ���
	struct InputData
	{
		int button;		//�Q�[���p�b�h�̃{�^��
		int key;		//�L�[�{�[�h�̃L�[
	};
	//class�錾
	//�Q�[���p�b�h�z��
	std::vector<GamePad> pad;
	//�L�[�{�[�h
	KeyBoard key;
	//�}�E�X
	Mouse mouse;
	//�ϐ�
	bool Pad_Connection;				//�Q�[���p�b�h�̑��ݗL��
	//�֐�
	void Inputinit(GLFWwindow *w);		//���͏�����
	bool on(const int in_, const int padNum = 0) const;		//�����Ă�Ƃ�
	bool down(const int in_, const int padNum = 0) const;	//�������Ƃ�
	bool up(const int in_, const int padNum = 0) const;		//�������Ƃ�
	float axis(const int in_, const int padNum = 0) const;
	void registAxis(const float regist);
	void upDate();						//���͏��X�V
private:
	void ResetInputData();				//���͏�Ԃ����Z�b�g
	int inputData[256];					//���̓f�[�^
	std::vector<Input::GamePad> initGamePad();//�Q�[���p�b�h������
	KeyBoard initkeyBoard();			//�L�[�{�[�h������
	Mouse initMouse();					//�}�E�X������
	InputData inputdata[22];			//in���̃f�[�^
};
