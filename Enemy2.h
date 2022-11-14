#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Enemy2 : public GameObject
{
    //画像
    int hPict_;
public:
    //コンストラクタ
    Enemy2(GameObject* parent);

    //デストラクタ
    ~Enemy2();

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

