#include "TitleScene.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), hPict_(-1), hPict_2(-1)
{
}

//初期化
void TitleScene::Initialize()
{
	//画像のロード
	hPict_ = Image::Load("Title.jpg");
	assert(hPict_ >= 0);

	hPict_2 = Image::Load("yajirusi.png");
	assert(hPict_2 >= 0);

	//矢印の初期位置
	trans_.position_.x = -0.45;
	trans_.position_.y = -0.1;
}

//更新
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_UP))
	{
		trans_.position_.x = -0.45;
		trans_.position_.y = -0.1;

		choice = 0;
	}
	if (Input::IsKeyDown(DIK_DOWN))
	{
		trans_.position_.x = -0.45;
		trans_.position_.y = -0.5;

		choice = 1;
	}
	switch (choice)
	{
	case 0:
		if (Input::IsKeyDown(DIK_RETURN))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_PLAY);
		}
		break;
	case 1:
		if (Input::IsKeyDown(DIK_RETURN))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_OPTION);
		}
		break;
	}
	
}

//描画
void TitleScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
	Image::SetTransform(hPict_2, trans_);
	Image::Draw(hPict_2);
}

//開放
void TitleScene::Release()
{
}