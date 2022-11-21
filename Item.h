#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Item : public GameObject
{
    //画像
    int hPict_[6];
    int hPictSelect_[6];

    //画像のカウント用
    int count = 0;

public:
    //コンストラクタ
    Item(GameObject* parent);

    //デストラクタ
    ~Item();

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

    //アイテムを取った時
    void GetItem();
};

