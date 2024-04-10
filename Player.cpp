#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Collider.h"
#include "Enemy.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,-1.0f };

	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 0.5f);
	AddCollider(collision);
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.position_.x = -1.5f;
	}
	else if (Input::IsKey(DIK_RIGHT))
	{
		transform_.position_.x = 1.5f;
	}
	else
		transform_.position_.x = 0;
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy")
	{
		this->KillMe();
		pTarget->KillMe();
	}
}
