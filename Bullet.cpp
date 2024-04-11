#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"),hModel_(-1)
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.5f);
	AddCollider(collision);
}

void Bullet::Update()
{
	transform_.position_.z -= 0.1;
	if (transform_.position_.z <= -5.0f)
	{
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}


