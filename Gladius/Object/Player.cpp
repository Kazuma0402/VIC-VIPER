#include "Player.h"
#include "Bullet.h"
#include "../Ability/Missile.h"
#include "../Ability/Double.h"
#include "../Ability/Laser.h"
#include "../Ability/Option.h"

#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Camera.h"
#include "../Engine/SceneManager.h"

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

	//�R�i�~�R�}���h�p�i���j
	cnt = 0;

	angle = false;

	//���W�̏�����
	for (int i = 0; i < 81; i++)
	{
		cx[i] = 0;
		cy[i] = 0;
	}	
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

		angle = true;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= speed;

		//���[�U�[�̏o��ʒu�̕␳
		trans_.position_.y -= speed;

		angle = true;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += speed;

		//���[�U�[�̏o��ʒu�̕␳
		trans_.position_.x += speed;

		angle = true;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= speed;

		//���[�U�[�̏o��ʒu�̕␳
		trans_.position_.x -= speed;

		angle = true;
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

	//�v���C���[���ړ���������W�̋L�^���X�V
	if (angle != false)
	{
		//���W���L�^
		for (int i = 79; i >= 0; i--)
		{
			cx[i + 1] = cx[i];
			cy[i + 1] = cy[i];
		}
		cx[0] = this->transform_.position_.x;
		cy[0] = this->transform_.position_.y;

		angle = false;
	}

	//�R�i�~�R�}���h�i���j
	switch (cnt)
	{
	case 0: 
	case 1:
		if (Input::IsKeyUp(DIK_UP))
		{
			cnt++;
		}
		break;
	case 2:
	case 3:
		if (Input::IsKeyUp(DIK_DOWN))
		{
			cnt++;
		}
		break;
	case 4:
		if (Input::IsKeyUp(DIK_LEFT))
		{
			cnt++;
		}
		break;
	case 5:
		if (Input::IsKeyUp(DIK_RIGHT))
		{
			cnt++;
		}
		break;
	case 6:
		if (Input::IsKeyUp(DIK_LEFT))
		{
			cnt++;
		}
		break;
	case 7:
		if (Input::IsKeyUp(DIK_RIGHT))
		{
			cnt++;
		}
		break;
	case 8:
		if (Input::IsKeyUp(DIK_RSHIFT))
		{
			
			cnt++;
		}
		break;
	case 9:
		if (Input::IsKeyUp(DIK_RETURN))
		{
			ShotMissile();
			ShotLaser();
			Option* pOption = (Option*)FindObject("Option");
			for (int i = 0; i < 2; i++)
			{
				pOption->AddOption();
			}
			pOption->ShotMissile();
			pOption->ShotLaser();
			cnt++;
		}
		break;
	case 10:
		break;
	default:
		cnt = 0;
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
	if (pTarget->GetObjectName() == "Enemy2")
	{
		KillMe();
		pTarget->KillMe();
	}
	if (pTarget->GetObjectName() == "EnemyBullet")
	{
		KillMe();
		pTarget->KillMe();
	}
	if (pTarget->GetObjectName() == "Boss")
	{
		KillMe();
	}
}

//�ʒu�擾
void Player::GetPosition(double* x, double* y)
{
	//���݂̈ʒu�̎擾
	*x = this->transform_.position_.x;
	*y = this->transform_.position_.y;
}

//�̂̈ʒu���擾
void Player::GetOldPosition20(double* x, double* y)
{
	//�ʒu�̎擾
	if (FindObject("Player") != NULL)
	{
		*x = cx[20];
		*y = cy[20];
	}
}
// �̂̈ʒu���擾
void Player::GetOldPosition40(double* x, double* y)
{
	//�ʒu�̎擾
	*x = cx[40];
	*y = cy[40];
}
// �̂̈ʒu���擾
void Player::GetOldPosition60(double* x, double* y)
{
	//�ʒu�̎擾
	*x = cx[60];
	*y = cy[60];
}
// �̂̈ʒu���擾
void Player::GetOldPosition80(double* x, double* y)
{
	//�ʒu�̎擾
	*x = cx[80];
	*y = cy[80];
}

//�A�r���e�B�̉��
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

//�Z�Ԗ�
//�@�̂̕ύX
void Player::Change()
{
	//�傫��
	transform_.scale_.x = 2.0f;
	transform_.scale_.y = 2.0f;

	//�����蔻��
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.20f);
	AddCollider(collision);

	//���[�h
	hPict_ = Image::Load("Nezuko.png");
	assert(hPict_ >= 0);

	//�h���[
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}