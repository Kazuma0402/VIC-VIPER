#include "Boss.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Score.h"
#include "PlayScene.h"

//�R���X�g���N�^
Boss::Boss(GameObject* parent)
	:GameObject(parent, "Boss"), hPict_(-1)
{
}

//�f�X�g���N�^
Boss::~Boss()
{
}

//������
void Boss::Initialize()
{
	//�摜�̃��[�h
	hPict_ = Image::Load("Boss.png");
	assert(hPict_ >= 0);

	//�����ʒu
	transform_.position_.x = 1.0f;
	transform_.position_.y = 0.4f;

	//�傫��
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//�����蔻��i�ہj
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

}

//�X�V
void Boss::Update()
{
	//�ړ����x
	transform_.position_.x -= 0.01f;

	if (transform_.position_.x <= -1.00f)
	{
		KillMe();
	}
}

//�`��
void Boss::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Boss::Release()
{
}

//�����ɓ�������
void Boss::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Bullet")
	{
		//�G��������
		KillMe();

		//�e��������
		pTarget->KillMe();

		//�G��|������X�R�A���Z
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();
	}
}
