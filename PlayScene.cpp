#include "PlayScene.h"
#include "Engine/Image.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), hPict_(-1)
{
}

//初期化
void PlayScene::Initialize()
{
	hPict_ = Image::Load("Shinwa.jpg");
	assert(hPict_ >= 0);
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void PlayScene::Release()
{
}
