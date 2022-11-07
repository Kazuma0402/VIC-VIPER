#include "PlayScene.h"
#include "Engine/Image.h"
#include "Player.h"
#include "Engine/Input.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), hPict_(-1)
{
}

//初期化
void PlayScene::Initialize()
{

	hPict_ = Image::Load("Assets/Shinwa.jpg");
	assert(hPict_ >= 0);

	Instantiate<Player>(this);
}

//更新
void PlayScene::Update()
{
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.01;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.01;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.01;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.01;
	}
}

//描画
void PlayScene::Draw()
{
	/*Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);*/
}

//開放
void PlayScene::Release()
{
}
