#pragma once
#include "Engine/GameObject.h"
#include "Bullet.h"


class Medium :
    public GameObject
{
	int hModel_;
	int count;
	int counter;
	double z;
	bool isAlive_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Medium(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void OnCollision(GameObject* pTarget);
	void DeActivateMe() { isAlive_ = false; }
	void ActivateMe() { isAlive_ = true; }
};

