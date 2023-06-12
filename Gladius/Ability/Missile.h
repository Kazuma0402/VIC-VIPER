#pragma once
#include "../Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Missile : public GameObject
{
    //�摜
    int hPict_[2];
    int hPictNow_;

public:
    //�R���X�g���N�^
    Missile(GameObject* parent);

    //�f�X�g���N�^
    ~Missile();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

};



