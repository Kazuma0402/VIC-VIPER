#include "Boss.h"
#include "EnemyBullet.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Display/Score.h"

//�R���X�g���N�^
Boss::Boss(GameObject* parent)
	:GameObject(parent, "Boss"), hPict_(-1)
{
}

//�f�X�g���N�^
Boss::~Boss()
{
}

//������
void Boss::Initialize()
{
	//�摜�̃��[�h
	hPict_ = Image::Load("Boss.png");
	assert(hPict_ >= 0);

	//�����ʒu
	transform_.position_.x = 50.00f;
	transform_.position_.y = 0.4f;
	//�傫��
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

	//�̗͂̏�����
	hp = 100;

	move = false;

	wavePoint = false;

	time = 0;
}

//�X�V
void Boss::Update()
{
	if (transform_.position_.x >= 0.4f)
	{
		//�ړ����x
		transform_.position_.x -= 0.005f;
	}
	else if (transform_.position_.x <= 0.4f)
	{
		move = true;
	}
	
	//�ړ��̐؂�ւ�
	if (move == true && wavePoint == false)
	{
		transform_.position_.y += 0.005f;

		if (transform_.position_.y >= 0.70f)
		{
			wavePoint = true;
		}
	}
	else if (move == true && wavePoint == true)
	{
		transform_.position_.y -= 0.005f;

		if (transform_.position_.y <= -0.70f)
		{
			wavePoint = false;
		}
	}

	//if (move == true)
	//{
	//	time++;

	//	if (time >= 120)
	//	{
	//		EnemyBullet* pEnemyBullet = Instantiate<EnemyBullet>(GetParent());
	//		pEnemyBullet->SetPosition(transform_.position_);

	//		time = 0;
	//	}
	//}
	
}

//�`��
void Boss::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Boss::Release()
{
}

//�����ɓ�������
void Boss::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Bullet")
	{
		//�G��������
		hp--;

		//�e��������
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Missile")
	{
		//�G��������
		hp--;

		//�e��������
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Double")
	{
		//�G��������
		hp--;

		//�e��������
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Laser")
	{
		//�G��������
		hp -= 3;

		//�e��������
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
}
