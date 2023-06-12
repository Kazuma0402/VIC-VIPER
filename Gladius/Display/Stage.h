#pragma once
#include "../Engine/GameObject.h"

//Stageシーンを管理するクラス
class Stage : public GameObject
{
	//画像用
	int hPict_[4];

	Transform trans1_;
	Transform trans2_;
	Transform trans3_;
	Transform trans4_;

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

