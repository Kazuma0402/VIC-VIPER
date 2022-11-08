#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
	hModel_ = Model::Load("Assets/BoxBrock.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Player::Update()
{
	//�ړ�����
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.01;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.01;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.01;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.01;
	}

	//��ʊO�ɏo�Ȃ��悤�ɂ���
	if (transform_.position_.y > 7.4f)
	{
		transform_.position_.y = 7.4f;
	}
	if (transform_.position_.y < -7.4f)
	{
		transform_.position_.y = -7.4f;
	}
	if (transform_.position_.x < -10.0f)
	{
		transform_.position_.x = -10.0f;
	}
	if (transform_.position_.x > 10.0f)
	{
		transform_.position_.x = 10.0f;
	}
}

//�`��
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}
