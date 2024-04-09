#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/input.h"

TitleScene::TitleScene(GameObject* parent)
{
}

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	if (Input::IsKeyUp(DIK_SPACE))
	{
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
