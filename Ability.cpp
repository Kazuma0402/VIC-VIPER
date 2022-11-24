#include "Ability.h"
#include "Engine/Image.h"

//コンストラクタ
Ability::Ability(GameObject* parent)
	:GameObject(parent, "Ability")
{
}

//デストラクタ
Ability::~Ability()
{
}

//初期化
void Ability::Initialize()
{
	//画像データ
	std::string fileName[] = {
		"SPEEDUP.png",
		"MISSILE.png",
		"DOUBLE.png",
		"LASER.png",
		"OPTION.png",
		"HATENA.png",
	};

	std::string fileName2[] = {
		"SPEEDUP_SELECT.png",
		"MISSILE_SELECT.png",
		"DOUBLE_SELECT.png",
		"LASER_SELECT.png",
		"OPTION_SELECT.png",
		"HATENA_SELECT.png",
	};

	//画像のロード
	for (int i = 0; i < 6; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}

	for (int i = 0; i < 6; i++)
	{
		hPictSelect_[i] = Image::Load(fileName2[i]);
		assert(hPictSelect_[i] >= 0);
	}

	//初期位置
	transform_.position_.y = -0.92f;

	//大きさ
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.8f;
}

//更新
void Ability::Update()
{
	switch (count)
	{
	case 1:
		hPict_[0] = hPictSelect_[0];
		break;
	case 2:
		hPict_[1] = hPictSelect_[1];
		hPict_[0] = Image::Load("SPEEDUP.png");
		assert(hPict_[0] >= 0);
		break;
	case 3:
		hPict_[2] = hPictSelect_[2];
		break;
	case 4:
		hPict_[3] = hPictSelect_[3];
		break;
	case 5:
		hPict_[4] = hPictSelect_[4];
		break;
	case 6:
		hPict_[5] = hPictSelect_[5];
		break;
	}
}

//描画
void Ability::Draw()
{
	for (int i = 0; i < 6; i++)
	{
		transform_.position_.x = 0.2f * i - 0.5f;
		Image::SetTransform(hPict_[i], transform_);
		Image::Draw(hPict_[i]);
	}

}

//開放
void Ability::Release()
{
}

//カウントの加算
void Ability::Addition()
{
	count++;

	if (count > 6)
	{
		count = 1;
	}
}