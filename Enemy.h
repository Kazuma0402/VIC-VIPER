#pragma once
#include "Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Enemy : public GameObject
{
    //�摜
    int hPict_;

public:
    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

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
