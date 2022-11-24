#include "Ability.h"
#include "Engine/Image.h"

//�R���X�g���N�^
Ability::Ability(GameObject* parent)
	:GameObject(parent, "Ability")
{
}

//�f�X�g���N�^
Ability::~Ability()
{
}

//������
void Ability::Initialize()
{
	//�摜�f�[�^
	std::string fileName[] = {
		"SPEEDUP.png",
		"MISSILE.png",
		"DOUBLE.png",
		"LASER.png",
		"OPTION.png",
		"HATENA.png",
	};

	std::string fileName2[] = {
		"SPEEDUP_SELECT.png",
		"MISSILE_SELECT.png",
		"DOUBLE_SELECT.png",
		"LASER_SELECT.png",
		"OPTION_SELECT.png",
		"HATENA_SELECT.png",
	};

	//�摜�̃��[�h
	for (int i = 0; i < 6; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}

	for (int i = 0; i < 6; i++)
	{
		hPictSelect_[i] = Image::Load(fileName2[i]);
		assert(hPictSelect_[i] >= 0);
	}

	//�����ʒu
	transform_.position_.y = -0.92f;

	//�傫��
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.8f;
}

//�X�V
void Ability::Update()
{
	switch (count)
	{
	case 1:
		hPict_[0] = hPictSelect_[0];
		break;
	case 2:
		hPict_[1] = hPictSelect_[1];
		hPict_[0] = Image::Load("SPEEDUP.png");
		assert(hPict_[0] >= 0);
		break;
	case 3:
		hPict_[2] = hPictSelect_[2];
		break;
	case 4:
		hPict_[3] = hPictSelect_[3];
		break;
	case 5:
		hPict_[4] = hPictSelect_[4];
		break;
	case 6:
		hPict_[5] = hPictSelect_[5];
		break;
	}
}

//�`��
void Ability::Draw()
{
	for (int i = 0; i < 6; i++)
	{
		transform_.position_.x = 0.2f * i - 0.5f;
		Image::SetTransform(hPict_[i], transform_);
		Image::Draw(hPict_[i]);
	}

}

//�J��
void Ability::Release()
{
}

//�J�E���g�̉��Z
void Ability::Addition()
{
	count++;

	if (count > 6)
	{
		count = 1;
	}
}