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
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Medium(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void OnCollision(GameObject* pTarget);
	void DeActivateMe() { isAlive_ = false; }
	void ActivateMe() { isAlive_ = true; }
};

