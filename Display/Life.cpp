#include "Life.h"
#include "../Ability/Ability.h"
#include "../Ability/Option.h"

#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Scene/PlayScene.h"

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
	//画像のロード
	std::string fileName = "Life.png";
	for (int i = 0; i < 3; i++)
	{
		hPictCon_[i] = Image::Load(fileName);
	}

	//残機の初期位置
	transform_.position_.x = -0.7f;
	transform_.position_.y = 0.92f;

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
		transform_.position_.x = 0.1f * i - 0.7f;
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
	hPictCon_[con] = -1;

	//残機があるなら表示
	if (life > 0)
	{
		//残機の減少
		life--;

		con++;

		//PlaySceneのインスタンス呼び出し
		PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");

		//プレイヤーの表示
		pPlayScene->AppearancePlayer();

		//-----アビリティクラスについて-----
		Ability* pAbility = (Ability*)FindObject("Ability");

		//アビリティの点灯の初期化
		pAbility->CountReset();

		//アビリティの使用回数の復活
		pAbility->AbilityHeel();

		//アビリティ表示のリセット
		pAbility->AbilityReset();

		//オプション側のアビリティの回復
		Option* pOption = (Option*)FindObject("Option");
		pOption->AbilityHeel();
	}
	//残機がないなら結果画面
	else
	{
		//ゲーム結果画面への遷移
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
	}
}