#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//コンストラクタ
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
	hModel_ = Model::Load("Assets/BoxBrock.fbx");
	assert(hModel_ >= 0);
}

//更新
void Player::Update()
{
	//移動操作
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.01;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.01;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.01;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.01;
	}

	//画面外に出ないようにする
	if (transform_.position_.y > 7.4f)
	{
		transform_.position_.y = 7.4f;
	}
	if (transform_.position_.y < -7.4f)
	{
		transform_.position_.y = -7.4f;
	}
	if (transform_.position_.x < -10.0f)
	{
		transform_.position_.x = -10.0f;
	}
	if (transform_.position_.x > 10.0f)
	{
		transform_.position_.x = 10.0f;
	}
}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}
