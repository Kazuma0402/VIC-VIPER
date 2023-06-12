#pragma once
#include "../Engine/GameObject.h"

//プレイヤーを管理するクラス
class Missile : public GameObject
{
    //画像
    int hPict_[2];
    int hPictNow_;

public:
    //コンストラクタ
    Missile(GameObject* parent);

    //デストラクタ
    ~Missile();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

};



