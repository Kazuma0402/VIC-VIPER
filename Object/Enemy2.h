#pragma once
#include "../Engine/GameObject.h"

//プレイヤーを管理するクラス
class Enemy2 : public GameObject
{
    //画像
    int hPict_;

    //折り返し地点
    int wavePoint;

    //プレイヤーの位置を保存
    double pos_x, pos_y;

    //死んだ数
    int KillCount;
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
    void OnCollision(GameObject* pTarget) override;

    //スコア用
    void KillCountpuls();

    //プレイヤーの位置の取得
    void GetPlayerPosition(double* x, double* y);
};

