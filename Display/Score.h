#pragma once
#include "../Engine/GameObject.h"

class Score : public GameObject
{
	//�摜�p�z��
	int hPict_[11];
	int hScore_[6];

	//�X�R�A���Z�p
	int count = 0;

	//�X�R�A�̈�
	int Hundred;				//�P�O�O�̈�
	int Thousand;				//�P�O�O�O�̈�
	int TenThousand;			//�P�O�O�O�O�̈�
	int OneHundredThousand;		//�P�O�O�O�O�O�̈�

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

	//�X�R�A�̉��Z(+100)
	void Addition();

	//�X�R�A�̉��Z(+1000)
	void Addition2();
};