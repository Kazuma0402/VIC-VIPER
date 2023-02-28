#include "Enemy.h"
#include "Player.h"
#include "../Display/Score.h"
#include "../Scene/PlayScene.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Camera.h"
#include "../Engine/SphereCollider.h"

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
	//transform_.position_.y = (float)(rand() % 180 - 110) / 100;
	
	//大きさ
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//当たり判定（丸）
	SphereCollider* collision = new SphereCollider(XMFLOAT3( 0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

	//ウェーブポイントの初期化
	wavePoint = 0;
}

//更新
void Enemy::Update()
{
	//移動
	transform_.position_.x -= 0.005f;

	//一定の位置より先に行くと消える
	if (transform_.position_.x <= -1.00f)
	{
		KillMe();
	}
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
		//死んだ位置の保存
		GetPosition(&pos_x, &pos_y);

		//敵が消える
		KillMe();

		//弾が消える
		pTarget->KillMe();

		//敵を倒したらスコア加算
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();
	}
	//当たったときの処理
	if (pTarget->GetObjectName() == "Missile")
	{
		//死んだ位置の保存
		GetPosition(&pos_x, &pos_y);

		//敵が消える
		KillMe();

		//弾が消える
		pTarget->KillMe();

		//敵を倒したらスコア加算
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();

	}
	//当たったときの処理
	if (pTarget->GetObjectName() == "Double")
	{
		//死んだ位置の保存
		GetPosition(&pos_x, &pos_y);

		//敵が消える
		KillMe();

		//弾が消える
		pTarget->KillMe();

		//敵を倒したらスコア加算
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();

	}
	//当たったときの処理
	if (pTarget->GetObjectName() == "Laser")
	{
		//死んだ位置の保存
		GetPosition(&pos_x, &pos_y);

		//敵が消える
		KillMe();

		//敵を倒したらスコア加算
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();

	}
}

//位置取得
void Enemy::GetPosition(double* x, double* y)
{
	//現在の位置の取得
	*x = this->transform_.position_.x;
	*y = this->transform_.position_.y;
}

//死んだ位置をアイテムへ送る
void Enemy::SendOldPosition(double* x, double* y)
{
	*x = pos_x;
	*y = pos_y;
}