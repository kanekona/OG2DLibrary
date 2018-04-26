#pragma once
#include "OGSystem\_OGsystem.h"
#include <functional>
class FPS {
public:
	FPS();							//�R���X�g���N�^
	~FPS();							//�f�X�g���N�^
	void Initialize();				//������	
	void Update();					//�X�V����
	void SetData(void data_());		//�֐��o�^
	void DeleteData();				//�f�[�^�̍폜
	typedef std::shared_ptr<FPS> SP;//�X�}�[�g�|�C���^�̐���
	static SP Create();				//�X�}�[�g�|�C���^��Ԃ�
private:
	float lastTime;					//�O�t���[���^�C��
	int count;						//�J�E���g��
	GLfloat fps;					//fps�l
	std::vector<std::function<void()>> data;//�֐��f�[�^
	float Setfps;					//fps��ݒ�
	float setlast;					//�Ofps�l
};
