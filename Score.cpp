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
	
	//�X�R�A�������n�߂���P�O�̈ʂɂO��\��
	if (count > 0)
	{
		hScore_[1] = hPict_[1];
	}

	//�e�ʂɐ��l�̑��
	Hundred = count % 10;
	Thousand = ((count % 1000) % 100) / 10;
	TenThousand = (count % 1000) / 100;
	OneHundredThousand = count / 1000;
	
	//�摜�f�[�^�̂P���O�̂��߁{�P�̏���
	if (count >= 1)
	{
		Hundred++;
	}
	if (count >= 10)
	{
		Thousand++;
	}
	if (count >= 100)
	{
		TenThousand++;
	}
	if (count >= 1000)
	{
		OneHundredThousand++;
	}

	//����������l�f�[�^�����ƂɃX�R�A�̕\���̕ύX
	hScore_[2] = hPict_[Hundred];
	hScore_[3] = hPict_[Thousand];
	hScore_[4] = hPict_[TenThousand];
	hScore_[5] = hPict_[OneHundredThousand];
}

void Score::Addition2()
{
	count = count + 10;

	//�X�R�A�������n�߂���P�O�̈ʂɂO��\��
	if (count > 0)
	{
		hScore_[1] = hPict_[1];
	}
	//�e�ʂɐ��l�̑��
	Thousand = ((count % 1000) % 100) / 10;
	TenThousand = (count % 1000) / 100;
	OneHundredThousand = count / 1000;

	//�摜�f�[�^�̂P���O�̂��߁{�P�̏���
	if (count >= 10)
	{
		Thousand++;
	}
	if (count >= 100)
	{
		TenThousand++;
	}
	if (count >= 1000)
	{
		OneHundredThousand++;
	}

	//����������l�f�[�^�����ƂɃX�R�A�̕\���̕ύX
	hScore_[2] = hPict_[Hundred];
	hScore_[3] = hPict_[Thousand];
	hScore_[4] = hPict_[TenThousand];
	hScore_[5] = hPict_[OneHundredThousand];
}
