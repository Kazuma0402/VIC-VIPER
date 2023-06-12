#pragma once
#include "../Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Boss : public GameObject
{
    //�摜
    int hPict_;

    //�̗�
    int hp;

    //�㉺�ړ��ւ̈ړ�
    bool move;

    //�܂�Ԃ��n�_
    bool wavePoint;

    //�e�̔��˃N�[���^�C��
    int time;
public:
    //�R���X�g���N�^
    Boss(GameObject* parent);

    //�f�X�g���N�^
    ~Boss();

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

