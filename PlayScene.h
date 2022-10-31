#pragma once
#include "Engine/SceneManager.h"

class PlayScene : public GameObject
{
public:
	//コンストラクタ
	//引数:Parent　親オブジェクト(SceneManager)
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void  Update() override;

	//描画
	void Draw() override;

	//解放
	void Release() override;
};

