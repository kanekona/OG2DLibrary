///�t���[�����[�g���v�Z,����(������)����class
///����GameEngine���g�p���Ă���ꍇ��DEBUG���̂ݎ����Ő��������
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
