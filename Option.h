#pragma once
#include "Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Option : public GameObject
{
    //�摜
    int hPict_[2];
    int hPictNow_;

public:
    //�R���X�g���N�^
    Option(GameObject* parent);

    //�f�X�g���N�^
    ~Option();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

};