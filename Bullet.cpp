#include "Bullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hPict_(-1)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
	hPict_ = Image::Load("Bullet.png");
	assert(hPict_ >= 0);

	//�����蔻��
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.01f);
	AddCollider(collision);
}

//�X�V
void Bullet::Update()
{
	transform_.position_.x += 0.003f;

	if (transform_.position_.x >= 0.95f)
	{
		KillMe();
	}
}

//�`��
void Bullet::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Bullet::Release()
{
}
