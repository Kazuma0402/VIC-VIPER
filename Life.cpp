#include "Life.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "PlayScene.h"

//コンストラクタ
Life::Life(GameObject* parent)
	:GameObject(parent, "Life")
{
}

//デストラクタ
Life::~Life()
{
}

//初期化
void Life::Initialize()
{
	//残機の表示
	std::string fileName = "VICVIPER.png";
	for (int i = 0; i < 3; i++)
	{
		hPictCon_[i] = Image::Load(fileName);
	}

	//残機の初期位置
	transform_.position_.x = -0.7f;
	transform_.position_.y = 0.92f;

	//残機の表示の大きさ
	transform_.scale_.x = 0.15;
	transform_.scale_.y = 0.15;

}

//更新
void Life::Update()
{
}

//描画
void Life::Draw()
{
	//残機の表示
	for (int i = 1; i < 3; i++)
	{
		transform_.position_.x = 0.07f * i - 0.7f;
		Image::SetTransform(hPictCon_[i - 1], transform_);
		Image::Draw(hPictCon_[i - 1]);
	}
}

//開放
void Life::Release()
{
}

//残機判定
void Life::Stock()
{
	//残機の表示を消す
	hPictCon_[con] = NULL;

	//残機があるなら表示
	if (life > 0)
	{
		//残機の減少
		life--;

		con++;

		//プレイヤーの表示
		PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");
		pPlayScene->Appearance();
	}
	//残機がないなら結果画面
	else
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
	}
}