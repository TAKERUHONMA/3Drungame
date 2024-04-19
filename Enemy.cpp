#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Bullet.h"
#include "Medium.h"
#include "Engine/Input.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1),isAlive_(false),counter(0),ENEMY_NUM(0)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

void Enemy::Update()
{
	if (counter == 0)
	{
		Bullet* e = Instantiate<Bullet>(this->GetParent());
		Bullet* e2 = Instantiate<Bullet>(this->GetParent());
		Medium* m = Instantiate<Medium>(this->GetParent());
		e->SetPosition(this->transform_.position_ = { -0.5,0,25 }); //“G‚ÌˆÊ’u
		e2->SetPosition(this->transform_.position_ = { 0.5,0,25 }); //“G‚ÌˆÊ’u
		m->SetPosition(this->transform_.position_ = { 1,0.5,25 });
		counter = 250;
	}
	else if (counter == 200)
	{
		Bullet* e2 = Instantiate<Bullet>(this->GetParent());
		Bullet* e3 = Instantiate<Bullet>(this->GetParent());
		Medium* m = Instantiate<Medium>(this->GetParent());
		e2->SetPosition(this->transform_.position_ = { 0.5,0,25 }); //“G‚ÌˆÊ’u
		e3->SetPosition(this->transform_.position_ = { 1.5,0,25 }); //“G‚ÌˆÊ’u
		m->SetPosition(this->transform_.position_ = { -1,0.5,25 });
		counter = 450;
	}
	else if (counter == 400)
	{
		Bullet* e = Instantiate<Bullet>(this->GetParent());
		Bullet* e3 = Instantiate<Bullet>(this->GetParent());
		Medium* m = Instantiate<Medium>(this->GetParent());
		e3->SetPosition(this->transform_.position_ = { 1.5,0,25 }); //“G‚ÌˆÊ’u
		e->SetPosition(this->transform_.position_ = { -0.5,0,25 }); //“G‚ÌˆÊ’u
		m->SetPosition(this->transform_.position_ = { 0,0.5,25 });
		counter = 50;
	}
	else
	{
		counter -= 1;
	}
}


void Enemy::Draw()
{

		//Model::SetTransform(hModel_, transform_);
		//Model::Draw(hModel_);

}

void Enemy::Release()
{
}
