#include "Ability.h"
#include "Player.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

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

	std::string fileName3[] = {
		"NULL.png",
		"NULL_SELECT.png",
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

	for (int i = 0; i < 2; i++)
	{
		hPictNull_[i] = Image::Load(fileName3[i]);
		assert(hPictNull_[i] >= 0);
	}

	//�����ʒu
	transform_.position_.y = -0.92f;

	//�傫��
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.8f;

	//�A�r���e�B�̎g�p����̏�����
	//true = �g�p�@false = �g�p�s��
	AbilityMissile = true;
	AbilityDouble = true;
	AbilityLaser = true;

}

//�X�V
void Ability::Update()
{
	//�A�r���e�B�̓_��
	switch (count)
	{
	case 1:
		//�Y���A�r���e�B�̓_��
		hPict_[0] = hPictSelect_[0];

		//�ЂƂO�̓_����߂�
		hPict_[5] = Image::Load("HATENA.png");
		assert(hPict_[0] >= 0);

		//L����������X�s�[�h�A�b�v
		if (Input::IsKeyDown(DIK_L))
		{
			Player* pPlayer = (Player*)FindObject("Player");
			pPlayer->SpeedUp();

			//count��߂�
			count = 0;

			//�A�r���e�B�̓_��������
			hPict_[0] = Image::Load("SPEEDUP.png");
			assert(hPict_[0] >= 0);;
		}

		break;
	case 2:
		//�ЂƂO�̓_����߂�
		hPict_[0] = Image::Load("SPEEDUP.png");
		assert(hPict_[0] >= 0);

		//�A�r���e�B�̎g�p�񐔂��܂�����Ȃ�
		if (AbilityMissile == true)
		{
			//�Y���A�r���e�B�̓_��
			hPict_[1] = hPictSelect_[1];

			//L����������~�T�C���̔��ˉ\
			if (Input::IsKeyDown(DIK_L))
			{
				//�~�T�C�����łĂ�悤�ɂ���
				Player* pPlayer = (Player*)FindObject("Player");
				pPlayer->ShotMissile();

				//count��߂�
				count = 0;

				//�A�r���e�B�̎g�p���ł��Ȃ�����
				AbilityMissile = false;
				
				//�A�r���e�B���g���Ȃ��̂ł����
				if (AbilityMissile == false)
				{
					//�A�r���e�B�̕\�L�̕ύX
					hPict_[1] = hPictNull_[0];
				}
			}
		}
		else
		{
			//�Y���A�r���e�B�̓_��
			hPict_[1] = hPictNull_[1];
		}

		break;
	case 3:
		//�A�r���e�B�̎g�p���\�ł����
		if (AbilityDouble == true)
		{
			//�Y���A�r���e�B�̓_��
			hPict_[2] = hPictSelect_[2];

			//L����������~�T�C���̔��ˉ\
			if (Input::IsKeyDown(DIK_L))
			{
				//������ɒe���łĂ�悤�ɂ���
				Player* pPlayer = (Player*)FindObject("Player");
				pPlayer->ShotDouble();

				//count��߂�
				count = 0;

				//�A�r���e�B�̎g�p���ł��Ȃ�����
				AbilityDouble = false;

				//�A�r���e�B���g���Ȃ��̂ł����
				if (AbilityDouble == false)
				{
					//�A�r���e�B�̕\�L�̕ύX
					hPict_[2] = hPictNull_[0];
				}

				//���[�U�[�̎g�p���ł���悤�ɂ���
				AbilityLaser = true;

				//���[�U�[�̕\����߂�
				hPict_[3] = Image::Load("LASER.png");
				assert(hPict_[1] >= 0);
			}
		}
		else
		{
			//�A�r���e�B�̕\�L�̕ύX
			hPict_[2] = hPictNull_[1];
		}
		
		//��O�̃A�r���e�B�̎g�p�񐔂�����Ε\��
		if (AbilityMissile == true)
		{
			//�ЂƂO�̓_����߂�
			hPict_[1] = Image::Load("MISSILE.png");
			assert(hPict_[1] >= 0);
		}
		else
		{
			//�A�r���e�B�̕\�L�̕ύX
			hPict_[1] = hPictNull_[0];
		}
		break;
	case 4:
		//�A�r���e�B�̎g�p���\�ł����
		if (AbilityLaser == true)
		{
			//�Y���A�r���e�B�̓_��
			hPict_[3] = hPictSelect_[3];

			//L����������~�T�C���̔��ˉ\
			if (Input::IsKeyDown(DIK_L))
			{
				//������ɒe���łĂ�悤�ɂ���
				Player* pPlayer = (Player*)FindObject("Player");
				pPlayer->ShotLaser();

				//count��߂�
				count = 0;

				//�A�r���e�B�̎g�p���ł��Ȃ�����
				AbilityLaser = false;

				//�A�r���e�B���g���Ȃ��̂ł����
				if (AbilityLaser == false)
				{
					//�A�r���e�B�̕\�L�̕ύX
					hPict_[3] = hPictNull_[0];
				}

				//�_�u���̎g�p���ł���悤�ɂ���
				AbilityDouble = true;

				//�_�u���̕\����߂�
				hPict_[2] = Image::Load("Double.png");
				assert(hPict_[1] >= 0);
				
			}
		}
		else
		{
			//�A�r���e�B�̕\�L�̕ύX
			hPict_[3] = hPictNull_[1];
		}

		//��O�̃A�r���e�B�̎g�p�񐔂�����Ε\��
		if (AbilityDouble == true)
		{
			//�ЂƂO�̓_����߂�
			hPict_[2] = Image::Load("Double.png");
			assert(hPict_[2] >= 0);
		}
		else
		{
			//�A�r���e�B�̕\�L�̕ύX
			hPict_[2] = hPictNull_[0];
		}
		break;
	case 5:
		//�Y���A�r���e�B�̓_��
		hPict_[4] = hPictSelect_[4];

		//��O�̃A�r���e�B�̎g�p�񐔂�����Ε\��
		if (AbilityDouble == true)
		{
			//�ЂƂO�̓_����߂�
			hPict_[3] = Image::Load("Laser.png");
			assert(hPict_[3] >= 0);
		}
		else
		{
			//�A�r���e�B�̕\�L�̕ύX
			hPict_[3] = hPictNull_[0];
		}
		break;
	case 6:
		//�Y���A�r���e�B�̓_��
		hPict_[5] = hPictSelect_[5];

		//�ЂƂO�̓_����߂�
		hPict_[4] = Image::Load("OPTION.png");
		assert(hPict_[0] >= 0);
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

	//7�ȏ�Ȃ�count��1�ɖ߂�
	if (count >= 7)
	{
		count = 1;
	}
}

//���������ۂ̃J�E���g�̏�����
void Ability::CountReset()
{
	count = 1;
}

//���������ۂ̃A�r���e�B�g�p�̕���
void Ability::AbilityHeel()
{
	AbilityMissile = true;
	AbilityDouble = true;
}

//���������ۂ̃A�r���e�B�\���̃��Z�b�g
void Ability::AbilityReset()
{
	//�摜�f�[�^
	std::string fileName[] = {
		"SPEEDUP_SELECT.png",
		"MISSILE.png",
		"DOUBLE.png",
		"LASER.png",
		"OPTION.png",
		"HATENA.png",
	};

	//�摜�̃��[�h
	for (int i = 0; i < 6; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}
}