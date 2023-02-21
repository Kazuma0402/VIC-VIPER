#pragma once
#include "../Engine/GameObject.h"

//PlayScene�V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
	//�摜�p�̔z��
	int hPict_[2];

	int time = 0;
	int count = 0;

	//�摜�̕`��ʒu�p
	Transform trans_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�v���C���[�̕\��
	void AppearancePlayer();

	//�A�C�e���̕\��
	void AppearanceItem();
};

