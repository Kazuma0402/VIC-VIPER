#include "EnemyBullet.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Camera.h"
#include "../Engine/SphereCollider.h"

//�R���X�g���N�^
EnemyBullet::EnemyBullet(GameObject* parent)
	:GameObject(parent, "EnemyBullet"), hPict_(-1)
{
}

//�f�X�g���N�^
EnemyBullet::~EnemyBullet()
{
}

//������
void EnemyBullet::Initialize()
{
	hPict_ = Image::Load("Bullet.png");
	assert(hPict_ >= 0);

	//�����蔻��
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.01f);
	AddCollider(collision);
}

//�X�V
void EnemyBullet::Update()
{
	transform_.position_.x -= 0.0007f;

	if (transform_.position_.x <= -0.95f)
	{
		KillMe();
	}
}

//�`��
void EnemyBullet::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void EnemyBullet::Release()
{
}
