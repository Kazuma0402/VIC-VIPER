#pragma once
#include "Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Double : public GameObject
{
    //�摜
    int hPict_;

public:
    //�R���X�g���N�^
    Double(GameObject* parent);

    //�f�X�g���N�^
    ~Double();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

