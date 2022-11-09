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
	hPict_ = Image::Load("Assets/VICVIPER.png");
	assert(hPict_ >= 0);

	transform_.scale_.x = 0.1f;
	transform_.scale_.y = 0.1f;
}

//�X�V
void Player::Update()
{
	//�ړ�����
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.0001f;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.0001f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.0001f;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.0001f;
	}

	//��ʊO�ɏo�Ȃ��悤�ɂ���

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
