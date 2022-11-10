#include "Player.h"
#include "Bullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

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
	hPict_ = Image::Load("VICVIPER.png");
	assert(hPict_ >= 0);

	//プレイヤーの大きさ
	transform_.scale_.x = 0.3f;
	transform_.scale_.y = 0.3f;
}

//更新
void Player::Update()
{
	//移動操作
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += SPEED;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= SPEED;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += SPEED;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= SPEED;
	}

	//スペースキーが押されるたび
	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet* pBullet = Instantiate<Bullet>(GetParent());
		pBullet->SetPosition(transform_.position_);
	}

	//画面外に出ない
	if (transform_.position_.x > 0.92f)
	{
		if (transform_.position_.y > 0.92f)
		{
			transform_.position_.x = 0.92f;
			transform_.position_.y = 0.92f;
		}
		else if (transform_.position_.y < -0.92f)
		{
			transform_.position_.x = 0.92f;
			transform_.position_.y = -0.92f;
		}
		else
		{
			transform_.position_.x = 0.92f;
		}
		
	}
	else if (transform_.position_.x < -0.92f)
	{
		if (transform_.position_.y > 0.92f)
		{
			transform_.position_.x = -0.92f;
			transform_.position_.y = 0.92f;
		}
		
		else if (transform_.position_.y < -0.92f)
		{
			transform_.position_.x = -0.92f;
			transform_.position_.y = -0.92f;
		}
		else
		{
			transform_.position_.x = -0.92f;
		}

	}
	else if (transform_.position_.y > 0.92f)
	{
		if (transform_.position_.x > 0.92f)
		{
			transform_.position_.x = 0.92f;
			transform_.position_.y = 0.92f;
		}

		else if (transform_.position_.x < -0.92f)
		{
			transform_.position_.x = -0.92f;
			transform_.position_.y = 0.92f;
		}
		else
		{
			transform_.position_.y = 0.92f;
		}

	}
	else if (transform_.position_.y < -0.92f)
	{
		if (transform_.position_.x > 0.92f)
		{
			transform_.position_.x = 0.92f;
			transform_.position_.y = -0.92f;
		}

		else if (transform_.position_.x < -0.92f)
		{
			transform_.position_.x = -0.92f;
			transform_.position_.y = -0.92f;
		}
		else
		{
			transform_.position_.y = -0.92f;
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
