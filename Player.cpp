#include "Player.h"
#include "Bullet.h"
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
}

//�X�V
void Player::Update()
{
	//�ړ�����
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.01f;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.01f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.01f;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.01f;
	}

	//�ˌ�
	time++;

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
	

	//��ʊO�ɏo�Ȃ�
	if (transform_.position_.x > 0.92f)
	{
		if (transform_.position_.y > 0.80f)
		{
			transform_.position_.x = 0.92f;
			transform_.position_.y = 0.80f;
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
		if (transform_.position_.y > 0.80f)
		{
			transform_.position_.x = -0.92f;
			transform_.position_.y = 0.80f;
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

//�����蔻��
void Player::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Enemy" || pTarget->GetObjectName() == "EnemyBullet")
	{
		KillMe();
		pTarget->KillMe();
	}
}