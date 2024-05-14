#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Collider.h"
#include "Enemy.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"),hModel_(-1),isAlive_(true),count(0)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Man.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };

	SphereCollider* collision = new SphereCollider({ 0.5, 0, 0 }, 0.3f);
	AddCollider(collision);
}

void Player::Update()
{
	if (transform_.position_.x <= 1 )
	{
		if (Input::IsKey(DIK_RIGHT))
		{
			transform_.position_.x += 0.1f;
		}
	}
	 if (transform_.position_.x >= -1)
	{
		if (Input::IsKey(DIK_LEFT))
		{
			transform_.position_.x -= 0.1f;
		}
	}

}

void Player::Draw()
{
	if (isAlive_)
	{
		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
	}
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		count += 1;
		if (count == 5)
		{
			this->KillMe();
			this->DeActivateMe();
			SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
			pSM->ChangeScene(SCENE_ID_GAMEOVER);
		}
	}
}
