#pragma once
#include "../Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Laser : public GameObject
{
    //�摜
    int hPict_;

public:
    //�R���X�g���N�^
    Laser(GameObject* parent);

    //�f�X�g���N�^
    ~Laser();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

