#include "Life.h"
#include "../Ability/Ability.h"
#include "../Ability/Option.h"

#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Scene/PlayScene.h"

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
	//�摜�̃��[�h
	std::string fileName = "Life.png";
	for (int i = 0; i < 3; i++)
	{
		hPictCon_[i] = Image::Load(fileName);
	}

	//�c�@�̏����ʒu
	transform_.position_.x = -0.7f;
	transform_.position_.y = 0.92f;

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
		transform_.position_.x = 0.1f * i - 0.7f;
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
	hPictCon_[con] = -1;

	//�c�@������Ȃ�\��
	if (life > 0)
	{
		//�c�@�̌���
		life--;

		con++;

		//PlayScene�̃C���X�^���X�Ăяo��
		PlayScene* pPlayScene = (PlayScene*)FindObject("PlayScene");

		//�v���C���[�̕\��
		pPlayScene->AppearancePlayer();

		//-----�A�r���e�B�N���X�ɂ���-----
		Ability* pAbility = (Ability*)FindObject("Ability");

		//�A�r���e�B�̓_���̏�����
		pAbility->CountReset();

		//�A�r���e�B�̎g�p�񐔂̕���
		pAbility->AbilityHeel();

		//�A�r���e�B�\���̃��Z�b�g
		pAbility->AbilityReset();

		//�I�v�V�������̃A�r���e�B�̉�
		Option* pOption = (Option*)FindObject("Option");
		pOption->AbilityHeel();
	}
	//�c�@���Ȃ��Ȃ猋�ʉ��
	else
	{
		//�Q�[�����ʉ�ʂւ̑J��
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
	}
}