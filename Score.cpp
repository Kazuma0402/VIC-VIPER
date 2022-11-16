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
	
	//スコアが増え始めたら１０の位に０を表示
	if (count > 0)
	{
		hScore_[1] = hPict_[1];
	}

	//各位に数値の代入
	Hundred = count % 10;
	Thousand = ((count % 1000) % 100) / 10;
	TenThousand = (count % 1000) / 100;
	OneHundredThousand = count / 1000;
	
	//画像データの１が０のため＋１の処理
	if (count >= 1)
	{
		Hundred++;
	}
	if (count >= 10)
	{
		Thousand++;
	}
	if (count >= 100)
	{
		TenThousand++;
	}
	if (count >= 1000)
	{
		OneHundredThousand++;
	}

	//代入した数値データをもとにスコアの表示の変更
	hScore_[2] = hPict_[Hundred];
	hScore_[3] = hPict_[Thousand];
	hScore_[4] = hPict_[TenThousand];
	hScore_[5] = hPict_[OneHundredThousand];
}

void Score::Addition2()
{
	count = count + 10;

	//スコアが増え始めたら１０の位に０を表示
	if (count > 0)
	{
		hScore_[1] = hPict_[1];
	}
	//各位に数値の代入
	Thousand = ((count % 1000) % 100) / 10;
	TenThousand = (count % 1000) / 100;
	OneHundredThousand = count / 1000;

	//画像データの１が０のため＋１の処理
	if (count >= 10)
	{
		Thousand++;
	}
	if (count >= 100)
	{
		TenThousand++;
	}
	if (count >= 1000)
	{
		OneHundredThousand++;
	}

	//代入した数値データをもとにスコアの表示の変更
	hScore_[2] = hPict_[Hundred];
	hScore_[3] = hPict_[Thousand];
	hScore_[4] = hPict_[TenThousand];
	hScore_[5] = hPict_[OneHundredThousand];
}
