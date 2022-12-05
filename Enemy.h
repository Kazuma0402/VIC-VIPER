#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Enemy : public GameObject
{
    //画像
    int hPict_;

    int wavePoint;

    //死んだ数
    int KillCount;
public:
    //コンストラクタ
    Enemy(GameObject* parent);

    //デストラクタ
    ~Enemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //当たり判定
    void OnCollision(GameObject* pTarget) override;

    void KillCountpuls();
};

