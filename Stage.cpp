#include "Stage.h"
#include "Engine/Image.h"
#include "Enemy.h"
#include "Enemy2.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
	: GameObject(parent, "Stage")
{
}

//初期化
void Stage::Initialize()
{
}

//更新
void Stage::Update()
{
	//一定時間で敵を出現させる
	time++;
	if (time >= 15 && count < 4)
	{
		Instantiate<Enemy>(this);
		Instantiate<Enemy2>(this);
		time = 0;
		count++;
	}

	if (time >= 210 && count >= 4)
	{
		time = 0;
		count = 0;
	}
}

//描画
void Stage::Draw()
{
}

//開放
void Stage::Release()
{
}