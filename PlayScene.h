#pragma once
#include "Engine/SceneManager.h"

class PlayScene : public GameObject
{
public:
	//�R���X�g���N�^
	//����:Parent�@�e�I�u�W�F�N�g(SceneManager)
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void  Update() override;

	//�`��
	void Draw() override;

	//���
	void Release() override;
};

