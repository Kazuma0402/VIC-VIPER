#include "PlayScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Player.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), hPict_(-1)
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
}

//更新
void PlayScene::Update()
{	
	if (Input::IsKeyDown(DIK_ESCAPE))
	{
		PostQuitMessage(0);
	}
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
