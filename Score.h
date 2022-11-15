#pragma once
#include "Engine/GameObject.h"


//TitleSceneシーンを管理するクラス
class Score : public GameObject
{
	//画像用配列
	int hPict_[11];
	int hScore_[6];

	//スコア加算用
	int count = 0;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト
	Score(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//スコアの加算
	void Addition();
};

