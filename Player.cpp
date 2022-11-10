#include "Player.h"
#include "Bullet.h"
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
	hPict_ = Image::Load("VICVIPER.png");
	assert(hPict_ >= 0);

	//�v���C���[�̑傫��
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

	//�X�y�[�X�L�[��������邽��
	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet* pBullet = Instantiate<Bullet>(GetParent());
		pBullet->SetPosition(transform_.position_);
	}

	//��ʊO�ɏo�Ȃ�
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
