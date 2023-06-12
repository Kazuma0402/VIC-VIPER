#pragma once
#include "../Engine/GameObject.h"


//OptionSceneシーンを管理するクラス
class OptionScene : public GameObject
{
	int hPict_[2];
	int nowPict_;

	bool push;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	OptionScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

