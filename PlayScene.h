#pragma once
#include "Engine/GameObject.h"

#define SCROLL_SPEED 0.001f;

//PlayScene�V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
	int hPict_[2];
	
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
};

