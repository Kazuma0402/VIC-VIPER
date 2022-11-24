#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Life : public GameObject
{
    //画像
    int hPictCon_[3];

    //残機
    int life = 2;

    //死亡回数
    int con = 0;

public:
    //コンストラクタ
    Life(GameObject* parent);

    //デストラクタ
    ~Life();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //残機判定
    void Stock();
};

