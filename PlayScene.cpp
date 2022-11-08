#include "PlayScene.h"
#include "Engine/Image.h"
#include "Player.h"

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
