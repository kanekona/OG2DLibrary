#pragma once
#include "OGSystem\_OGsystem.h"
#include <functional>
class FPS {
public:
	FPS();							//�R���X�g���N�^
	~FPS();							//�f�X�g���N�^
	void Update();					//�X�V����
	typedef std::shared_ptr<FPS> SP;//�X�}�[�g�|�C���^�̐���
	static SP Create();				//�X�}�[�g�|�C���^��Ԃ�
private:
	float lastTime;					//�O�t���[���^�C��
	int count;						//�J�E���g��
	GLfloat fps;					//fps�l
};
