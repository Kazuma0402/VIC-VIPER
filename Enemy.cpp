#include "Enemy.h"
#include "EnemyBullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hPict_(-1)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
	hPict_ = Image::Load("Enemy.png");
	assert(hPict_ >= 0);

	//初期位置
	transform_.position_.x = 0.46;

	//敵の大きさ
	transform_.scale_.x = 0.3f;
	transform_.scale_.y = 0.3f;

	//当たり判定（丸）
	SphereCollider* collision = new SphereCollider(XMFLOAT3( 0.0f, 0.0f, 0.0f), 0.05f);
	AddCollider(collision);
}

//更新
void Enemy::Update()
{
	////時間の加算
	//time++;

	////一定時間で球を発射
	//if (time >= 1000)
	//{
	//	EnemyBullet* pEnemyBullet = Instantiate<EnemyBullet>(GetParent());
	//	pEnemyBullet->SetPosition(transform_.position_);

	//	//カウント時間のリセット
	//	time = 0;
	//}
}

//描画
void Enemy::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Enemy::Release()
{
}

//何かに当たった
void Enemy::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	if (pTarget->GetObjectName() == "Bullet")
	{
		KillMe();
		pTarget->KillMe();
	}
}