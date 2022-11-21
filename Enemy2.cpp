#include "Enemy2.h"
#include "EnemyBullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Score.h";

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Enemy2::Enemy2(GameObject* parent)
	:GameObject(parent, "Enemy2")
{
}

//ƒfƒXƒgƒ‰ƒNƒ^
Enemy2::~Enemy2()
{
}

//‰Šú‰»
void Enemy2::Initialize()
{
	//“G‚P
	hPict_ = Image::Load("Enemy.png");
	assert(hPict_ >= 0);

	//“G‚P
	//‰ŠúˆÊ’u
	transform_.position_.x = 2.2f;
	transform_.position_.y = -0.4f;

	//“G‚Ì‘å‚«‚³
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;

	//“–‚½‚è”»’èiŠÛj
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);


}

//XV
void Enemy2::Update()
{
	//ˆÚ“®‘¬“x
	transform_.position_.x -= 0.01f;
}

//•`‰æ
void Enemy2::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//ŠJ•ú
void Enemy2::Release()
{
}

//‰½‚©‚É“–‚½‚Á‚½
void Enemy2::OnCollision(GameObject* pTarget)
{
	//“–‚½‚Á‚½‚Æ‚«‚Ìˆ—
	if (pTarget->GetObjectName() == "Bullet")
	{
		//“G‚ªÁ‚¦‚é
		KillMe();
		//’e‚ªÁ‚¦‚é
		pTarget->KillMe();

		//“G‚ð“|‚µ‚½‚çƒXƒRƒA‚Ì‰ÁŽZ
		Score* pScore = (Score*)FindObject("Score");
		pScore->Addition();
	}
}