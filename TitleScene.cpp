#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), hPict_(-1)
{
}

//������
void TitleScene::Initialize()
{
	hPict_ = Image::Load("Assets/Title.jpg");
	assert(hPict_ >= 0);
}

//�X�V
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//�`��
void TitleScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void TitleScene::Release()
{
}
