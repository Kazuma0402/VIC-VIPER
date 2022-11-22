#include "Stage.h"
#include "Engine/Image.h"
#include "Enemy.h"
#include "Enemy2.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
	: GameObject(parent, "Stage")
{
}

//������
void Stage::Initialize()
{
}

//�X�V
void Stage::Update()
{
	//��莞�ԂœG���o��������
	time++;
	if (time >= 15 && count < 4)
	{
		Instantiate<Enemy>(this);
		Instantiate<Enemy2>(this);
		time = 0;
		count++;
	}

	if (time >= 210 && count >= 4)
	{
		time = 0;
		count = 0;
	}
}

//�`��
void Stage::Draw()
{
}

//�J��
void Stage::Release()
{
}