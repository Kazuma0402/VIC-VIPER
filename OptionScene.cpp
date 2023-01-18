#include "OptionScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//コンストラクタ
OptionScene::OptionScene(GameObject* parent)
	: GameObject(parent, "OptionScene"), hPict_(-1)
{
}

//初期化
void OptionScene::Initialize()
{
	hPict_ = Image::Load("Rule.png");
	assert(hPict_ >= 0);
}

//更新
void OptionScene::Update()
{
	if (Input::IsKey(DIK_ESCAPE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

//描画
void OptionScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void OptionScene::Release()
{
}