#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Option : public GameObject
{
    //画像
    int hPict_[2];
    int hPictNow_;

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

};