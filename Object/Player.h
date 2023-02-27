#pragma once
#include "../Engine/GameObject.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
    //画像
    int hPict_;

    int hPicts_;
    Transform t_;

    //機体のスピード
    float speed;

    //弾の位置の補正
    Transform trans_;

    //射撃のクールタイム用
    int time;
    //ミサイルのクールタイム用
    int time2;
    //二方向発射のクールタイム用
    int time3;
    //レーザーのクールタイム用
    int time4;

    //アビリティの有無
    bool missile_;
    bool double_;
    bool laser_;

    //コナミコマンド用（仮）
    int cnt;

    //移動しているかしていないか
    bool angle;

    //座標用配列
    double cx[81];
    double cy[81];
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

    //位置の取得
    void GetPosition(double *x, double *y);

    //自機に昔の位置(20個前)の取得
    void GetOldPosition20(double *x, double *y);
    //自機に昔の位置(40個前)の取得
    void GetOldPosition40(double* x, double* y);
    //自機に昔の位置(60個前)の取得
    void GetOldPosition60(double* x, double* y);
    //自機に昔の位置(80個前)の取得
    void GetOldPosition80(double* x, double* y);

    //死んだ時に座標記録の配列を初期化にする
    void ResetPosition();

    //↓アビリティの開放↓
    //スピードアップ
    void SpeedUp();

    //ミサイルの発射
    void ShotMissile();

    //弾が二方向へ発射
    void ShotDouble();

    //弾がレーザーに変更
    void ShotLaser();

    //機体が変身
    void Change();
};