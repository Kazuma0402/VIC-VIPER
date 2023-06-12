#include "GameClearScene.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"

//コンストラクタ
GameClearScene::GameClearScene(GameObject* parent)
	: GameObject(parent, "GameClearScene"), hPict_(-1)
{
}

//初期化
void GameClearScene::Initialize()
{
	hPict_ = Image::Load("GameClear.png");
	assert(hPict_ >= 0);
}

//更新
void GameClearScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

//描画
void GameClearScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void GameClearScene::Release()
{
}
