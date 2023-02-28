#include "Enemy.h"
#include "Player.h"
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
	//transform_.position_.y = (float)(rand() % 180 - 110) / 100;
	
	//�傫��
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3( 0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

	//�E�F�[�u�|�C���g�̏�����
	wavePoint = 0;
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
		//���񂾈ʒu�̕ۑ�
		GetPosition(&pos_x, &pos_y);

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
		//���񂾈ʒu�̕ۑ�
		GetPosition(&pos_x, &pos_y);

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
		//���񂾈ʒu�̕ۑ�
		GetPosition(&pos_x, &pos_y);

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
		//���񂾈ʒu�̕ۑ�
		GetPosition(&pos_x, &pos_y);

		//�G��������
		KillMe();

		//�G��|������X�R�A���Z
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();

	}
}

//�ʒu�擾
void Enemy::GetPosition(double* x, double* y)
{
	//���݂̈ʒu�̎擾
	*x = this->transform_.position_.x;
	*y = this->transform_.position_.y;
}

//���񂾈ʒu���A�C�e���֑���
void Enemy::SendOldPosition(double* x, double* y)
{
	*x = pos_x;
	*y = pos_y;
}