#include "PlayScene.h"
#include "Engine/Image.h"
#include "Player.h"
#include "Engine/Input.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), hPict_(-1)
{
}

//������
void PlayScene::Initialize()
{

	hPict_ = Image::Load("Assets/Shinwa.jpg");
	assert(hPict_ >= 0);

	Instantiate<Player>(this);
}

//�X�V
void PlayScene::Update()
{
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
}

//�`��
void PlayScene::Draw()
{
	/*Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);*/
}

//�J��
void PlayScene::Release()
{
}
