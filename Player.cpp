#include "Player.h"
#include "Bullet.h"
#include "Missile.h"
#include "Double.h"
#include "Laser.h"

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

	//���[�U�[�̏o��ʒu�̕␳
	trans_.position_.x = 0.45f;

	//�N�[���^�C���̏�����
	time = 0;
	time2 = 0;
	time3 = 0;
	time4 = 0;

	//�A�r���e�B�̏�����
	missile_ = false;
	double_ = false;
	laser_ = false;
}

//�X�V
void Player::Update()
{
	//�ړ�����ɂ���
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += speed;

		//���[�U�[�̏o��ʒu�̕␳
		trans_.position_.y += speed;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= speed;

		//���[�U�[�̏o��ʒu�̕␳
		trans_.position_.y -= speed;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += speed;

		//���[�U�[�̏o��ʒu�̕␳
		trans_.position_.x += speed;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= speed;

		//���[�U�[�̏o��ʒu�̕␳
		trans_.position_.x -= speed;
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

	//���[�U�[�̈ʒu����ʊO�ɂ����Ȃ��悤��
	if (trans_.position_.x > 1.37f)
	{
		if (trans_.position_.y > 0.80f)
		{
			trans_.position_.x = 1.37f;
			trans_.position_.y = 0.80f;
		}
		else if (trans_.position_.y < -0.80f)
		{
			trans_.position_.x = 1.37f;
			trans_.position_.y = -0.80f;
		}
		else
		{
			trans_.position_.x = 1.37f;
		}
	}
	else if (trans_.position_.x < -0.47f)
	{
		if (trans_.position_.y > 0.80f)
		{
			trans_.position_.x = -0.47f;
			trans_.position_.y = 0.80f;
		}
		else if (trans_.position_.y < -0.80f)
		{
			trans_.position_.x = -0.47f;
			trans_.position_.y = -0.80f;
		}
		else
		{
			trans_.position_.x = -0.47f;
		}
	}
	else if (trans_.position_.y > 0.80f)
	{
		if (trans_.position_.x > 0.92f)
		{
			trans_.position_.x = 0.92f;
			trans_.position_.y = 0.80f;
		}
		else if (trans_.position_.x < -0.92f)
		{
			trans_.position_.x = -0.92f;
			trans_.position_.y = 0.80f;
		}
		else
		{
			trans_.position_.y = 0.80f;
		}
	}
	else if (trans_.position_.y < -0.80f)
	{
		if (trans_.position_.x > 0.92f)
		{
			trans_.position_.x = 0.92f;
			trans_.position_.y = -0.80f;
		}
		else if (trans_.position_.x < -0.92f)
		{
			trans_.position_.x = -0.92f;
			trans_.position_.y = -0.80f;
		}
		else
		{
			trans_.position_.y = -0.80f;
		}
	}

	//�ˌ��ɂ���
	time++;
	time2++;
	time3++;
	time4++;

	if (time >= 10)
	{
		//���[�U�[���g�p���Ă��Ȃ��Ȃ�
		if (laser_ == false)
		{
			//�X�y�[�X�L�[�������Ă����
			if (Input::IsKey(DIK_SPACE))
			{
				Bullet* pBullet = Instantiate<Bullet>(GetParent());
				pBullet->SetPosition(transform_.position_);

				time = 0;
			}
		}
		
	}

	//�~�T�C���̔���
	if(missile_ == true)
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

	//������ւ̔���
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

	//���[�U�[�̔���
	if (laser_ == true)
	{
		if (time4 >= 30)
		{
			//�X�y�[�X�L�[�������Ă����
			if (Input::IsKey(DIK_SPACE))
			{
				Laser* pLaser = Instantiate<Laser>(GetParent());
				pLaser->SetPosition(trans_.position_);

				time4 = 0;
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
	//�~�T�C���̎g�p���ł���悤�ɂ���
	missile_ = true;
}

//�O�Ԗ�
//�e��������֔���
void Player::ShotDouble()
{
	//�Q�������˂̎g�p���ł���悤�ɂ���
	double_ = true;

	//���[�U�[�Ƃ̕��p�����ł��Ȃ�����
	laser_ = false;
}

//�l�Ԗ�
//�e��������֔���
void Player::ShotLaser()
{
	//���[�U�[�̎g�p���ł���悤�ɂ���
	laser_ = true;

	//�_�u���Ƃ̕��p���ł��Ȃ�����
	double_ = false;
}

