#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Ability : public GameObject
{
    //画像
    int hPict_[6];
    int hPictSelect_[6];

    //画像の表示
    int count;
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
};

