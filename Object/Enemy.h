#pragma once
#include "../Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Enemy : public GameObject
{
    //�摜
    int hPict_;

    //�܂�Ԃ��n�_
    int wavePoint;

    //���񂾈ʒu�̎擾�p
    double pos_x, pos_y;

    //���񂾈ʒu��ۑ�
    double tempx, tempy;

    int num;
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
    void OnCollision(GameObject* pTarget) override;

    //�ʒu�̎擾
    void GetPosition(double* x, double* y);

    void GetSavePosition(double* x, double* y);
};

