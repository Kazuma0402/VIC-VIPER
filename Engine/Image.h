#pragma once

#pragma once

#include <vector>
#include <string>
#include "Sprite.h"
#include "Transform.h"

//-----------------------------------------------------------
//2D画像を管理する
//-----------------------------------------------------------
namespace Image
{
	//画像情報
	struct ImageData
	{
		//ファイル名
		std::string fileName;

		//ロードした画像データのアドレス
		Sprite* pSprite;

		//行列
		Transform transform;

		//コンストラクタ
		ImageData() : pSprite(nullptr)
		{
		}
	};


	//初期化
	void Initialize();

	//画像をロード
	int Load(std::string fileName);

	//描画
	void Draw(int handle);

	//任意の画像を開放
	void Release(int handle);

	//全ての画像を解放）
	void AllRelease();

	//ワールド行列を設定
	void SetTransform(int handle, Transform& transform);

	//ワールド行列の取得
	XMMATRIX GetMatrix(int handle);
}