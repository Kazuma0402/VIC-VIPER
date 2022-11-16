//インクルード
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include "Engine/global.h"
#include "Engine/RootObject.h"
#include "Engine/Model.h"
#include "Engine/Image.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"

#pragma comment(lib, "winmm.lib")

//定数宣言
const char* WIN_CLASS_NAME = "VIC-VIPER";  //ウィンドウクラス名

//プロトタイプ宣言
HWND InitApp(HINSTANCE hInstance, int screenWidth, int screenHeight, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//エントリーポイント
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	SetCurrentDirectory("Assets");

	//初期化ファイル（setup.ini）から必要な情報を取得
	int screenWidth = GetPrivateProfileInt("SCREEN", "Width", 800, ".\\setup.ini");		//スクリーンの幅
	int screenHeight = GetPrivateProfileInt("SCREEN", "Height", 600, ".\\setup.ini");	//スクリーンの高さ

	//ウィンドウを作成
	HWND hWnd = InitApp(hInstance, screenWidth, screenHeight, nCmdShow);

	//Direct3D準備
	Direct3D::Initialize(hWnd, screenWidth, screenHeight);

	//カメラを準備
	Camera::Initialize();

	//入力処理（キーボード、マウス、コントローラー）の準備
	Input::Initialize(hWnd);

	//オーディオ（効果音）の準備
	Audio::Initialize();

	//ルートオブジェクト準備
	//すべてのゲームオブジェクトの親となるオブジェクト
	RootObject* pRootObject = new RootObject;
	pRootObject->Initialize();

	//メッセージループ（何か起きるのを待つ）
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{

		//メッセージあり
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (Input::IsKeyDown(DIK_ESCAPE))
			{
				PostQuitMessage(0);
			}
		}
		//メッセージなし
		else
		{
			timeBeginPeriod(1);

			static DWORD countFps = 0;
			static DWORD startTime = timeGetTime();
			DWORD nowTime = timeGetTime();
			static DWORD lastUpdateTime = nowTime;

			if (nowTime - startTime >= 1000)
			{
				char str[16];
				wsprintf(str, "%u", countFps);
				SetWindowText(hWnd, str);

				countFps = 0;
				startTime = nowTime;
			}

			if ((nowTime - lastUpdateTime) * 60 <= 1000.0f)
			{
				continue;
			}
			lastUpdateTime = nowTime;

			countFps++;

			//入力情報の更新
			Input::Update();
			pRootObject->UpdateSub();

			//ゲームの処理
			Direct3D::BeginDraw();
			pRootObject->DrawSub();

			//アップデート
			Camera::Update();

			//終了
			Direct3D::EndDraw();
			timeEndPeriod(1);
		}
	}

	//いろんな開放
	Audio::Release();
	Model::/*All*/Release();
	Image::AllRelease();
	pRootObject->ReleaseSub();
	SAFE_DELETE(pRootObject);
	Direct3D::Release();

	return 0;
}

//ウィンドウの作成
HWND InitApp(HINSTANCE hInstance, int screenWidth, int screenHeight, int nCmdShow)
{
	//ウィンドウクラス（設計図）を作成
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);                     //この構造体のサイズ
	wc.hInstance = hInstance;                           //インスタンスハンドル
	wc.lpszClassName = WIN_CLASS_NAME;                  //ウィンドウクラス名
	wc.lpfnWndProc = WndProc;                           //ウィンドウプロシージャ
	wc.style = CS_VREDRAW | CS_HREDRAW;                 //スタイル（デフォルト）
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);      //アイコン
	wc.hIconSm = LoadIcon(nullptr, IDI_WINLOGO);        //小さいアイコン
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			//マウスカーソル
	wc.lpszMenuName = nullptr;                          //メニュー（なし）
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //背景（白）
	RegisterClassEx(&wc);

	//ウィンドウサイズの計算
	RECT winRect = { 0, 0, screenWidth, screenHeight };
	AdjustWindowRect(&winRect, WS_MAXIMIZE, FALSE);

	//タイトルバーに表示する内容
	char caption[64];
	GetPrivateProfileString("SCREEN", "Caption", "***", caption, 64, ".\\setup.ini");

	//ウィンドウを作成
	HWND hWnd = CreateWindow(
		WIN_CLASS_NAME,						//ウィンドウクラス名
		caption,							//タイトルバーに表示する内容
		WS_MAXIMIZE,						//スタイル（普通のウィンドウ）
		CW_USEDEFAULT,						//表示位置左（おまかせ）
		CW_USEDEFAULT,						//表示位置上（おまかせ）
		winRect.right - winRect.left,		//ウィンドウ幅
		winRect.bottom - winRect.top,		//ウィンドウ高さ
		NULL,								//親ウインドウ（なし）
		NULL,								//メニュー（なし）
		hInstance,							//インスタンス
		NULL								//パラメータ（なし）
	);

	SetWindowLong(hWnd, GWL_STYLE, 0); // Without 1 point border = white rectangle

	//ウィンドウを表示
	ShowWindow(hWnd, nCmdShow);

	return hWnd;
}

//ウィンドウプロシージャ（何かあった時によばれる関数）
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{	
	case WM_DESTROY:
		PostQuitMessage(0);  //プログラム終了
		return 0;
	case WM_CREATE:
		ShowCursor(FALSE);	//マウスカーソルの非表示
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}