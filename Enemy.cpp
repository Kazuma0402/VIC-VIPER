#include "Enemy.h"
#include "EnemyBullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hPict_(-1)
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
	hPict_ = Image::Load("Enemy.png");
	assert(hPict_ >= 0);

	//�����ʒu
	transform_.position_.x = 0.46;

	//�G�̑傫��
	transform_.scale_.x = 0.3f;
	transform_.scale_.y = 0.3f;

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3( 0.0f, 0.0f, 0.0f), 0.05f);
	AddCollider(collision);
}

//�X�V
void Enemy::Update()
{
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