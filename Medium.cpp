#include "Medium.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Medium::Medium(GameObject* parent)
	:GameObject(parent, "Medium"),hModel_(-1),z(0.3f),count(0),isAlive_(false)
{
}

void Medium::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	SphereCollider* collision = new SphereCollider({ 0.5,0,0 }, 0.4f);
	AddCollider(collision);

}

void Medium::Update()
{
	transform_.position_.z -= z;
	
	if (transform_.position_.z <= -7.0f)
	{
		KillMe();
	}
}

void Medium::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Medium::Release()
{
}

void Medium::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Player")
	{
			this->KillMe();
	}
}
