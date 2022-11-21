#include "PlayScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Score.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Item.h"

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

	//残機の表示
	std::string fileName = "VICVIPER.png";
	for (int i = 0; i < 3; i++)
	{
		hPictCon_[i] = Image::Load(fileName);
	}

	//残機の初期位置
	transcon_.position_.x = -0.7f;
	transcon_.position_.y = 0.92f;
	//残機の表示の大きさ
	transcon_.scale_.x = 0.15;
	transcon_.scale_.y = 0.15;
	
	//プレイヤーの表示
	Instantiate<Score>(this);
	Instantiate<Player>(this);
	Instantiate<Item>(this);

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

	if (Input::IsKeyDown(DIK_ESCAPE))
	{
		PostQuitMessage(0);
	}

	//一定時間で敵を出現させる
	time++;
	if (time >= 20 && count < 4)
	{
		Instantiate<Enemy>(this);
		Instantiate<Enemy2>(this);
		time = 0;
		count++;
	}
	if (time >= 210 && count  >= 4)
	{
		time = 0;
		count = 0;
	}


	//もしプレイヤーがなければ
	if (FindObject("Player") == NULL)
	{
		//残機の表示を消す
		hPictCon_[con] = NULL;

		//残機があるなら表示
		if (life > 0)
		{
			Instantiate<Player>(this);
			life--;
			con++;
		}
		//残機がないなら結果画面
		else
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_RESULT);
		}
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

	//残機の表示
	for (int i = 1; i < 3; i++)
	{
		transcon_.position_.x = -0.065f * i - 0.6f;
		Image::SetTransform(hPictCon_[i - 1], transcon_);
		Image::Draw(hPictCon_[i - 1]);
	}
	
}

//開放
void PlayScene::Release()
{
}
