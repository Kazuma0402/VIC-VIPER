#include "Enemy.h"
#include "EnemyBullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Score.h"
#include "PlayScene.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"),hPict_(-1)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
	//画像のロード
	hPict_ = Image::Load("Enemy.png");
	assert(hPict_ >= 0);

	//初期位置
	transform_.position_.x = 1.0f;
	transform_.position_.y = 0.4f;
	
	//大きさ
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//当たり判定（丸）
	SphereCollider* collision = new SphereCollider(XMFLOAT3( 0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

}

//更新
void Enemy::Update()
{
	//移動速度
	transform_.position_.x -= 0.01f;
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
		//敵が消える
		KillMe();

		//弾が消える
		pTarget->KillMe();

		//敵を倒したらスコア加算
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();
	}
}
