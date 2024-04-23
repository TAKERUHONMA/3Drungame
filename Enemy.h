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
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

