#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,40.0f };
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.5f);
	AddCollider(collision);

}

void Enemy::Update()
{
	transform_.position_.z -= 0.1;
	if (transform_.position_.z <= -2.0f)
	{
		KillMe();
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
