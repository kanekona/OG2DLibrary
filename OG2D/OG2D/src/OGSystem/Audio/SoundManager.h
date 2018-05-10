#pragma once
#include "Sound.h"

class SoundManager
{
public:
	explicit SoundManager();				//�R���X�g���N�^
	~SoundManager();						//�f�X�g���N�^
	void SetMaxVolume(const float value_);	//�ő剹�ʂ�o�^����
	float GetMaxVolume() const;				//�ő剹�ʂ�Ԃ�
	void SetVolume(const Sound* s,			//�I�����ꂽSound�̉��ʂ��ő剹�ʂɓK�������l�ɕς���
					const float value_);
	void SetSound(Sound* s);				//Sound�f�[�^��o�^����
	bool DeleteSound(const Sound* s);	//Sound�f�[�^��j������
	void AllDelete();						//Sound�f�[�^��S�폜����
	void Application();						//�ő剹�ʂ�o�^����Ă���Sound���ׂĂɓK��������
private:
	float MaxVolume;						//�ő剹�ʂ��i�[����
	std::vector<Sound*> sounddata;			//�K��������Sound�̃f�[�^���i�[����
};