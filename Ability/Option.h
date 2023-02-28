#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Global.h"

//プレイヤーを管理するクラス
class Option : public GameObject
{
    //画像用
    int hPict_[4];

    //生きているかの判定
    bool alive;

    //今出ているオプションの数
    int cnt;

    //座標の記録配列
    double cx[4];
    double cy[4];

    //各々の位置用
    Transform pos1_;
    Transform pos2_;
    Transform pos3_;
    Transform pos4_;

    //弾のクールタイム
    int time;
    int time2;
    int time3;
    int time4;

    //アビリティの有無
    bool missile_;
    bool double_;
    bool laser_;

    //発射速度
    float speed;

    //レーザーの発射位置の補正
    Transform trans_1;
    Transform trans_2;
    Transform trans_3;
    Transform trans_4;
    Transform trans_;

public:
    //コンストラクタ
    Option(GameObject* parent);

    //デストラクタ
    ~Option();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //プレイヤーの位置の取得
    void GetPlayerPosition20();
    //プレイヤーの位置の取得
    void GetPlayerPosition40();
    //プレイヤーの位置の取得
    void GetPlayerPosition60();
    //プレイヤーの位置の取得
    void GetPlayerPosition80();

    //オプションの表示
    void AddOption();

    //プレイヤーが死んだ時のリセット
    void CountReset();

    //プレイヤーが死んだときにオプションも死ぬ
    void KillOption();

    //↓アビリティ
    //ミサイルの発射
    void ShotMissile();

    //弾が二方向へ発射
    void ShotDouble();

    //弾がレーザーに変更
    void ShotLaser();
};