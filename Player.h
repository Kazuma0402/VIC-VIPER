#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
    //画像
    int hPict_;

    //生きてるかどうか
    bool life;

public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

