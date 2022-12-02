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

	//初期位置
	transform_.position_.y = -0.92f;

	//大きさ
	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.8f;

	//アビリティの使用回数の初期化
	AbilityCountMissile = 1;
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
		if (AbilityCountMissile > 0)
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

				//アビリティの使用回数を１減らす
				AbilityCountMissile--;
				
				//アビリティがまだ使えるのであれば
				if (AbilityCountMissile > 0)
				{
					//アビリティの点灯を消す
					hPict_[1] = Image::Load("MISSILE.png");
					assert(hPict_[1] >= 0);
				}
				//アビリティが使えないのであれば
				else
				{
					//アビリティの表記の変更
					hPict_[1] = Image::Load("NULL.png");
					assert(hPict_[1] >= 0);
				}
				
			}
		}
		else
		{
			count++;
		}

		break;
	case 3:
		//該当アビリティの点灯
		hPict_[2] = hPictSelect_[2];

		//一個前のアビリティの使用回数があれば表示
		if (AbilityCountMissile > 0)
		{
			//ひとつ前の点灯を戻す
			hPict_[1] = Image::Load("MISSILE.png");
			assert(hPict_[0] >= 0);
		}
		else
		{
			//アビリティの表記の変更
			hPict_[1] = Image::Load("NULL.png");
			assert(hPict_[1] >= 0);
		}
		
		break;
	case 4:
		//該当アビリティの点灯
		hPict_[3] = hPictSelect_[3];

		//ひとつ前の点灯を戻す
		hPict_[2] = Image::Load("DOUBLE.png");
		assert(hPict_[0] >= 0);
		break;
	case 5:
		//該当アビリティの点灯
		hPict_[4] = hPictSelect_[4];

		//ひとつ前の点灯を戻す
		hPict_[3] = Image::Load("LASER.png");
		assert(hPict_[0] >= 0);
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

//復活した際のアビティの点灯の初期化
void Ability::CountReset()
{
	count = 1;
}

//復活した際のアビリティの使用回数の復活
void Ability::AbilityCountHeel()
{
	AbilityCountMissile = 1;
}