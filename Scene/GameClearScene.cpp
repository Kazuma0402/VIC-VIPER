#include "GameClearScene.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"

//�R���X�g���N�^
GameClearScene::GameClearScene(GameObject* parent)
	: GameObject(parent, "GameClearScene"), hPict_(-1)
{
}

//������
void GameClearScene::Initialize()
{
	hPict_ = Image::Load("GameClear.png");
	assert(hPict_ >= 0);
}

//�X�V
void GameClearScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

//�`��
void GameClearScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void GameClearScene::Release()
{
}
