#include "PlayScene.h"
#include "../Display/Stage.h"
#include "../Object/Player.h"
#include "../Object/Enemy.h"
#include "../Object/Enemy2.h"
#include "../Display/Score.h"
#include "../Ability/Ability.h"
#include "../Display/Life.h"
#include "../Object/Item.h"
#include "../Ability/Option.h"

#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/SceneManager.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{  
	//�w�i
	//�摜�̃��[�h
	hPict_[0] = Image::Load("BackGround.png");
	assert(hPict_[0] >= 0);
	hPict_[1] = Image::Load("BackGround2.png");
	assert(hPict_[1] >= 0);

	//�񖇖ڂ̔w�i�̏����ʒu
	trans_.position_.x = 1.95;

	
	//�\��
	Instantiate<Player>(this);
	Instantiate<Option>(this);
	Instantiate<Enemy>(this);
	//Instantiate<Enemy2>(this);
	Instantiate<Stage>(this);
	Instantiate<Score>(this);
	Instantiate<Ability>(this);
	Instantiate<Life>(this);

}

//�X�V
void PlayScene::Update()
{	
	//�w�i�̃X�N���[��
	transform_.position_.x -= 0.005f;
	trans_.position_.x -= 0.005f;

	//�ꖇ�ڂ̕`�悪�I�������񖇖ڂ̌��ɖ߂�
	if (transform_.position_.x < -1.95)
	{
		transform_.position_.x = 1.95;
		Image::SetTransform(hPict_[0], transform_);
		Image::Draw(hPict_[0]);
	}

	//�񖇖ڂ̕`�悪�I�������ꖇ�ڂ̌��ɖ߂�
	if (trans_.position_.x < -1.95)
	{
		trans_.position_.x = 1.95;
		Image::SetTransform(hPict_[1], trans_);
		Image::Draw(hPict_[1]);
	}

	//�����G�����Ȃ����
	if (FindObject("Enemy") == NULL)
	{
		Instantiate<Enemy>(this);
		count++;
		
		if (count >= 5)
		{
			Instantiate<Item>(this);
			count = 0;
		}
	}
	/*if (FindObject("Enemy2") == NULL)
	{
		time++;
		
		if (time >= 60)
		{
			Instantiate<Enemy2>(this);
			count++;
		}	

		if (count >= 5)
		{
			Instantiate<Item>(this);
			count = 0;
		}
	}*/

	//�����v���C���[���Ȃ����
	if (FindObject("Player") == NULL)
	{
		//�c�@����ɍs��
		Life* pLife = (Life*)FindObject("Life");
		pLife->Stock();

		if (FindObject("Option") != NULL)
		{
			//Option��Kill
			Option* pOption = (Option*)FindObject("Option");
			pOption->KillOption();
		}	
	}

	//ESC�L�[�ŋ����I��
	if (Input::IsKeyDown(DIK_ESCAPE))
	{
		PostQuitMessage(0);
	}
}

//�`��
void PlayScene::Draw()
{
	//�ꖇ��
	Image::SetTransform(hPict_[0], transform_);
	Image::Draw(hPict_[0]);

	//�񖇖�
	Image::SetTransform(hPict_[1], trans_);
	Image::Draw(hPict_[1]);
}

//�J��
void PlayScene::Release()
{
}

//�v���C���[�̕\��
void PlayScene::AppearancePlayer()
{
	Instantiate<Player>(this);
}

//Option�̕\��
void PlayScene::AppearanceOption()
{
	Instantiate<Option>(this);
}

//�A�C�e���̕\��
void PlayScene::AppearanceItem()
{
	Instantiate<Item>(this);
}