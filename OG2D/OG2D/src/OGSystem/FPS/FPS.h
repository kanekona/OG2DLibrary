#pragma once
#include "OGSystem\_OGsystem.h"

class FPS {
public:
	FPS();							//�R���X�g���N�^
	~FPS();							//�f�X�g���N�^
	void Update();					//�X�V����
private:
	float lastTime;					//�O�t���[���^�C��
	int count;						//�J�E���g��
	GLfloat fps;					//fps�l
};
