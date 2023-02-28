#include "Option.h"
#include "Double.h"
#include "Laser.h"
#include "Missile.h"
#include "../Object/Player.h"
#include "../Object/Bullet.h"

#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/SphereCollider.h"

//�R���X�g���N�^
Option::Option(GameObject* parent)
	:GameObject(parent, "Option")
{
}

//�f�X�g���N�^
Option::~Option()
{
}

//������
void Option::Initialize()
{
	//�摜�̃��[�h
	for (int i = 0; i < 4; i++)
	{
		hPict_[i] = Image::Load("Fighter.png");
	}

	//�ŏ��͏o�Ă��Ȃ�����O
	cnt = 0;

	//�N�[���^�C���̏�����
	time = 0;
	time2 = 0;
	time3 = 0;
	time4 = 0;

	//�A�r���e�B�̏�����
	missile_ = false;
	double_ = false;
	laser_ = false;

	//���ˑ��x
	speed = 0.01f;

	//���[�U�[�̔��ˈʒu�̕␳
	trans_.position_.x = 0.45f;

	alive = false;
}

//�X�V
void Option::Update()
{
	//�I�v�V�������\�����ꂢ��Ȃ���W�̍X�V�\
	if (FindObject("Option") != NULL)
	{
		alive = true;
	}
	else
	{
		alive = false;
		cnt = 0;
	}

	//�I�v�V�������\������Ă���Ԃ������W�̍X�V
	if(alive == true)
	{
		//��Ƀv���C���[�̐̂̈ʒu���X�V
		GetPlayerPosition20();
		GetPlayerPosition40();
		GetPlayerPosition60();
		GetPlayerPosition80();
	}

	//�ʒu�̍X�V
	pos1_.position_.x = cx[0];
	pos1_.position_.y = cy[0];
	pos2_.position_.x = cx[1];
	pos2_.position_.y = cy[1];
	pos3_.position_.x = cx[2];
	pos3_.position_.y = cy[2];
	pos4_.position_.x = cx[3];
	pos4_.position_.y = cy[3];

	//���[�U�[�̔��ˈʒu�̕␳
	trans_1.position_.x = pos1_.position_.x + trans_.position_.x;
	trans_1.position_.y = pos1_.position_.y;
	trans_2.position_.x = pos2_.position_.x + trans_.position_.x;
	trans_2.position_.y = pos2_.position_.y;
	trans_3.position_.x = pos3_.position_.x + trans_.position_.x;
	trans_3.position_.y = pos3_.position_.y;
	trans_4.position_.x = pos4_.position_.x + trans_.position_.x;
	trans_4.position_.y = pos4_.position_.y;

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
			if (cnt >= 1)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Bullet* pBullet = Instantiate<Bullet>(GetParent());
					pBullet->SetPosition(pos1_.position_);

					time = 0;
				}
			}
			if (cnt >= 2)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Bullet* pBullet = Instantiate<Bullet>(GetParent());
					pBullet->SetPosition(pos2_.position_);

					time = 0;
				}
			}
			if (cnt >= 3)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Bullet* pBullet = Instantiate<Bullet>(GetParent());
					pBullet->SetPosition(pos3_.position_);

					time = 0;
				}
			}
			if (cnt >= 4)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Bullet* pBullet = Instantiate<Bullet>(GetParent());
					pBullet->SetPosition(pos4_.position_);

					time = 0;
				}
			}
			
		}
	}

	//�~�T�C���̔���
	if (missile_ == true)
	{
		if (time2 >= 60)
		{
			if (cnt >= 1)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Missile* pMissile = Instantiate<Missile>(GetParent());
					pMissile->SetPosition(pos1_.position_);

					time2 = 0;
				}
			}
			if (cnt >= 2)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Missile* pMissile = Instantiate<Missile>(GetParent());
					pMissile->SetPosition(pos2_.position_);

					time2 = 0;
				}
			}
			if (cnt >= 3)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Missile* pMissile = Instantiate<Missile>(GetParent());
					pMissile->SetPosition(pos3_.position_);

					time2 = 0;
				}
			}
			if (cnt >= 4)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Missile* pMissile = Instantiate<Missile>(GetParent());
					pMissile->SetPosition(pos4_.position_);

					time2 = 0;
				}
			}
		}
	}

	//������ւ̔���
	if (double_ == true)
	{
		if (time3 >= 10)
		{
			if (cnt >= 1)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Double* pDouble = Instantiate<Double>(GetParent());
					pDouble->SetPosition(pos1_.position_);

					time3 = 0;
				}
			}
			if (cnt >= 2)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Double* pDouble = Instantiate<Double>(GetParent());
					pDouble->SetPosition(pos2_.position_);

					time3 = 0;
				}
			}
			if (cnt >= 3)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Double* pDouble = Instantiate<Double>(GetParent());
					pDouble->SetPosition(pos3_.position_);

					time3 = 0;
				}
			}
			if (cnt >= 4)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Double* pDouble = Instantiate<Double>(GetParent());
					pDouble->SetPosition(pos4_.position_);

					time3 = 0;
				}
			}
		}
	}

	//���[�U�[�̔���
	if (laser_ == true)
	{
		if (time4 >= 30)
		{
			if (cnt >= 1)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Laser* pLaser = Instantiate<Laser>(GetParent());
					pLaser->SetPosition(trans_1.position_);

					time4 = 0;
				}
			}
			if (cnt >= 2)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Laser* pLaser = Instantiate<Laser>(GetParent());
					pLaser->SetPosition(trans_2.position_);

					time4 = 0;
				}
			}
			if (cnt >= 3)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Laser* pLaser = Instantiate<Laser>(GetParent());
					pLaser->SetPosition(trans_3.position_);

					time4 = 0;
				}
			}
			if (cnt >= 4)
			{
				//�X�y�[�X�L�[�������Ă����
				if (Input::IsKey(DIK_SPACE))
				{
					Laser* pLaser = Instantiate<Laser>(GetParent());
					pLaser->SetPosition(trans_4.position_);

					time4 = 0;
				}
			}
		}
	}
}

//�`��
void Option::Draw()
{
	if (cnt == 0)
	{
		Image::SetTransform(hPict_[0], pos1_);
	}
	if (cnt >= 1)
	{
		Image::SetTransform(hPict_[0], pos1_);
		Image::Draw(hPict_[0]);
	}
	if (cnt >= 2)
	{
		Image::SetTransform(hPict_[1], pos2_);
		Image::Draw(hPict_[1]);
	}
	if (cnt >= 3)
	{
		Image::SetTransform(hPict_[2], pos3_);
		Image::Draw(hPict_[2]);
	}
	if (cnt >= 4)
	{
		Image::SetTransform(hPict_[3], pos4_);
		Image::Draw(hPict_[3]);
	}
}

//���
void Option::Release()
{
}

//�v���C���[�̐̂̍��W�̎擾
void Option::GetPlayerPosition20()
{	

	double tempx, tempy;
	Player* pPlayer = (Player*)FindObject("Player");
	pPlayer->GetOldPosition20(&tempx, &tempy);

	cx[0] = tempx;
	cy[0] = tempy;
}
void Option::GetPlayerPosition40()
{

	double tempx, tempy;
	Player* pPlayer = (Player*)FindObject("Player");
	pPlayer->GetOldPosition40(&tempx, &tempy);

	cx[1] = tempx;
	cy[1] = tempy;
}
void Option::GetPlayerPosition60()
{

	double tempx, tempy;
	Player* pPlayer = (Player*)FindObject("Player");
	pPlayer->GetOldPosition60(&tempx, &tempy);

	cx[2] = tempx;
	cy[2] = tempy;
}
void Option::GetPlayerPosition80()
{

	double tempx, tempy;
	Player* pPlayer = (Player*)FindObject("Player");
	pPlayer->GetOldPosition80(&tempx, &tempy);

	cx[3] = tempx;
	cy[3] = tempy;
}

//�I�v�V�����̒ǉ��\��
void Option::AddOption()
{
	cnt++;
}

//���ʏ���
void Option::KillOption()
{
	KillMe();
	alive = false;
}

//��Ԗ�
//�~�T�C���̔���
void Option::ShotMissile()
{
	//�~�T�C���̎g�p���ł���悤�ɂ���
	missile_ = true;
}

//�O�Ԗ�
//�e��������֔���
void Option::ShotDouble()
{
	//�Q�������˂̎g�p���ł���悤�ɂ���
	double_ = true;

	//���[�U�[�Ƃ̕��p�����ł��Ȃ�����
	laser_ = false;
}

//�l�Ԗ�
//�e��������֔���
void Option::ShotLaser()
{
	//���[�U�[�̎g�p���ł���悤�ɂ���
	laser_ = true;

	//�_�u���Ƃ̕��p���ł��Ȃ�����
	double_ = false;
}