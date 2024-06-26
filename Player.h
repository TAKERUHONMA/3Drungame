#pragma once
#include "Engine/GameObject.h"


class Player :
    public GameObject
{
	int hModel_;
	bool isAlive_;
	int count;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//何かに当たった
	void OnCollision(GameObject* pTarget) override;
	void DeActivateMe() { isAlive_ = false; }
	void ActivateMe() { isAlive_ = true; }
};

