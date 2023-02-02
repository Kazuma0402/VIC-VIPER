#include "Enemy.h"
#include "EnemyBullet.h"
#include "Player.h"
#include "Score.h"
#include "PlayScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

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
	transform_.position_.y = (float)(rand() % 180 - 110) / 100;
	
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
		//�G��������
		KillMe();

		//�G��|������X�R�A���Z
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();

	}
}

void Enemy::KillCountpuls()
{
	//�L���J�E���g�̉��Z
	KillCount++;

	//�؂�J�E���g����萔�ȏ�Ȃ�A�C�e���̕\��
	if (KillCount >= 5)
	{
		//�A�C�e���̕\��
		PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");
		pPlayScene->AppearanceItem();

		//�L���J�E���g�̃��Z�b�g
		KillCount == 0;
	}
}