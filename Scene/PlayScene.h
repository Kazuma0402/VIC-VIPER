#pragma once
#include "../Engine/GameObject.h"

//PlaySceneシーンを管理するクラス
class PlayScene : public GameObject
{
	//画像用の配列
	int hPict_[2];

	int time = 0;
	int count = 0;

	//画像の描画位置用
	Transform trans_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//プレイヤーの表示
	void AppearancePlayer();

	//アイテムの表示
	void AppearanceItem();
};

