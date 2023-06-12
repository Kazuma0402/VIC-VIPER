#include "Stage.h"
#include "../Engine/Image.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
	: GameObject(parent, "Stage")
{
}

//初期化
void Stage::Initialize()
{
	//画像データ
	std::string fileName[] = {
		"Stage1-1.png",
		"Stage1-2.png",
		"Stage1-3.png",
		"Stage1-4.png",
	};

	//画像のロード
	for (int i = 0; i < 4; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}

	//初期位置
	trans1_.position_.x = 10.0f;
	trans2_.position_.x = 11.95f;
	trans3_.position_.x = 13.95f;
	trans4_.position_.x = 15.85f;
}

//更新
void Stage::Update()
{
	//ステージの移動
	trans1_.position_.x -= 0.003f;
	trans2_.position_.x -= 0.003f;
	trans3_.position_.x -= 0.003f;
	trans4_.position_.x -= 0.003f;
}

//描画
void Stage::Draw()
{
	Image::SetTransform(hPict_[0], trans1_);
	Image::Draw(hPict_[0]);
	Image::SetTransform(hPict_[1], trans2_);
	Image::Draw(hPict_[1]);
	Image::SetTransform(hPict_[2], trans3_);
	Image::Draw(hPict_[2]);
	Image::SetTransform(hPict_[3], trans4_);
	Image::Draw(hPict_[3]);
}

//開放
void Stage::Release()
{
}
