#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Global.h"

//�v���C���[���Ǘ�����N���X
class Option : public GameObject
{
    //�摜�p
    int hPict_[4];

    //�����Ă��邩�̔���
    bool alive;

    //���o�Ă���I�v�V�����̐�
    int cnt;

    //���W�̋L�^�z��
    double cx[4];
    double cy[4];

    //�e�X�̈ʒu�p
    Transform pos1_;
    Transform pos2_;
    Transform pos3_;
    Transform pos4_;

    //�e�̃N�[���^�C��
    int time;
    int time2;
    int time3;
    int time4;

    //�A�r���e�B�̗L��
    bool missile_;
    bool double_;
    bool laser_;

    //���ˑ��x
    float speed;

    //���[�U�[�̔��ˈʒu�̕␳
    Transform trans_1;
    Transform trans_2;
    Transform trans_3;
    Transform trans_4;
    Transform trans_;

public:
    //�R���X�g���N�^
    Option(GameObject* parent);

    //�f�X�g���N�^
    ~Option();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�v���C���[�̈ʒu�̎擾
    void GetPlayerPosition20();
    //�v���C���[�̈ʒu�̎擾
    void GetPlayerPosition40();
    //�v���C���[�̈ʒu�̎擾
    void GetPlayerPosition60();
    //�v���C���[�̈ʒu�̎擾
    void GetPlayerPosition80();

    //�I�v�V�����̕\��
    void AddOption();

    //�v���C���[�����񂾎��̃��Z�b�g
    void CountReset();

    //�v���C���[�����񂾂Ƃ��ɃI�v�V����������
    void KillOption();

    //���A�r���e�B
    //�~�T�C���̔���
    void ShotMissile();

    //�e��������֔���
    void ShotDouble();

    //�e�����[�U�[�ɕύX
    void ShotLaser();
};