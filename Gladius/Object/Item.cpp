#include "Item.h"
#include "../Engine/Image.h"
#include "../Ability/Ability.h"
#include "Enemy.h"

//�R���X�g���N�^
Item::Item(GameObject* parent)
	:GameObject(parent, "Item"), hPict_(-1)
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

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

	//�G�̎��񂾈ʒu�̎擾
	GetPosition();
}

//�X�V
void Item::Update()
{
	transform_.position_.x -= 0.005f;
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
		//�A�C�e����������
		KillMe();

		//�Ƃ�����\�͂̓_��
		Ability* pAbility = (Ability*)FindObject("Ability");
		pAbility->Addition();
	}
}

//�ʒu�̎擾
void Item::GetPosition()
{
	double tempx, tempy;

	Enemy* pEnemy = (Enemy*)FindObject("Enemy");
	pEnemy->GetSavePosition(&tempx, &tempy);

	transform_.position_.x = tempx;
	transform_.position_.y = tempy;

}