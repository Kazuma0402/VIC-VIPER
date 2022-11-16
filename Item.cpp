#include "Item.h"
#include "Engine/Image.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Item::Item(GameObject* parent)
	:GameObject(parent, "Item")
{
}

//�f�X�g���N�^
Item::~Item()
{
}

//������
void Item::Initialize()
{
	//�摜�̃��[�h
	hPict_ = Image::Load("Point.png");
	assert(hPict_ >= 0);

	//�傫��
	transform_.scale_.y = 1.2f;

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

}

//�X�V
void Item::Update()
{
}

//�`��
void Item::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Item::Release()
{
}

//�����ɓ�������
void Item::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Player")
	{
		KillMe();
		pTarget->KillMe();
	}
}