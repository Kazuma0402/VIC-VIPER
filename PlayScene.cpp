#include "PlayScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Ability.h"
#include "Life.h"
#include "Item.h"

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
	Instantiate<Score>(this);
	Instantiate<Ability>(this);
	Instantiate<Life>(this);
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);

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

	if (FindObject("Enemy") == NULL)
	{
		Instantiate<Enemy>(this);
		count++;
	}
	if (count >= 1 && count % 5 == 0)
	{
		Instantiate<Item>(this);
		count = 0;
	}

	//�����v���C���[���Ȃ����
	if (FindObject("Player") == NULL)
	{
		//�c�@����ɍs��
		Life* pLife = (Life*)FindObject("Life");
		pLife->Stock();
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
void PlayScene::Appearance()
{
	Instantiate<Player>(this);
}