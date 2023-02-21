#include "Double.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/SphereCollider.h"

//�R���X�g���N�^
Double::Double(GameObject* parent)
	:GameObject(parent, "Double"), hPict_(-1)
{
}

//�f�X�g���N�^
Double::~Double()
{
}

//������
void Double::Initialize()
{
	//�摜�̃��[�h
	hPict_ = Image::Load("Bullet.png");
	assert(hPict_ >= 0);

	//�����蔻��
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.01f);
	AddCollider(collision);

	//��]
	transform_.rotate_.z = 30.0f;
}

//�X�V
void Double::Update()
{
	transform_.position_.x += 0.06f;
	transform_.position_.y += 0.06f;

	if (transform_.position_.x >= 0.95f)
	{
		KillMe();
	}
}

//�`��
void Double::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Double::Release()
{
}