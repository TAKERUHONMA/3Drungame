#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/Input.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1),isAlive_(false)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,25 };
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.5f);
	AddCollider(collision);

}

void Enemy::Update()
{	
	if (isAlive_ == false)
	{
			transform_.position_.z -= 0.1;
			if (transform_.position_.z <= -5.0f)
			{
				KillMe();
			}
	}		
}

void Enemy::Draw()
{
		for (int ENEMY_NUM = 0; ENEMY_NUM < ENEMY_MAX; ENEMY_NUM++)
		{
			Model::SetTransform(hModel_, transform_);
			Model::Draw(hModel_);
			transform_.position_.x = ENEMY_NUM * 1.5 - 1.5;
		}
}

void Enemy::Release()
{
}
