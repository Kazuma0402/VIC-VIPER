#include "Ability.h"
#include "Player.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//コンストラクタ
Ability::Ability(GameObject* parent)
	:GameObject(parent, "Ability")
{
}

//デストラクタ
Ability::~Ability()
{
}

//初期化
void Ability::Initialize()
{
	//画像データ
	std::string fileName[] = {
		"SPEEDUP.png",
		"MISSILE.png",
		"DOUBLE.png",
		"LASER.png",
		"OPTION.png",
		"HATENA.png",
	};

	std::string fileName2[] = {
		"SPEEDUP_SELECT.png",
		"MISSILE_SELECT.png",
		"DOUBLE_SELECT.png",
		"LASER_SELECT.png",
		"OPTION_SELECT.png",
		"HATENA_SELECT.png",
	};

	std::string fileName3[] = {
		"NULL.png",
		"NULL_SELECT.png",
	};

	//画像のロード
	for (int i = 0; i < 6; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}

	for (int i = 0; i < 6; i++)
	{
		hPictSelect_[i] = Image::Load(fileName2[i]);
		assert(hPictSelect_[i] >= 0);
	}

	for (int i = 0; i < 2; i++)
	{
		hPictNull_[i] = Image::Load(fileName3[i]);
		assert(hPictNull_[i] >= 0);
	}

	//初期位置
	transform_.position_.y = -0.92f;

	//大きさ
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.8f;

	//アビリティの使用判定の初期化
	//true = 使用可　false = 使用不可
	AbilityMissile = true;
	AbilityDouble = true;
	AbilityLaser = true;

}

//更新
void Ability::Update()
{
	//アビリティの点灯
	switch (count)
	{
	case 1:
		//該当アビリティの点灯
		hPict_[0] = hPictSelect_[0];

		//ひとつ前の点灯を戻す
		hPict_[5] = Image::Load("HATENA.png");
		assert(hPict_[0] >= 0);

		//Lを押したらスピードアップ
		if (Input::IsKeyDown(DIK_L))
		{
			Player* pPlayer = (Player*)FindObject("Player");
			pPlayer->SpeedUp();

			//countを戻す
			count = 0;

			//アビリティの点灯を消す
			hPict_[0] = Image::Load("SPEEDUP.png");
			assert(hPict_[0] >= 0);;
		}

		break;
	case 2:
		//ひとつ前の点灯を戻す
		hPict_[0] = Image::Load("SPEEDUP.png");
		assert(hPict_[0] >= 0);

		//アビリティの使用回数がまだあるなら
		if (AbilityMissile == true)
		{
			//該当アビリティの点灯
			hPict_[1] = hPictSelect_[1];

			//Lを押したらミサイルの発射可能
			if (Input::IsKeyDown(DIK_L))
			{
				//ミサイルが打てるようにする
				Player* pPlayer = (Player*)FindObject("Player");
				pPlayer->ShotMissile();

				//countを戻す
				count = 0;

				//アビリティの使用をできなくする
				AbilityMissile = false;
				
				//アビリティが使えないのであれば
				if (AbilityMissile == false)
				{
					//アビリティの表記の変更
					hPict_[1] = hPictNull_[0];
				}
			}
		}
		else
		{
			//該当アビリティの点灯
			hPict_[1] = hPictNull_[1];
		}

		break;
	case 3:
		//アビリティの使用が可能であれば
		if (AbilityDouble == true)
		{
			//該当アビリティの点灯
			hPict_[2] = hPictSelect_[2];

			//Lを押したらミサイルの発射可能
			if (Input::IsKeyDown(DIK_L))
			{
				//二方向に弾が打てるようにする
				Player* pPlayer = (Player*)FindObject("Player");
				pPlayer->ShotDouble();

				//countを戻す
				count = 0;

				//アビリティの使用をできなくする
				AbilityDouble = false;

				//アビリティが使えないのであれば
				if (AbilityDouble == false)
				{
					//アビリティの表記の変更
					hPict_[2] = hPictNull_[0];
				}

				//レーザーの使用をできるようにする
				AbilityLaser = true;

				//レーザーの表示を戻す
				hPict_[3] = Image::Load("LASER.png");
				assert(hPict_[1] >= 0);
			}
		}
		else
		{
			//アビリティの表記の変更
			hPict_[2] = hPictNull_[1];
		}
		
		//一個前のアビリティの使用回数があれば表示
		if (AbilityMissile == true)
		{
			//ひとつ前の点灯を戻す
			hPict_[1] = Image::Load("MISSILE.png");
			assert(hPict_[1] >= 0);
		}
		else
		{
			//アビリティの表記の変更
			hPict_[1] = hPictNull_[0];
		}
		break;
	case 4:
		//アビリティの使用が可能であれば
		if (AbilityLaser == true)
		{
			//該当アビリティの点灯
			hPict_[3] = hPictSelect_[3];

			//Lを押したらミサイルの発射可能
			if (Input::IsKeyDown(DIK_L))
			{
				//二方向に弾が打てるようにする
				Player* pPlayer = (Player*)FindObject("Player");
				pPlayer->ShotLaser();

				//countを戻す
				count = 0;

				//アビリティの使用をできなくする
				AbilityLaser = false;

				//アビリティが使えないのであれば
				if (AbilityLaser == false)
				{
					//アビリティの表記の変更
					hPict_[3] = hPictNull_[0];
				}

				//ダブルの使用をできるようにする
				AbilityDouble = true;

				//ダブルの表示を戻す
				hPict_[2] = Image::Load("Double.png");
				assert(hPict_[1] >= 0);
				
			}
		}
		else
		{
			//アビリティの表記の変更
			hPict_[3] = hPictNull_[1];
		}

		//一個前のアビリティの使用回数があれば表示
		if (AbilityDouble == true)
		{
			//ひとつ前の点灯を戻す
			hPict_[2] = Image::Load("Double.png");
			assert(hPict_[2] >= 0);
		}
		else
		{
			//アビリティの表記の変更
			hPict_[2] = hPictNull_[0];
		}
		break;
	case 5:
		//該当アビリティの点灯
		hPict_[4] = hPictSelect_[4];

		//一個前のアビリティの使用回数があれば表示
		if (AbilityDouble == true)
		{
			//ひとつ前の点灯を戻す
			hPict_[3] = Image::Load("Laser.png");
			assert(hPict_[3] >= 0);
		}
		else
		{
			//アビリティの表記の変更
			hPict_[3] = hPictNull_[0];
		}
		break;
	case 6:
		//該当アビリティの点灯
		hPict_[5] = hPictSelect_[5];

		//ひとつ前の点灯を戻す
		hPict_[4] = Image::Load("OPTION.png");
		assert(hPict_[0] >= 0);
		break;
	}
}

//描画
void Ability::Draw()
{
	for (int i = 0; i < 6; i++)
	{
		transform_.position_.x = 0.2f * i - 0.5f;
		Image::SetTransform(hPict_[i], transform_);
		Image::Draw(hPict_[i]);
	}

}

//開放
void Ability::Release()
{
}

//カウントの加算
void Ability::Addition()
{
	count++;

	//7以上ならcountを1に戻す
	if (count >= 7)
	{
		count = 1;
	}
}

//復活した際のカウントの初期化
void Ability::CountReset()
{
	count = 1;
}

//復活した際のアビリティ使用の復活
void Ability::AbilityHeel()
{
	AbilityMissile = true;
	AbilityDouble = true;
}

//復活した際のアビリティ表示のリセット
void Ability::AbilityReset()
{
	//画像データ
	std::string fileName[] = {
		"SPEEDUP_SELECT.png",
		"MISSILE.png",
		"DOUBLE.png",
		"LASER.png",
		"OPTION.png",
		"HATENA.png",
	};

	//画像のロード
	for (int i = 0; i < 6; i++)
	{
		hPict_[i] = Image::Load(fileName[i]);
		assert(hPict_[i] >= 0);
	}
}