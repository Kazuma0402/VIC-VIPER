#include "Item.h"
#include "Engine/Image.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Item::Item(GameObject* parent)
	:GameObject(parent, "Item")
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

	//大きさ
	transform_.scale_.y = 1.2f;

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
		KillMe();
		pTarget->KillMe();
	}
}