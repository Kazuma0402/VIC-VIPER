#include "PlayScene.h"
#include "Player.h"
#include "Engine/Image.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent) : GameObject(parent, "PlayScene"), hPict_(-1)
{
}

//������
void PlayScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Shinwa.jpg");
	assert(hPict_ >= 0);

	Instantiate<Player>(this);
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//���
void PlayScene::Release()
{
}
