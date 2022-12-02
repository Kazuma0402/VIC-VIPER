#pragma once
#include "Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Ability : public GameObject
{
    //�摜
    int hPict_[6];              //�\���摜
    int hPictSelect_[6];        //�I�𒆂̉摜
    int hPictNull_[2];          //�g�p�񐔂̂Ȃ����̉摜

    //�摜�̕\��
    int count;

    //�A�r���e�B�̎g�p��
    int AbilityCountMissile;        //�~�T�C���̎g�p��
    int AbilityCountDouble;         //�_�u���V���b�g�̎g�p��
public:
    //�R���X�g���N�^
    Ability(GameObject* parent);

    //�f�X�g���N�^
    ~Ability();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�J�E���g�̉��Z
    void Addition();

    //���������ۂ̃A�r���e�B�̓_���̏�����
    void CountReset();

    //���������ۂ̃A�r���e�B�̎g�p�񐔂̉�
    void AbilityCountHeel();
};

