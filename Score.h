#pragma once
#include "Engine/GameObject.h"


//TitleScene�V�[�����Ǘ�����N���X
class Score : public GameObject
{
	//�摜�p�z��
	int hPict_[11];
	int hScore_[6];

	//�X�R�A���Z�p
	int count = 0;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g
	Score(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�X�R�A�̉��Z
	void Addition();
};

