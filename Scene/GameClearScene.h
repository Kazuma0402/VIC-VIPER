#pragma once
#include "../Engine/GameObject.h"

//GameClearScene�V�[�����Ǘ�����N���X
class GameClearScene : public GameObject
{
	//�摜�p
	int hPict_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameClearScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

