#include "OptionScene.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"

//コンストラクタ
OptionScene::OptionScene(GameObject* parent)
	: GameObject(parent, "OptionScene"), nowPict_(-1)
{
}

//初期化
void OptionScene::Initialize()
{
	//画像のロード
	hPict_[0] = Image::Load("Rule.png");
	assert(hPict_[0] >= 0);
	hPict_[1] = Image::Load("Rule2.png");
	assert(hPict_[1] >= 0);
	nowPict_ = Image::Load("Rule.png");
	assert(nowPict_ >= 0);

	//
	push = false;
}

//更新
void OptionScene::Update()
{
	if (push == false)
	{
		if (Input::IsKey(DIK_RIGHT))
		{
			nowPict_ = hPict_[1];
			push = true;
		}
	}
	
	if (push == true)
	{
		if (Input::IsKey(DIK_LEFT))
		{
			nowPict_ = hPict_[0];
			push = false;
		}
		else if (Input::IsKey(DIK_ESCAPE))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_TITLE);
		}
	}
	
}

//描画
void OptionScene::Draw()
{
	Image::SetTransform(nowPict_, transform_);
	Image::Draw(nowPict_);
}

//開放
void OptionScene::Release()
{
}