#include "Enemy.h"
#include "EnemyBullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Score.h"
#include "PlayScene.h"

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
	transform_.position_.y = (rand() % 180 - 90) / 100;
	
	//�傫��
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3( 0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

	//�E�F�[�u�|�C���g�̏�����
	wavePoint = 0;

	//�L���J�E���g�̏�����
	KillCount = 0;
}

//�X�V
void Enemy::Update()
{
	//�ړ����x
	transform_.position_.x -= 0.005f;
	
	if (wavePoint == 0)
	{
		transform_.position_.y -= 0.01f;

		if (transform_.position_.y <= -0.5f)
		{
			wavePoint = 1;
		}
	}
	if (wavePoint == 1)
	{
		transform_.position_.y += 0.01f;

		if (transform_.position_.y >= 0.5f)
		{
			wavePoint = 0;
		}
	}

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
		//�G��������
		KillMe();

		//�e��������
		pTarget->KillMe();

		//�G��|������X�R�A���Z
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();

	}
}

void Enemy::KillCountpuls()
{
	//�L���J�E���g�̉��Z
	KillCount++;

	if (KillCount >= 5)
	{
		PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");
		pPlayScene->AppearanceItem();

		KillCount == 0;
	}
}

