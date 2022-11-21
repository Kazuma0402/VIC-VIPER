#include "PlayScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Score.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
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

	//�c�@�̕\��
	std::string fileName = "VICVIPER.png";
	for (int i = 0; i < 3; i++)
	{
		hPictCon_[i] = Image::Load(fileName);
	}

	//�c�@�̏����ʒu
	transcon_.position_.x = -0.7f;
	transcon_.position_.y = 0.92f;
	//�c�@�̕\���̑傫��
	transcon_.scale_.x = 0.15;
	transcon_.scale_.y = 0.15;
	
	//�v���C���[�̕\��
	Instantiate<Score>(this);
	Instantiate<Player>(this);
	Instantiate<Item>(this);

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

	if (Input::IsKeyDown(DIK_ESCAPE))
	{
		PostQuitMessage(0);
	}

	//��莞�ԂœG���o��������
	time++;
	if (time >= 20 && count < 4)
	{
		Instantiate<Enemy>(this);
		Instantiate<Enemy2>(this);
		time = 0;
		count++;
	}
	if (time >= 210 && count  >= 4)
	{
		time = 0;
		count = 0;
	}


	//�����v���C���[���Ȃ����
	if (FindObject("Player") == NULL)
	{
		//�c�@�̕\��������
		hPictCon_[con] = NULL;

		//�c�@������Ȃ�\��
		if (life > 0)
		{
			Instantiate<Player>(this);
			life--;
			con++;
		}
		//�c�@���Ȃ��Ȃ猋�ʉ��
		else
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_RESULT);
		}
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

	//�c�@�̕\��
	for (int i = 1; i < 3; i++)
	{
		transcon_.position_.x = -0.065f * i - 0.6f;
		Image::SetTransform(hPictCon_[i - 1], transcon_);
		Image::Draw(hPictCon_[i - 1]);
	}
	
}

//�J��
void PlayScene::Release()
{
}
