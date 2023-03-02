#include "Enemy.h"
#include "Player.h"
#include "Item.h"
#include "../Display/Score.h"
#include "../Scene/PlayScene.h"

#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Camera.h"
#include "../Engine/SphereCollider.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"),hPict_(-1)
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
	//�摜�̃��[�h
	hPict_ = Image::Load("Enemy.png");
	assert(hPict_ >= 0);

	//�����ʒu
	transform_.position_.x = 1.0f;
	transform_.position_.y = (rand() % 160 - 80.0f) / 100;
	
	//�傫��
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3( 0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

	//�E�F�[�u�|�C���g�̏�����
	wavePoint = 0;

	num = rand() % 5;
}

//�X�V
void Enemy::Update()
{
	//�ړ�
	transform_.position_.x -= 0.005f;

	//���̈ʒu����ɍs���Ə�����
	if (transform_.position_.x <= -1.00f)
	{
		KillMe();
	}
}

//�`��
void Enemy::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Enemy::Release()
{
}

//�����ɓ�������
void Enemy::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Bullet")
	{
		//�G�̎��񂾈ʒu���擾
		GetPosition(&pos_x, &pos_y);

		//�擾�����ʒu��ۑ�
		tempx = pos_x;
		tempy = pos_y;

		//�m���ŃA�C�e���̕\��
		if (num == 0)
		{
			PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");
			pPlayScene->AppearanceItem();
		}
			
		//�G��������
		KillMe();

		//�e��������
		pTarget->KillMe();

		//�G��|������X�R�A���Z
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();
	}
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Missile")
	{
		//�G�̎��񂾈ʒu���擾
		GetPosition(&pos_x, &pos_y);

		//�擾�����ʒu��ۑ�
		tempx = pos_x;
		tempy = pos_y;

		//�m���ŃA�C�e���̕\��
		if (num == 0)
		{
			PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");
			pPlayScene->AppearanceItem();
		}

		//�G��������
		KillMe();

		//�e��������
		pTarget->KillMe();

		//�G��|������X�R�A���Z
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();

	}
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Double")
	{
		//�G�̎��񂾈ʒu���擾
		GetPosition(&pos_x, &pos_y);

		//�擾�����ʒu��ۑ�
		tempx = pos_x;
		tempy = pos_y;

		//�m���ŃA�C�e���̕\��
		if (num == 0)
		{
			PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");
			pPlayScene->AppearanceItem();
		}

		//�G��������
		KillMe();

		//�e��������
		pTarget->KillMe();

		//�G��|������X�R�A���Z
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();

	}
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Laser")
	{
		//�G�̎��񂾈ʒu���擾
		GetPosition(&pos_x, &pos_y);

		//�擾�����ʒu��ۑ�
		tempx = pos_x;
		tempy = pos_y;

		//�m���ŃA�C�e���̕\��
		if (num == 0)
		{
			PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");
			pPlayScene->AppearanceItem();
		}

		//�G��������
		KillMe();

		//�G��|������X�R�A���Z
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();

	}
}

//���񂾈ʒu�擾
void Enemy::GetPosition(double* x, double* y)
{
	//���݂̈ʒu�̎擾
	*x = this->transform_.position_.x;
	*y = this->transform_.position_.y;
}

//�ۑ������ʒu���擾
void Enemy::GetSavePosition(double* x, double* y)
{
	*x = tempx;
	*y = tempy;
}