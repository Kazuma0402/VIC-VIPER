#include "Player.h"
#include "Bullet.h"
#include "Missile.h"
#include "Double.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"

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
	//���[�h
	hPict_ = Image::Load("VICVIPER.png");
	assert(hPict_ >= 0);

	//�v���C���[�̑傫��
	transform_.scale_.x = 0.3f;
	transform_.scale_.y = 0.3f;

	//�����蔻��
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.08f);
	AddCollider(collision);

	//�@�̂̏����X�s�[�h
	speed = 0.01f;

	//�N�[���^�C���̏�����
	time = 0;
	time2 = 0;

	//�A�r���e�B�̏�����
	missile = false;
	double_ = false;
}

//�X�V
void Player::Update()
{
	//�ړ�����ɂ���
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

	//��ʊO�ɏo�Ȃ�
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

	//�ˌ��ɂ���
	time++;
	time2++;
	time3++;

	if (time >= 10)
	{
		//�X�y�[�X�L�[�������Ă����
		if (Input::IsKey(DIK_SPACE))
		{
			Bullet* pBullet = Instantiate<Bullet>(GetParent());
			pBullet->SetPosition(transform_.position_);

			time = 0;
		}
	}

	//�~�T�C���̔���
	if(missile == true)
	{
		if (time2 >= 60)
		{
			//�X�y�[�X�L�[�������Ă����
			if (Input::IsKey(DIK_SPACE))
			{
				Missile* pMissile = Instantiate<Missile>(GetParent());
				pMissile->SetPosition(transform_.position_);

				time2 = 0;
			}
		}
	}

	//�~�T�C���̔���
	if (double_ == true)
	{
		if (time3 >= 10)
		{
			//�X�y�[�X�L�[�������Ă����
			if (Input::IsKey(DIK_SPACE))
			{
				Double* pDouble = Instantiate<Double>(GetParent());
				pDouble->SetPosition(transform_.position_);

				time3 = 0;
			}
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

//�����蔻��
void Player::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Enemy")
	{
		KillMe();
		pTarget->KillMe();
	}
}

//�A�r���e�B�̊J��

//��Ԗ�
//�X�s�[�h�A�b�v
void Player::SpeedUp()
{
	speed += 0.005f;
}

//��Ԗ�
//�~�T�C���̔���
void Player::ShotMissile()
{
	missile = true;
}

//�O�Ԗ�
//�e��������֔���
void Player::ShotDouble()
{
	double_ = true;
}

