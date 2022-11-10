#pragma once
#include <vector>
#include "Engine/GameObject.h"

#define SPEED 0.001f;		//�v���C���[�̉����x

//�v���C���[���Ǘ�����N���X
class Player : public GameObject
{
    //�摜
    int hPict_;

    //�����Ă邩�ǂ���
    bool life;

    //��ʊO�ɂł����̔���
    bool safe = true;

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

