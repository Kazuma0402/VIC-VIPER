#include "Stage.h"
#include "../Engine/Image.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
	: GameObject(parent, "Stage")
{
}

//������
void Stage::Initialize()
{
	//�摜�f�[�^
	std::string fileName[] = {
		"Stage1-1.png",
		"Stage1-2.png",
		"Stage1-3.png",
		"Stage1-4.png",
	};

	//�摜�̃��[�h
	for (int i = 0; i < 4; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}

	//�����ʒu
	trans1_.position_.x = 10.0f;
	trans2_.position_.x = 11.95f;
	trans3_.position_.x = 13.95f;
	trans4_.position_.x = 15.85f;
}

//�X�V
void Stage::Update()
{
	//�X�e�[�W�̈ړ�
	trans1_.position_.x -= 0.003f;
	trans2_.position_.x -= 0.003f;
	trans3_.position_.x -= 0.003f;
	trans4_.position_.x -= 0.003f;
}

//�`��
void Stage::Draw()
{
	Image::SetTransform(hPict_[0], trans1_);
	Image::Draw(hPict_[0]);
	Image::SetTransform(hPict_[1], trans2_);
	Image::Draw(hPict_[1]);
	Image::SetTransform(hPict_[2], trans3_);
	Image::Draw(hPict_[2]);
	Image::SetTransform(hPict_[3], trans4_);
	Image::Draw(hPict_[3]);
}

//�J��
void Stage::Release()
{
}
