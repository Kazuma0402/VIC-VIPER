#pragma once
#include "Engine/GameObject.h"


//OptionScene�V�[�����Ǘ�����N���X
class OptionScene : public GameObject
{
	int hPict_[2];
	int nowPict_;

	bool push;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	OptionScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
