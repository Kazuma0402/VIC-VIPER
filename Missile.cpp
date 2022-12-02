#include "Missile.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Missile::Missile(GameObject* parent)
	:GameObject(parent, "Missile"), hPictNow_(-1)
{
}

//�f�X�g���N�^
Missile::~Missile()
{
}

//������
void Missile::Initialize()
{
	//�摜�f�[�^
	std::string fileName[] = {
		"Missile1.png",
		"Missile2.png",
	};

	//�摜�̃��[�h
	for (int i = 0; i < 2; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}
	
	hPictNow_ = Image::Load("Missile1.png");
	assert(hPictNow_ >= 0);

	//�����蔻��
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0f, 0, 0), 0.01f);
	AddCollider(collision);

}

//�X�V
void Missile::Update()
{
	transform_.position_.x += 0.01f;
	transform_.position_.y -= 0.03f;

	//��萔�ȏ�s���Ə�����
	if (transform_.position_.x >= 0.95f || transform_.position_.y <= -0.95f)
	{
		KillMe();
	}
}

//�`��
void Missile::Draw()
{
	Image::SetTransform(hPictNow_, transform_);
	Image::Draw(hPictNow_);
}

//�J��
void Missile::Release()
{
}
