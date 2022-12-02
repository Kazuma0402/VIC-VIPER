#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Ability : public GameObject
{
    //画像
    int hPict_[6];              //表示画像
    int hPictSelect_[6];        //選択中の画像
    int hPictNull_[2];          //使用回数のない時の画像

    //画像の表示
    int count;

    //アビリティの使用回数
    int AbilityCountMissile;        //ミサイルの使用回数
    int AbilityCountDouble;         //ダブルショットの使用回数
public:
    //コンストラクタ
    Ability(GameObject* parent);

    //デストラクタ
    ~Ability();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //カウントの加算
    void Addition();

    //復活した際のアビリティの点灯の初期化
    void CountReset();

    //復活した際のアビリティの使用回数の回復
    void AbilityCountHeel();
};

