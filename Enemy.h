#pragma once
#include "Engine/GameObject.h"

const int ENEMY_MAX{ 3 };
const int RUNDOM[] = { 0,200,400 };


class Bullet;
class Medium;
class Enemy :
    public GameObject
{
	int hModel_;
	double counter;
	bool isAlive_;
	int ENEMY_NUM;
	int i;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Enemy(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

