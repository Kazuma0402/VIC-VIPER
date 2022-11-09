#include "Player.h"
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

	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;
}

//更新
void Player::Update()
{
	//移動操作
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.0005f;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.0005f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.0005f;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.0005f;
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
