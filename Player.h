#pragma once
#include "Engine/GameObject.h"

#define SPEED 0.01f;

//プレイヤーを管理するクラス
class Player : public GameObject
{
    //画像
    int hPict_;

    //射撃のクールタイム用
    int time = 0;

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

    //当たり判定
    void OnCollision(GameObject* pTarget);
};

