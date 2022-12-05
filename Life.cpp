#include "Life.h"
#include "Ability.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "PlayScene.h"

//�R���X�g���N�^
Life::Life(GameObject* parent)
	:GameObject(parent, "Life")
{
}

//�f�X�g���N�^
Life::~Life()
{
}

//������
void Life::Initialize()
{
	//�c�@�̕\��
	std::string fileName = "VICVIPER.png";
	for (int i = 0; i < 3; i++)
	{
		hPictCon_[i] = Image::Load(fileName);
	}

	//�c�@�̏����ʒu
	transform_.position_.x = -0.7f;
	transform_.position_.y = 0.92f;

	//�c�@�̕\���̑傫��
	transform_.scale_.x = 0.15;
	transform_.scale_.y = 0.15;

}

//�X�V
void Life::Update()
{
}

//�`��
void Life::Draw()
{
	//�c�@�̕\��
	for (int i = 1; i < 3; i++)
	{
		transform_.position_.x = 0.07f * i - 0.7f;
		Image::SetTransform(hPictCon_[i - 1], transform_);
		Image::Draw(hPictCon_[i - 1]);
	}
}

//�J��
void Life::Release()
{
}

//�c�@����
void Life::Stock()
{
	//�c�@�̕\��������
	hPictCon_[con] = NULL;

	//�c�@������Ȃ�\��
	if (life > 0)
	{
		//�c�@�̌���
		life--;

		con++;

		//�v���C���[�̕\��
		PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");
		pPlayScene->AppearancePlayer();

		//-----�A�r���e�B�N���X�ɂ���-----
		Ability* pAbility = (Ability*)FindObject("Ability");

		//�A�r���e�B�̓_���̏�����
		pAbility->CountReset();

		//�A�r���e�B�̎g�p�񐔂̕���
		pAbility->AbilityHeel();
	}
	//�c�@���Ȃ��Ȃ猋�ʉ��
	else
	{
		//�Q�[�����ʉ�ʂւ̑J��
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
	}
}