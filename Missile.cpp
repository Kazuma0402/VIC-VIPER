#include "Missile.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Missile::Missile(GameObject* parent)
	:GameObject(parent, "Missile"), hPictNow_(-1)
{
}

//デストラクタ
Missile::~Missile()
{
}

//初期化
void Missile::Initialize()
{
	//画像データ
	std::string fileName[] = {
		"Missile1.png",
		"Missile2.png",
	};

	//画像のロード
	for (int i = 0; i < 2; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}
	
	hPictNow_ = Image::Load("Missile1.png");
	assert(hPictNow_ >= 0);

	//当たり判定
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.01f);
	AddCollider(collision);

}

//更新
void Missile::Update()
{
	transform_.position_.x += 0.01f;
	transform_.position_.y -= 0.03f;

	//一定数以上行くと消える
	if (transform_.position_.x >= 0.95f || transform_.position_.y <= -0.95f)
	{
		KillMe();
	}
}

//描画
void Missile::Draw()
{
	Image::SetTransform(hPictNow_, transform_);
	Image::Draw(hPictNow_);
}

//開放
void Missile::Release()
{
}
