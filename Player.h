#pragma once
#include "Engine/GameObject.h"

//プロトタイプ宣言
const int WINDOW_WIDTH = GetSystemMetrics(SM_CXSCREEN);			//ウィンドウの幅
const int WINDOW_HEIGHT = GetSystemMetrics(SM_CYSCREEN);		//ウィンドウの高さ

//プレイヤーを管理するクラス
class Player : public GameObject
{
    int hModel_;

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

