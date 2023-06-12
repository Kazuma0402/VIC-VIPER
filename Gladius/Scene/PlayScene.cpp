#include "PlayScene.h"
#include "../Display/Stage.h"
#include "../Object/Player.h"
#include "../Object/Enemy.h"
#include "../Object/Enemy2.h"
#include "../Object/Boss.h"
#include "../Display/Score.h"
#include "../Ability/Ability.h"
#include "../Display/Life.h"
#include "../Object/Item.h"
#include "../Ability/Option.h"

#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/SceneManager.h"

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
	Instantiate<Option>(this);
	Instantiate<Enemy>(this);
	Instantiate<Enemy2>(this);
	Instantiate<Boss>(this);
	Instantiate<Stage>(this);
	Instantiate<Score>(this);
	Instantiate<Ability>(this);
	Instantiate<Life>(this);

	time = 0;
	time2 = 0;
	timeCount = 0;
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

	time2++;
	if (time2 >= 60)
	{
		timeCount++;
		time2 = 0;
	}

	//もし敵がいなければ
	if (FindObject("Enemy") == NULL && timeCount <= 80)
	{
		Instantiate<Enemy>(this);
	}
	if (FindObject("Enemy2") == NULL && timeCount <= 80)
	{
		time++;
		
		if (time >= 60)
		{
			Instantiate<Enemy2>(this);
			time = 0;
		}	
	}
	if (FindObject("Boss") == NULL)
	{
		//ゲーム結果画面への遷移
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}

	//もしプレイヤーがなければ
	if (FindObject("Player") == NULL)
	{
		//残機判定に行く
		Life* pLife = (Life*)FindObject("Life");
		pLife->Stock();

		if (FindObject("Option") != NULL)
		{
			//OptionをKill
			Option* pOption = (Option*)FindObject("Option");
			pOption->KillOption();
		}	
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

//Optionの表示
void PlayScene::AppearanceOption()
{
	Instantiate<Option>(this);
}

//アイテムの表示
void PlayScene::AppearanceItem()
{
	Instantiate<Item>(this);
}