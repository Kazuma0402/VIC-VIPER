#include "Laser.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Laser::Laser(GameObject* parent)
	:GameObject(parent, "Laser"), hPict_(-1)
{
}

//デストラクタ
Laser::~Laser()
{
}

//初期化
void Laser::Initialize()
{
	hPict_ = Image::Load("LaserBullet.png");
	assert(hPict_ >= 0);

	//当たり判定
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.1f, 0.1f, 0.1f));
	AddCollider(collision);
}

//更新
void Laser::Update()
{
	transform_.position_.x += 0.05f;

	if (transform_.position_.x >= 2.0f)
	{
		KillMe();
	}
}

//描画
void Laser::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Laser::Release()
{
}
