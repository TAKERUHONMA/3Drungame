#include "Medium.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

Medium::Medium(GameObject* parent)
	:GameObject(parent, "Medium"),hModel_(-1),z(0),count(0),counter(0),isAlive_(true)
{
}

void Medium::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	SphereCollider* collision = new SphereCollider({ 0.5,0,0 }, 0.4f);
	AddCollider(collision);
	z = 0.5f;
}

void Medium::Update()
{
	if (isAlive_ == false)
	{
		count += 1;
	}
	else
	{
		counter = count;
	}

	transform_.position_.z -= z;

	if (counter == 5)
	{
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_GAMECLEAR);
	}
}

void Medium::Draw()
{
	if (isAlive_)
	{
		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
	}
}

void Medium::Release()
{
}

void Medium::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Player")
	{
		this->DeActivateMe();
		this->KillMe();
	}
}


