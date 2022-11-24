#include "Item.h"
#include "Engine/Image.h"
#include "Ability.h"
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

	//初期位置
	transform_.position_.x = 0.5f;
	transform_.position_.y = -0.4f;

	//当たり判定（丸）
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.03f, 0.0f, 0.0f), 0.08f);
	AddCollider(collision);

}

//更新
void Item::Update()
{
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