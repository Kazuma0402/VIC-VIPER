#include "Boss.h"
#include "EnemyBullet.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Display/Score.h"

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Boss::Boss(GameObject* parent)
	:GameObject(parent, "Boss"), hPict_(-1)
{
}

//ƒfƒXƒgƒ‰ƒNƒ^
Boss::~Boss()
{
}

//‰Šú‰»
void Boss::Initialize()
{
	//‰æ‘œ‚Ìƒ[ƒh
	hPict_ = Image::Load("Boss.png");
	assert(hPict_ >= 0);

	//‰ŠúˆÊ’u
	transform_.position_.x = 50.00f;
	transform_.position_.y = 0.4f;
	//‘å‚«‚³
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//“–‚½‚è”»’èiŠÛj
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

	//‘Ì—Í‚Ì‰Šú‰»
	hp = 100;

	move = false;

	wavePoint = false;

	time = 0;
}

//XV
void Boss::Update()
{
	if (transform_.position_.x >= 0.4f)
	{
		//ˆÚ“®‘¬“x
		transform_.position_.x -= 0.005f;
	}
	else if (transform_.position_.x <= 0.4f)
	{
		move = true;
	}
	
	//ˆÚ“®‚ÌØ‚è‘Ö‚¦
	if (move == true && wavePoint == false)
	{
		transform_.position_.y += 0.005f;

		if (transform_.position_.y >= 0.70f)
		{
			wavePoint = true;
		}
	}
	else if (move == true && wavePoint == true)
	{
		transform_.position_.y -= 0.005f;

		if (transform_.position_.y <= -0.70f)
		{
			wavePoint = false;
		}
	}

	//if (move == true)
	//{
	//	time++;

	//	if (time >= 120)
	//	{
	//		EnemyBullet* pEnemyBullet = Instantiate<EnemyBullet>(GetParent());
	//		pEnemyBullet->SetPosition(transform_.position_);

	//		time = 0;
	//	}
	//}
	
}

//•`‰æ
void Boss::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//ŠJ•ú
void Boss::Release()
{
}

//‰½‚©‚É“–‚½‚Á‚½
void Boss::OnCollision(GameObject* pTarget)
{
	//“–‚½‚Á‚½‚Æ‚«‚Ìˆ—
	if (pTarget->GetObjectName() == "Bullet")
	{
		//“G‚ªÁ‚¦‚é
		hp--;

		//’e‚ªÁ‚¦‚é
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
	//“–‚½‚Á‚½‚Æ‚«‚Ìˆ—
	if (pTarget->GetObjectName() == "Missile")
	{
		//“G‚ªÁ‚¦‚é
		hp--;

		//’e‚ªÁ‚¦‚é
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
	//“–‚½‚Á‚½‚Æ‚«‚Ìˆ—
	if (pTarget->GetObjectName() == "Double")
	{
		//“G‚ªÁ‚¦‚é
		hp--;

		//’e‚ªÁ‚¦‚é
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
	//“–‚½‚Á‚½‚Æ‚«‚Ìˆ—
	if (pTarget->GetObjectName() == "Laser")
	{
		//“G‚ªÁ‚¦‚é
		hp -= 3;

		//’e‚ªÁ‚¦‚é
		pTarget->KillMe();

		if (hp <= 0)
		{
			KillMe();
		}
	}
}
