#include "Stage.h"
#include "Engine/Model.h"

Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")
{
    stageWidth_ = 3;
    stageHeight_ = 40;
}

void Stage::Initialize()
{
    hFloor_ = Model::Load("floor.fbx");
    //hBlock_ = Model::Load("Block.fbx");
    assert(hFloor_ >= 0);
    //assert(hBlock_ >= 0);
    transform_.position_ = { 0,0,-2};
}

void Stage::Update()
{
}

void Stage::Draw()
{
    for (int z = 0; z < stageHeight_; z++)
    {
        for (int x = 0; x < stageWidth_; x++)
        {
            Model::SetTransform(hFloor_, transform_);
            Model::Draw(hFloor_);
            transform_.position_.x = x - 0.5;
        }
        transform_.position_.z = z -10;
    }
}

void Stage::Release()
{
}
