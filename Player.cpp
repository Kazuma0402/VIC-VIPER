#include "Player.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

#define SPEED 0.001f;		//�v���C���[�̉����x

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
	hPict_ = Image::Load("VICVIPER.png");
	assert(hPict_ >= 0);

	transform_.scale_.x = 0.3f;
	transform_.scale_.y = 0.3f;
}

//�X�V
void Player::Update()
{
	//�ړ�����
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
