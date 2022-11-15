#include "Enemy.h"
#include "EnemyBullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy")
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
	//�G�P
	hPict_ = Image::Load("Enemy.png");
	assert(hPict_ >= 0);

	//�G�P
	//�����ʒu
	transform_.position_.x = 0.8f;
	transform_.position_.y = 0.4f;
	
	//�G�̑傫��
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3( 0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

}

//�X�V
void Enemy::Update()
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
		KillMe();
		pTarget->KillMe();
	}
}