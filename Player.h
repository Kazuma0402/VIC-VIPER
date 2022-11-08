#pragma once
#include "Engine/GameObject.h"

//�v���g�^�C�v�錾
const int WINDOW_WIDTH = GetSystemMetrics(SM_CXSCREEN);			//�E�B���h�E�̕�
const int WINDOW_HEIGHT = GetSystemMetrics(SM_CYSCREEN);		//�E�B���h�E�̍���

//�v���C���[���Ǘ�����N���X
class Player : public GameObject
{
    int hModel_;

public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

