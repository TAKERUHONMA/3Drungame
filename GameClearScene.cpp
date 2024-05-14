#include "GameClearScene.h"
#include "Engine/Model.h"

GameClearScene::GameClearScene(GameObject* parent)
	:GameObject(parent, "GameClearScene"),hModel_(-1)
{
}

void GameClearScene::Initialize()
{
	hModel_ = Model::Load("");
	assert(hModel_ >= 0);
}

void GameClearScene::Update()
{
}

void GameClearScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void GameClearScene::Release()
{
}
