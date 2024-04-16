#pragma once
#include "Engine/GameObject.h"
#include <vector>

using std::vector;

enum STAGE_OBJ {
	FLOOR,
	WALL,
};

class Stage :
    public GameObject
{
	int hFloor_;
	int hBlock_;
	int stageWidth_, stageHeight_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
