#include "Score.h""
#include "Engine/Image.h"

//�R���X�g���N�^
Score::Score(GameObject* parent)
	: GameObject(parent, "Score")
{
}

//������
void Score::Initialize()
{
	//�摜�f�[�^
	std::string fileName[] = {
		"Clear.png",
		"0.png",
		"1.png",
		"2.png",
		"3.png",
		"4.png",
		"5.png",
		"6.png",
		"7.png",
		"8.png",
		"9.png",
	};

	//�摜�̃��[�h
	for (int i = 0; i < 11; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}

	//�X�R�A�摜�̏����\��
	for (int i = 0; i < 6; i++)
	{
		//�X�R�A���O����X�^�[�g������
		if (i == 0)
		{
			hScore_[i] = hPict_[1];
		}
		else
		{
			hScore_[i] = hPict_[0];
		}	
	}

	//�����ʒu
	transform_.position_.x = -0.4f;
	transform_.position_.y = 0.92f;
}

//�X�V
void Score::Update()
{
}

//�`��
void Score::Draw()
{
	for (int i = 0; i < 6; i++)
	{
		transform_.position_.x = -0.05f * i - 0.1f;
		Image::SetTransform(hScore_[i], transform_);
		Image::Draw(hScore_[i]);
	}
	
}

//�J��
void Score::Release()
{
}

//�X�R�A���Z
void Score::Addition()
{
	count++;
	if (count >= 10)
	{
		count = 2;
		hScore_[1] = hPict_[count];
	}
	else
	{
		hScore_[1] = hPict_[count];
	}
}
