#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Stage.h"
#include "Medium.h"
#include "Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{

}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
