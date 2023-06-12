#pragma once
#include "../Engine/GameObject.h"

//プレイヤーを管理するクラス
class Boss : public GameObject
{
    //画像
    int hPict_;

    //体力
    int hp;

    //上下移動への移動
    bool move;

    //折り返し地点
    bool wavePoint;

    //弾の発射クールタイム
    int time;
public:
    //コンストラクタ
    Boss(GameObject* parent);

    //デストラクタ
    ~Boss();

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

