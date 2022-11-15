#include "Enemy2.h"
#include "EnemyBullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Score.h";

//�R���X�g���N�^
Enemy2::Enemy2(GameObject* parent)
	:GameObject(parent, "Enemy")
{
}

//�f�X�g���N�^
Enemy2::~Enemy2()
{
}

//������
void Enemy2::Initialize()
{
	//�G�P
	hPict_ = Image::Load("Enemy.png");
	assert(hPict_ >= 0);

	//�G�P
	//�����ʒu
	transform_.position_.x = 1.8f;
	transform_.position_.y = -0.4f;

	//�G�̑傫��
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);


}

//�X�V
void Enemy2::Update()
{
	//�ړ����x
	transform_.position_.x -= 0.01f;

	////���Ԃ̉��Z
	//time++;

	////��莞�Ԃŋ��𔭎�
	//if (time >= 1000)
	//{
	//	EnemyBullet* pEnemyBullet = Instantiate<EnemyBullet>(GetParent());
	//	pEnemyBullet->SetPosition(transform_.position_);

	//	//�J�E���g���Ԃ̃��Z�b�g
	//	time = 0;
	//}
}

//�`��
void Enemy2::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Enemy2::Release()
{
}

//�����ɓ�������
void Enemy2::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Bullet")
	{
		KillMe();
		pTarget->KillMe();

		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();
	}
}