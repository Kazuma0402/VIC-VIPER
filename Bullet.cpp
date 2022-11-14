#include "Bullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hPict_(-1)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
	hPict_ = Image::Load("Bullet.png");
	assert(hPict_ >= 0);

	//当たり判定
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.01f);
	AddCollider(collision);
}

//更新
void Bullet::Update()
{
	transform_.position_.x += 0.003f;

	if (transform_.position_.x >= 0.95f)
	{
		KillMe();
	}
}

//描画
void Bullet::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Bullet::Release()
{
}
