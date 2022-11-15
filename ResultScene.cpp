#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"

//�R���X�g���N�^
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"), hPict_(-1)
{
}

//������
void ResultScene::Initialize()
{
	hPict_ = Image::Load("Result.png");
	assert(hPict_ >= 0);
}

//�X�V
void ResultScene::Update()
{
}

//�`��
void ResultScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void ResultScene::Release()
{
}
