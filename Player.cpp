#include "Player.h"
#include "Bullet.h"
#include "Missile.h"
#include "Double.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hPict_(-1)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
	//ロード
	hPict_ = Image::Load("VICVIPER.png");
	assert(hPict_ >= 0);

	//プレイヤーの大きさ
	transform_.scale_.x = 0.3f;
	transform_.scale_.y = 0.3f;

	//当たり判定
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.08f);
	AddCollider(collision);

	//機体の初期スピード
	speed = 0.01f;

	//クールタイムの初期化
	time = 0;
	time2 = 0;

	//アビリティの初期化
	missile = false;
	double_ = false;
}

//更新
void Player::Update()
{
	//移動操作について
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += speed;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= speed;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += speed;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= speed;
	}

	//画面外に出ない
	if (transform_.position_.x > 0.92f)
	{
		if (transform_.position_.y > 0.80f)
		{
			transform_.position_.x = 0.92f;
			transform_.position_.y = 0.80f;
		}
		else if (transform_.position_.y < -0.80f)
		{
			transform_.position_.x = 0.92f;
			transform_.position_.y = -0.80f;
		}
		else
		{
			transform_.position_.x = 0.92f;
		}
		
	}
	else if (transform_.position_.x < -0.92f)
	{
		if (transform_.position_.y > 0.80f)
		{
			transform_.position_.x = -0.92f;
			transform_.position_.y = 0.80f;
		}
		else if (transform_.position_.y < -0.80f)
		{
			transform_.position_.x = -0.92f;
			transform_.position_.y = -0.80f;
		}
		else
		{
			transform_.position_.x = -0.92f;
		}

	}
	else if (transform_.position_.y > 0.80f)
	{
		if (transform_.position_.x > 0.92f)
		{
			transform_.position_.x = 0.92f;
			transform_.position_.y = 0.80f;
		}
		else if (transform_.position_.x < -0.92f)
		{
			transform_.position_.x = -0.92f;
			transform_.position_.y = 0.80f;
		}
		else
		{
			transform_.position_.y = 0.80f;
		}

	}
	else if (transform_.position_.y < -0.80f)
	{
		if (transform_.position_.x > 0.92f)
		{
			transform_.position_.x = 0.92f;
			transform_.position_.y = -0.80f;
		}
		else if (transform_.position_.x < -0.92f)
		{
			transform_.position_.x = -0.92f;
			transform_.position_.y = -0.80f;
		}
		else
		{
			transform_.position_.y = -0.80f;
		}
	}

	//射撃について
	time++;
	time2++;
	time3++;

	if (time >= 10)
	{
		//スペースキーが押している間
		if (Input::IsKey(DIK_SPACE))
		{
			Bullet* pBullet = Instantiate<Bullet>(GetParent());
			pBullet->SetPosition(transform_.position_);

			time = 0;
		}
	}

	//ミサイルの発射
	if(missile == true)
	{
		if (time2 >= 60)
		{
			//スペースキーが押している間
			if (Input::IsKey(DIK_SPACE))
			{
				Missile* pMissile = Instantiate<Missile>(GetParent());
				pMissile->SetPosition(transform_.position_);

				time2 = 0;
			}
		}
	}

	//ミサイルの発射
	if (double_ == true)
	{
		if (time3 >= 10)
		{
			//スペースキーが押している間
			if (Input::IsKey(DIK_SPACE))
			{
				Double* pDouble = Instantiate<Double>(GetParent());
				pDouble->SetPosition(transform_.position_);

				time3 = 0;
			}
		}
	}
}

//描画
void Player::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Player::Release()
{
}

//当たり判定
void Player::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	if (pTarget->GetObjectName() == "Enemy")
	{
		KillMe();
		pTarget->KillMe();
	}
}

//アビリティの開放

//一番目
//スピードアップ
void Player::SpeedUp()
{
	speed += 0.005f;
}

//二番目
//ミサイルの発射
void Player::ShotMissile()
{
	missile = true;
}

//三番目
//弾が二方向へ発射
void Player::ShotDouble()
{
	double_ = true;
}

