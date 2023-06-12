#pragma once
#include "../Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Enemy2 : public GameObject
{
    //�摜
    int hPict_;

    //�܂�Ԃ��n�_
    int wavePoint;

    //�v���C���[�̈ʒu��ۑ�
    double pos_x, pos_y;

    //���񂾐�
    int KillCount;
public:
    //�R���X�g���N�^
    Enemy2(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy2();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����蔻��
    void OnCollision(GameObject* pTarget) override;

    //�X�R�A�p
    void KillCountpuls();

    //�v���C���[�̈ʒu�̎擾
    void GetPlayerPosition(double* x, double* y);
};

