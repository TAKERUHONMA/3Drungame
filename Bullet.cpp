#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1), count_(0), speed_(0.3f),isAlive_(true)
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Wall.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.3f);
	AddCollider(collision);
}

void Bullet::Update()
{
	transform_.position_.z -= speed_;
	
	if (transform_.position_.z <= -6.0f)
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

void Bullet::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Player")
	{
		pTarget->KillMe();
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_GAMEOVER);
	}
}




