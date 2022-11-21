#include "Enemy2.h"
#include "EnemyBullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Score.h";

//コンストラクタ
Enemy2::Enemy2(GameObject* parent)
	:GameObject(parent, "Enemy2")
{
}

//デストラクタ
Enemy2::~Enemy2()
{
}

//初期化
void Enemy2::Initialize()
{
	//敵１
	hPict_ = Image::Load("Enemy.png");
	assert(hPict_ >= 0);

	//敵１
	//初期位置
	transform_.position_.x = 2.2f;
	transform_.position_.y = -0.4f;

	//敵の大きさ
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//当たり判定（丸）
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);


}

//更新
void Enemy2::Update()
{
	//移動速度
	transform_.position_.x -= 0.01f;
}

//描画
void Enemy2::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Enemy2::Release()
{
}

//何かに当たった
void Enemy2::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	if (pTarget->GetObjectName() == "Bullet")
	{
		//敵が消える
		KillMe();
		//弾が消える
		pTarget->KillMe();

		//敵を倒したらスコアの加算
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();
	}
}