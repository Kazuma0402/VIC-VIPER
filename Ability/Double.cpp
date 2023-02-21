#include "Double.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/SphereCollider.h"

//コンストラクタ
Double::Double(GameObject* parent)
	:GameObject(parent, "Double"), hPict_(-1)
{
}

//デストラクタ
Double::~Double()
{
}

//初期化
void Double::Initialize()
{
	//画像のロード
	hPict_ = Image::Load("Bullet.png");
	assert(hPict_ >= 0);

	//当たり判定
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.01f);
	AddCollider(collision);

	//回転
	transform_.rotate_.z = 30.0f;
}

//更新
void Double::Update()
{
	transform_.position_.x += 0.06f;
	transform_.position_.y += 0.06f;

	if (transform_.position_.x >= 0.95f)
	{
		KillMe();
	}
}

//描画
void Double::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Double::Release()
{
}