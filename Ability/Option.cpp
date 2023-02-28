#include "Option.h"
#include "Double.h"
#include "Laser.h"
#include "Missile.h"
#include "../Object/Player.h"
#include "../Object/Bullet.h"

#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/SphereCollider.h"

//コンストラクタ
Option::Option(GameObject* parent)
	:GameObject(parent, "Option")
{
}

//デストラクタ
Option::~Option()
{
}

//初期化
void Option::Initialize()
{
	//画像のロード
	for (int i = 0; i < 4; i++)
	{
		hPict_[i] = Image::Load("Fighter.png");
	}

	//最初は出ていないから０
	cnt = 0;

	//クールタイムの初期化
	time = 0;
	time2 = 0;
	time3 = 0;
	time4 = 0;

	//アビリティの初期化
	missile_ = false;
	double_ = false;
	laser_ = false;

	//発射速度
	speed = 0.01f;

	//レーザーの発射位置の補正
	trans_.position_.x = 0.45f;

	alive = false;
}

//更新
void Option::Update()
{
	//オプションが表示されいるなら座標の更新可能
	if (FindObject("Option") != NULL)
	{
		alive = true;
	}
	else
	{
		alive = false;
		cnt = 0;
	}

	//オプションが表示されている間だけ座標の更新
	if(alive == true)
	{
		//常にプレイヤーの昔の位置を更新
		GetPlayerPosition20();
		GetPlayerPosition40();
		GetPlayerPosition60();
		GetPlayerPosition80();
	}

	//位置の更新
	pos1_.position_.x = cx[0];
	pos1_.position_.y = cy[0];
	pos2_.position_.x = cx[1];
	pos2_.position_.y = cy[1];
	pos3_.position_.x = cx[2];
	pos3_.position_.y = cy[2];
	pos4_.position_.x = cx[3];
	pos4_.position_.y = cy[3];

	//レーザーの発射位置の補正
	trans_1.position_.x = pos1_.position_.x + trans_.position_.x;
	trans_1.position_.y = pos1_.position_.y;
	trans_2.position_.x = pos2_.position_.x + trans_.position_.x;
	trans_2.position_.y = pos2_.position_.y;
	trans_3.position_.x = pos3_.position_.x + trans_.position_.x;
	trans_3.position_.y = pos3_.position_.y;
	trans_4.position_.x = pos4_.position_.x + trans_.position_.x;
	trans_4.position_.y = pos4_.position_.y;

	//射撃について
	time++;
	time2++;
	time3++;
	time4++;

	if (time >= 10)
	{
		//レーザーを使用していないなら
		if (laser_ == false)
		{
			if (cnt >= 1)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Bullet* pBullet = Instantiate<Bullet>(GetParent());
					pBullet->SetPosition(pos1_.position_);

					time = 0;
				}
			}
			if (cnt >= 2)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Bullet* pBullet = Instantiate<Bullet>(GetParent());
					pBullet->SetPosition(pos2_.position_);

					time = 0;
				}
			}
			if (cnt >= 3)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Bullet* pBullet = Instantiate<Bullet>(GetParent());
					pBullet->SetPosition(pos3_.position_);

					time = 0;
				}
			}
			if (cnt >= 4)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Bullet* pBullet = Instantiate<Bullet>(GetParent());
					pBullet->SetPosition(pos4_.position_);

					time = 0;
				}
			}
			
		}
	}

	//ミサイルの発射
	if (missile_ == true)
	{
		if (time2 >= 60)
		{
			if (cnt >= 1)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Missile* pMissile = Instantiate<Missile>(GetParent());
					pMissile->SetPosition(pos1_.position_);

					time2 = 0;
				}
			}
			if (cnt >= 2)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Missile* pMissile = Instantiate<Missile>(GetParent());
					pMissile->SetPosition(pos2_.position_);

					time2 = 0;
				}
			}
			if (cnt >= 3)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Missile* pMissile = Instantiate<Missile>(GetParent());
					pMissile->SetPosition(pos3_.position_);

					time2 = 0;
				}
			}
			if (cnt >= 4)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Missile* pMissile = Instantiate<Missile>(GetParent());
					pMissile->SetPosition(pos4_.position_);

					time2 = 0;
				}
			}
		}
	}

	//二方向への発射
	if (double_ == true)
	{
		if (time3 >= 10)
		{
			if (cnt >= 1)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Double* pDouble = Instantiate<Double>(GetParent());
					pDouble->SetPosition(pos1_.position_);

					time3 = 0;
				}
			}
			if (cnt >= 2)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Double* pDouble = Instantiate<Double>(GetParent());
					pDouble->SetPosition(pos2_.position_);

					time3 = 0;
				}
			}
			if (cnt >= 3)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Double* pDouble = Instantiate<Double>(GetParent());
					pDouble->SetPosition(pos3_.position_);

					time3 = 0;
				}
			}
			if (cnt >= 4)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Double* pDouble = Instantiate<Double>(GetParent());
					pDouble->SetPosition(pos4_.position_);

					time3 = 0;
				}
			}
		}
	}

	//レーザーの発射
	if (laser_ == true)
	{
		if (time4 >= 30)
		{
			if (cnt >= 1)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Laser* pLaser = Instantiate<Laser>(GetParent());
					pLaser->SetPosition(trans_1.position_);

					time4 = 0;
				}
			}
			if (cnt >= 2)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Laser* pLaser = Instantiate<Laser>(GetParent());
					pLaser->SetPosition(trans_2.position_);

					time4 = 0;
				}
			}
			if (cnt >= 3)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Laser* pLaser = Instantiate<Laser>(GetParent());
					pLaser->SetPosition(trans_3.position_);

					time4 = 0;
				}
			}
			if (cnt >= 4)
			{
				//スペースキーが押している間
				if (Input::IsKey(DIK_SPACE))
				{
					Laser* pLaser = Instantiate<Laser>(GetParent());
					pLaser->SetPosition(trans_4.position_);

					time4 = 0;
				}
			}
		}
	}
}

//描画
void Option::Draw()
{
	if (cnt == 0)
	{
		Image::SetTransform(hPict_[0], pos1_);
	}
	if (cnt >= 1)
	{
		Image::SetTransform(hPict_[0], pos1_);
		Image::Draw(hPict_[0]);
	}
	if (cnt >= 2)
	{
		Image::SetTransform(hPict_[1], pos2_);
		Image::Draw(hPict_[1]);
	}
	if (cnt >= 3)
	{
		Image::SetTransform(hPict_[2], pos3_);
		Image::Draw(hPict_[2]);
	}
	if (cnt >= 4)
	{
		Image::SetTransform(hPict_[3], pos4_);
		Image::Draw(hPict_[3]);
	}
}

//解放
void Option::Release()
{
}

//プレイヤーの昔の座標の取得
void Option::GetPlayerPosition20()
{	

	double tempx, tempy;
	Player* pPlayer = (Player*)FindObject("Player");
	pPlayer->GetOldPosition20(&tempx, &tempy);

	cx[0] = tempx;
	cy[0] = tempy;
}
void Option::GetPlayerPosition40()
{

	double tempx, tempy;
	Player* pPlayer = (Player*)FindObject("Player");
	pPlayer->GetOldPosition40(&tempx, &tempy);

	cx[1] = tempx;
	cy[1] = tempy;
}
void Option::GetPlayerPosition60()
{

	double tempx, tempy;
	Player* pPlayer = (Player*)FindObject("Player");
	pPlayer->GetOldPosition60(&tempx, &tempy);

	cx[2] = tempx;
	cy[2] = tempy;
}
void Option::GetPlayerPosition80()
{

	double tempx, tempy;
	Player* pPlayer = (Player*)FindObject("Player");
	pPlayer->GetOldPosition80(&tempx, &tempy);

	cx[3] = tempx;
	cy[3] = tempy;
}

//オプションの追加表示
void Option::AddOption()
{
	cnt++;
}

//死ぬ処理
void Option::KillOption()
{
	KillMe();
	alive = false;
}

//二番目
//ミサイルの発射
void Option::ShotMissile()
{
	//ミサイルの使用ができるようにする
	missile_ = true;
}

//三番目
//弾が二方向へ発射
void Option::ShotDouble()
{
	//２方向発射の使用ができるようにする
	double_ = true;

	//レーザーとの併用がをできなくする
	laser_ = false;
}

//四番目
//弾が二方向へ発射
void Option::ShotLaser()
{
	//レーザーの使用ができるようにする
	laser_ = true;

	//ダブルとの併用をできなくする
	double_ = false;
}