#pragma once
#include "Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Item : public GameObject
{
    //�摜
    int hPict_[5];

public:
    //�R���X�g���N�^
    Item(GameObject* parent);

    //�f�X�g���N�^
    ~Item();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����蔻��
    void OnCollision(GameObject* pTarget);
};

