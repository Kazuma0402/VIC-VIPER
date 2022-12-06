#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Ability.h"
#include "Life.h"
#include "Item.h"

#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{  
	//背景
	//画像のロード
	hPict_[0] = Image::Load("BackGround.png");
	assert(hPict_[0] >= 0);
	hPict_[1] = Image::Load("BackGround2.png");
	assert(hPict_[1] >= 0);

	//二枚目の背景の初期位置
	trans_.position_.x = 1.95;

	
	//表示
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	Instantiate<Stage>(this);
	Instantiate<Score>(this);
	Instantiate<Ability>(this);
	Instantiate<Life>(this);

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
	//もし敵がいなければ
	if (FindObject("Enemy") == NULL)
	{
		Instantiate<Enemy>(this);
		count++;

		if (count >= 5)
		{
			Instantiate<Item>(this);
			count = 0;
		}
	}

	//もしプレイヤーがなければ
	if (FindObject("Player") == NULL)
	{
		//残機判定に行く
		Life* pLife = (Life*)FindObject("Life");
		pLife->Stock();
	}

	//ESCキーで強制終了
	if (Input::IsKeyDown(DIK_ESCAPE))
	{
		PostQuitMessage(0);
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

//プレイヤーの表示
void PlayScene::AppearancePlayer()
{
	Instantiate<Player>(this);
}

//アイテムの表示
void PlayScene::AppearanceItem()
{
	Instantiate<Item>(this);
}