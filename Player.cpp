#include "Player.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"


//�R���X�g���N�^
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hPict_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
	hPict_ = Image::Load("Assets/Gradius.png");
	assert(hPict_ >= 0);
}

//�X�V
void Player::Update()
{
	//�ړ�����
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.001f;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.001f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.001f;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.001f;
	}

	//��ʊO�ɏo�Ȃ��悤�ɂ���
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

//�`��
void Player::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Player::Release()
{
}
