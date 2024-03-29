#pragma once
#include "../Engine/GameObject.h"

//プレイヤーを管理するクラス
class Laser : public GameObject
{
    //画像
    int hPict_;

public:
    //コンストラクタ
    Laser(GameObject* parent);

    //デストラクタ
    ~Laser();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

