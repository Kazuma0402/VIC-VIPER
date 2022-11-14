#include "PlayScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Player.h"
#include "Enemy.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{  
	hPict_[0] = Image::Load("BackGround.png");
	assert(hPict_[0] >= 0);
	hPict_[1] = Image::Load("BackGround2.png");
	assert(hPict_[1] >= 0);

	trans_.position_.x = 1.95;

	Instantiate<Player>(this);

}

//更新
void PlayScene::Update()
{	
	//背景のスクロール
	transform_.position_.x -= 0.005f;
	trans_.position_.x -= 0.005f;

	//一枚目の描画が終わったら二枚目の後ろに戻る
	if (transform_.position_.x < -1.95)
	{
		transform_.position_.x = 1.95;
		Image::SetTransform(hPict_[0], transform_);
		Image::Draw(hPict_[0]);
	}
	//二枚目の描画が終わったら一枚目の後ろに戻る
	if (trans_.position_.x < -1.95)
	{
		trans_.position_.x = 1.95;
		Image::SetTransform(hPict_[1], trans_);
		Image::Draw(hPict_[1]);
	}

	//ESCで終了
	if (Input::IsKeyDown(DIK_ESCAPE))
	{
		PostQuitMessage(0);
	}

	time++;
	if (time >= 15 && count < 4)
	{
		Instantiate<Enemy>(this);
		time = 0;
		count++;
	}
}

//描画
void PlayScene::Draw()
{
	//一枚目
	Image::SetTransform(hPict_[0], transform_);
	Image::Draw(hPict_[0]);
	//二枚目
	Image::SetTransform(hPict_[1], trans_);
	Image::Draw(hPict_[1]);
}

//開放
void PlayScene::Release()
{
}
