#pragma once
#include "../Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Player : public GameObject
{
    //�摜
    int hPict_;

    int hPicts_;
    Transform t_;

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

    //�R�i�~�R�}���h�p�i���j
    int cnt;

    //�ړ����Ă��邩���Ă��Ȃ���
    bool angle;

    //���W�p�z��
    double cx[81];
    double cy[81];
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

    //�ʒu�̎擾
    void GetPosition(double *x, double *y);

    //���@�ɐ̂̈ʒu(20�O)�̎擾
    void GetOldPosition20(double *x, double *y);
    //���@�ɐ̂̈ʒu(40�O)�̎擾
    void GetOldPosition40(double* x, double* y);
    //���@�ɐ̂̈ʒu(60�O)�̎擾
    void GetOldPosition60(double* x, double* y);
    //���@�ɐ̂̈ʒu(80�O)�̎擾
    void GetOldPosition80(double* x, double* y);

    //���񂾎��ɍ��W�L�^�̔z����������ɂ���
    void ResetPosition();

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