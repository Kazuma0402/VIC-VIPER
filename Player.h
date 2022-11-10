#pragma once
#include <vector>
#include "Engine/GameObject.h"

#define SPEED 0.001f;		//プレイヤーの加速度

//プレイヤーを管理するクラス
class Player : public GameObject
{
    //画像
    int hPict_;

    //生きてるかどうか
    bool life;

    //画面外にですかの判定
    bool safe = true;

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

