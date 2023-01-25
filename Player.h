#pragma once
#include "Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Player : public GameObject
{
    //�摜
    int hPict_;

    //�@�̂̃X�s�[�h
    float speed;

    //�e�̈ʒu�̕␳
    Transform trans_;

    //�ˌ��̃N�[���^�C���p
    int time;
    //�~�T�C���̃N�[���^�C���p
    int time2;
    //��������˂̃N�[���^�C���p
    int time3;
    //���[�U�[�̃N�[���^�C���p
    int time4;

    //�A�r���e�B�̗L��
    bool missile_;
    bool double_;
    bool laser_;

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

    //�����蔻��
    void OnCollision(GameObject* pTarget);

    //���A�r���e�B�̊J����
    //�X�s�[�h�A�b�v
    void SpeedUp();

    //�~�T�C���̔���
    void ShotMissile();

    //�e��������֔���
    void ShotDouble();

    //�e�����[�U�[�ɕύX
    void ShotLaser();

    //�@�̂��ϐg
    void Change();
};

