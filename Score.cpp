#include "Score.h""
#include "Engine/Image.h"

//コンストラクタ
Score::Score(GameObject* parent)
	: GameObject(parent, "Score")
{
}

//初期化
void Score::Initialize()
{
	//画像データ
	std::string fileName[] = {
		"Clear.png",
		"0.png",
		"1.png",
		"2.png",
		"3.png",
		"4.png",
		"5.png",
		"6.png",
		"7.png",
		"8.png",
		"9.png",
	};

	//画像のロード
	for (int i = 0; i < 11; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}

	//スコア画像の初期表示
	for (int i = 0; i < 6; i++)
	{
		//スコアを０からスタートさせる
		if (i == 0)
		{
			hScore_[i] = hPict_[1];
		}
		else
		{
			hScore_[i] = hPict_[0];
		}	
	}

	//初期位置
	transform_.position_.x = -0.4f;
	transform_.position_.y = 0.92f;
}

//更新
void Score::Update()
{
}

//描画
void Score::Draw()
{
	for (int i = 0; i < 6; i++)
	{
		transform_.position_.x = -0.05f * i - 0.1f;
		Image::SetTransform(hScore_[i], transform_);
		Image::Draw(hScore_[i]);
	}
	
}

//開放
void Score::Release()
{
}

//スコア加算
void Score::Addition()
{
	count++;
	if (count >= 10)
	{
		count = 2;
		hScore_[1] = hPict_[count];
	}
	else
	{
		hScore_[1] = hPict_[count];
	}
}
