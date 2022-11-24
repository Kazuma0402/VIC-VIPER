#pragma once
#include "Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Life : public GameObject
{
    //�摜
    int hPictCon_[3];

    //�c�@
    int life = 2;

    //���S��
    int con = 0;

public:
    //�R���X�g���N�^
    Life(GameObject* parent);

    //�f�X�g���N�^
    ~Life();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�c�@����
    void Stock();
};

