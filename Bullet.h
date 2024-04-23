#pragma once
#include "Engine/GameObject.h"
class Bullet :
    public GameObject
{
	int hModel_;
	int hModel2_;
	double count_;
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
	void OnCollision(GameObject* pTarget) override;
	void DeActivateMe() { isAlive_ = false; }
	void ActivateMe() { isAlive_ = true; }
};

