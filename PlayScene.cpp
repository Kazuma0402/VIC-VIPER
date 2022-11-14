#include "PlayScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Player.h"
#include "Enemy.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{  
	hPict_[0] = Image::Load("BackGround.png");
	assert(hPict_[0] >= 0);
	hPict_[1] = Image::Load("BackGround2.png");
	assert(hPict_[1] >= 0);

	trans_.position_.x = 1.95;

	Instantiate<Player>(this);

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

	//ESC�ŏI��
	if (Input::IsKeyDown(DIK_ESCAPE))
	{
		PostQuitMessage(0);
	}

	time++;
	if (time >= 15 && count < 4)
	{
		Instantiate<Enemy>(this);
		time = 0;
		count++;
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
