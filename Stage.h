#pragma once
#include "Engine/GameObject.h"

//Stageシーンを管理するクラス
class Stage : public GameObject
{
	//画像用
	int hPict_;

	//敵の出現
	int time = 0;
	int count = 0;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Stage(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

