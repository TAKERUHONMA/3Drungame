#pragma once
#include "Engine/GameObject.h"

class Bullet :
    public GameObject
{
	int hModel_;
	int count_;
	int counter_;
	double speed_;
	bool isAlive_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Bullet(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�����ɓ�������
	void SetSpeed(double _speed) { speed_ = _speed; }
	void DeActivateMe() { isAlive_ = false; }
	void ActivateMe() { isAlive_ = true; }
};

