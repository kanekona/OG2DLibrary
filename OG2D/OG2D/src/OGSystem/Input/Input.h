#pragma once
#include "OGSystem\_OGsystem.h"
class Input
{
public:
	//enum
	//���͗p
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
		explicit GamePad(const int id);
		bool on(const int index);
		bool down(const int index);
		bool up(const int index);
		float axis(const int index);
		void upDate();
		void Initialize();
		void Reset();
		bool isPresent() const;
	private:
		bool registAxisButton(const int x_index, const int y_index, const float axis_threshold_);
		int id_;
		int button_num;
		int axis_num;
		int GPadData[14];
		std::vector<float> axis_value;
		bool axis_button;
		float axis_threshold;
		int axis_x_index;
		int axis_y_index;
		std::vector<u_char> button_on;
		std::vector<u_char> button_down;
		std::vector<u_char> button_up;
		std::vector<u_char> axis_button_on;
		std::vector<u_char> axis_button_down;
		std::vector<u_char> axis_button_up;
		int buttons() const;
		int axes() const;
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
		KeyBoard();
		bool up(const int index);
		bool down(const int index);
		bool on(const int index);
		void upDate();
		void SetWindow(GLFWwindow* w);
		GLFWwindow* nowWindow;
		bool isPresent;
		std::vector<u_char> button_on;
		std::vector<u_char> button_down;
		std::vector<u_char> button_up;
	private:
		int KeyData[256];
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
		Vec2 position;
		GLFWwindow* nowWindow;
		Mouse();
		~Mouse();
		void upDate();
		void SetWindow(GLFWwindow *w);
		Vec2 GetPos() const;
		bool on(const int index);
		bool down(const int index);
		bool up(const int index);
		bool isPresent;
		std::vector<u_char> button_on;
		std::vector<u_char> button_down;
		std::vector<u_char> button_up;
	private:
		int MouseData[256];
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
	bool on(int in_, int padNum = 0);	//�����Ă�Ƃ�
	bool down(int in_, int padNum = 0);	//�������Ƃ�
	bool up(int in_, int padNum = 0);	//�������Ƃ�
	void upDate();						//���͏��X�V
private:
	void ResetInputData();				//���͏�Ԃ����Z�b�g
	int inputData[256];					//���̓f�[�^
	std::vector<Input::GamePad> initGamePad();//�Q�[���p�b�h������
	KeyBoard initkeyBoard();			//�L�[�{�[�h������
	Mouse initMouse();					//�}�E�X������
	InputData inputdata[14];			//in���̃f�[�^
};
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
	enum
	{
		AXIS_LEFT_X,		//���X�e�B�b�NX�l
		AXIS_LEFT_Y,		//���X�e�B�b�NY�l
		AXIS_RIGHT_X,		//�E�X�e�B�b�NX�l
		AXIS_RIGHT_Y,		//�E�X�e�B�b�NY�l
		AXIS_BUTTON_NUM,
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