#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
    //画像
    int hPict_;

    //機体のスピード
    float speed;

    //射撃のクールタイム用
    int time;
    //ミサイルのクールタイム用
    int time2;

    //アビリティの有無
    bool missile;

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

    //↓アビリティの開放↓
    //スピードアップ
    void SpeedUp();

    //ミサイルの発射
    void ShotMissile();
};

