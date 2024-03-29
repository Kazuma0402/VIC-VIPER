#include "Item.h"
#include "../Engine/Image.h"
#include "../Ability/Ability.h"
#include "Enemy.h"

//コンストラクタ
Item::Item(GameObject* parent)
	:GameObject(parent, "Item"), hPict_(-1)
{
}

//デストラクタ
Item::~Item()
{
}

//初期化
void Item::Initialize()
{
	//画像のロード
	hPict_ = Image::Load("Point.png");
	assert(hPict_ >= 0);

	//当たり判定（丸）
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

	//敵の死んだ位置の取得
	GetPosition();
}

//更新
void Item::Update()
{
	transform_.position_.x -= 0.005f;
}

//描画
void Item::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Item::Release()
{
}

//何かに当たった
void Item::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	if (pTarget->GetObjectName() == "Player")
	{
		//アイテムが消える
		KillMe();

		//とったら能力の点灯
		Ability* pAbility = (Ability*)FindObject("Ability");
		pAbility->Addition();
	}
}

//位置の取得
void Item::GetPosition()
{
	double tempx, tempy;

	Enemy* pEnemy = (Enemy*)FindObject("Enemy");
	pEnemy->GetSavePosition(&tempx, &tempy);

	transform_.position_.x = tempx;
	transform_.position_.y = tempy;

}