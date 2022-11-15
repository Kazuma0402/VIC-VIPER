#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"

//コンストラクタ
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"), hPict_(-1)
{
}

//初期化
void ResultScene::Initialize()
{
	hPict_ = Image::Load("Result.png");
	assert(hPict_ >= 0);
}

//更新
void ResultScene::Update()
{
}

//描画
void ResultScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void ResultScene::Release()
{
}
