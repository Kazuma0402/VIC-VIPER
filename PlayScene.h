#pragma once
#include "Engine/GameObject.h"

//PlaySceneシーンを管理するクラス
class PlayScene : public GameObject
{
	//画像用の配列
	int hPict_[2];
	int hPictCon_[2];

	//敵の出現
	int time = 0;
	int count = 0;

	//残機
	int life = 2;

	//死んだ回数
	int con = 0;

	//画像の描画位置用
	Transform trans_;
	Transform transcon_;

	

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
};

