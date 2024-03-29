#include "Boss.h"
#include "EnemyBullet.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Display/Score.h"

//コンストラクタ
Boss::Boss(GameObject* parent)
	:GameObject(parent, "Boss"), hPict_(-1)
{
}

//デストラクタ
Boss::~Boss()
{
}

//初期化
void Boss::Initialize()
{
	//画像のロード
	hPict_ = Image::Load("Boss.png");
	assert(hPict_ >= 0);

	//初期位置
	transform_.position_.x = 50.00f;
	transform_.position_.y = 0.4f;
	//大きさ
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//当たり判定（丸）
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

	//体力の初期化
	hp = 100;

	move = false;

	wavePoint = false;

	time = 0;
}

//更新
void Boss::Update()
{
	if (transform_.position_.x >= 0.4f)
	{
		//移動速度
		transform_.position_.x -= 0.005f;
	}
	else if (transform_.position_.x <= 0.4f)
	{
		move = true;
	}
	
	//移動の切り替え
	if (move == true && wavePoint == false)
	{
		transform_.position_.y += 0.005f;

		if (transform_.position_.y >= 0.70f)
		{
			wavePoint = true;
		}
	}
	else if (move == true && wavePoint == true)
	{
		transform_.position_.y -= 0.005f;

		if (transform_.position_.y <= -0.70f)
		{
			wavePoint = false;
		}
	}

	//if (move == true)
	//{
	//	time++;

	//	if (time >= 120)
	//	{
	//		EnemyBullet* pEnemyBullet = Instantiate<EnemyBullet>(GetParent());
	//		pEnemyBullet->SetPosition(transform_.position_);

	//		time = 0;
	//	}
	//}
	
}

//描画
void Boss::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Boss::Release()
{
}

//何かに当たった
void Boss::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	if (pTarget->GetObjectName() == "Bullet")
	{
		//敵が消える
		hp--;

		//弾が消える
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
	//当たったときの処理
	if (pTarget->GetObjectName() == "Missile")
	{
		//敵が消える
		hp--;

		//弾が消える
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
	//当たったときの処理
	if (pTarget->GetObjectName() == "Double")
	{
		//敵が消える
		hp--;

		//弾が消える
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
	//当たったときの処理
	if (pTarget->GetObjectName() == "Laser")
	{
		//敵が消える
		hp -= 3;

		//弾が消える
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
}
