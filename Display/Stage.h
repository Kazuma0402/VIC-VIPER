#pragma once
#include "../Engine/GameObject.h"

//Stage�V�[�����Ǘ�����N���X
class Stage : public GameObject
{
	//�摜�p
	int hPict_[4];

	Transform trans1_;
	Transform trans2_;
	Transform trans3_;
	Transform trans4_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

