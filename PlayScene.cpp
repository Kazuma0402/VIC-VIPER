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
	Instantiate<Player>(this);
}

//�X�V
void PlayScene::Update()
{	
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
