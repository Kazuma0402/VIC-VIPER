#pragma once
#include "../Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class EnemyBullet : public GameObject
{
    //�摜
    int hPict_;

public:
    //�R���X�g���N�^
    EnemyBullet(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyBullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

