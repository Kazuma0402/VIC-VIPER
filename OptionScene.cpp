#include "OptionScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//�R���X�g���N�^
OptionScene::OptionScene(GameObject* parent)
	: GameObject(parent, "OptionScene"), hPict_(-1)
{
}

//������
void OptionScene::Initialize()
{
	hPict_ = Image::Load("Rule.png");
	assert(hPict_ >= 0);
}

//�X�V
void OptionScene::Update()
{
	if (Input::IsKey(DIK_ESCAPE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

//�`��
void OptionScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void OptionScene::Release()
{
}