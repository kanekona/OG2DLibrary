#pragma once
//_____________________________
//|�Q�[���I�u�W�F�N�g            
//|�����F2018/03/20   
//|____________________________
#include "OGSystem\OGlib.h"
#include "OGSystem\Collision\Collision.h"
enum Objform
{
	Non,											//��
	Ball,											//�~
	Cube,											//��`
};
class GameObject
{
	bool isCheck;
public:
	Objform objform;								//�I�u�W�F�N�g�̏��
	Vec2 position;									//�ʒu
	Vec2 Scale;										//�T�C�Y
	Vec2 Radius;									//���a
	float angle;									//��]�x
	CollisionBox collisionCube;						//��`�����蔻��
	CollisionCircle collisionBall;					//�~�����蔻��
	bool Gravity;									//�d�̗͂L��
	float mass;										//����
	bool hit(GameObject& o);						//GameObject���m�̓����蔻��
	bool CubeHit(GameObject& o);					//�ȈՔŉ�]�Ȃ�����
	GameObject();									//�R���X�g���N�^	
	GameObject(										//�R���X�g���N�^
		const Objform& form, 
		const Vec2& _posi, 
		const Vec2& _Sca, 
		float _ang = 0.0f
	);
	~GameObject();									//�f�X�g���N�^
	void CreateObject(								//GameObject�̏���o�^
		const Objform& form,
		const Vec2& _posi,
		const Vec2& _Sca,
		const float _ang = 0.0f
	);
	std::string objectTag;							//�^�O��
	void LineDraw();								//�����蔻������C���������Ċm�F�p
	void CheckON();									//�����蔻����N������
	bool IsObjectDistanceCheck(const Vec2& pos, const Vec2& size);	//�����蔻����s���͈͓����ǂ�����Ԃ��܂��B
	void LineDistanceDraw();
private:
};