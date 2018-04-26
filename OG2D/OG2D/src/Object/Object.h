#pragma once
//______________________________//
//|�Q�[���I�u�W�F�N�g            |//
//|�����F2018/03/20���q��       |//
//|____________________________|//
#include "OGSystem\OGsystem.h"
enum Objform
{
	Non,											//��
	Ball,											//�~
	Cube,											//��`
};
class GameObject
{
public:
	Objform objform;								//�I�u�W�F�N�g�̏��
	Vec2 position;									//�ʒu
	Vec2 Scale;										//�T�C�Y
	float angle;									//��]�x
	CollisionBox collisionCube;						//��`�����蔻��
	CollisionCircle collisionBall;					//�~�����蔻��
	bool Gravity;									//�d�̗͂L��
	float mass;										//����
	bool hit(GameObject o);							//GameObject���m�̓����蔻��
	GameObject();									//�R���X�g���N�^	
	GameObject(										//�R���X�g���N�^
		Objform form, 
		Vec2 _posi, 
		Vec2 _Sca, 
		float _ang
	);
	~GameObject();									//�f�X�g���N�^
	void CreateObject(								//GameObject�̏���o�^
		Objform form,
		Vec2 _posi,
		Vec2 _Sca,
		float _ang
	);
	std::string objectTag;							//�^�O��
	void LineDraw();								//�����蔻������C���������Ċm�F�p
private:
};