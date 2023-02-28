#pragma once
#include "../Engine/GameObject.h"

//プレイヤーを管理するクラス
class Enemy : public GameObject
{
    //画像
    int hPict_;

    //折り返し地点
    int wavePoint;

    //位置を保存
    double pos_x, pos_y;
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

    //位置の取得
    void GetPosition(double* x, double* y);

    //死んだ位置をアイテムへ送る
    void SendOldPosition(double* x, double* y);
};

