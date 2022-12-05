#include "Laser.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
Laser::Laser(GameObject* parent)
	:GameObject(parent, "Laser"), hPict_(-1)
{
}

//�f�X�g���N�^
Laser::~Laser()
{
}

//������
void Laser::Initialize()
{
	hPict_ = Image::Load("LaserBullet.png");
	assert(hPict_ >= 0);

	//�����蔻��
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.1f, 0.1f, 0.1f));
	AddCollider(collision);
}

//�X�V
void Laser::Update()
{
	transform_.position_.x += 0.05f;

	if (transform_.position_.x >= 2.0f)
	{
		KillMe();
	}
}

//�`��
void Laser::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Laser::Release()
{
}
