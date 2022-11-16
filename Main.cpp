//�C���N���[�h
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

//�萔�錾
const char* WIN_CLASS_NAME = "VIC-VIPER";  //�E�B���h�E�N���X��

//�v���g�^�C�v�錾
HWND InitApp(HINSTANCE hInstance, int screenWidth, int screenHeight, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//�G���g���[�|�C���g
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	SetCurrentDirectory("Assets");

	//�������t�@�C���isetup.ini�j����K�v�ȏ����擾
	int screenWidth = GetPrivateProfileInt("SCREEN", "Width", 800, ".\\setup.ini");		//�X�N���[���̕�
	int screenHeight = GetPrivateProfileInt("SCREEN", "Height", 600, ".\\setup.ini");	//�X�N���[���̍���

	//�E�B���h�E���쐬
	HWND hWnd = InitApp(hInstance, screenWidth, screenHeight, nCmdShow);

	//Direct3D����
	Direct3D::Initialize(hWnd, screenWidth, screenHeight);

	//�J����������
	Camera::Initialize();

	//���͏����i�L�[�{�[�h�A�}�E�X�A�R���g���[���[�j�̏���
	Input::Initialize(hWnd);

	//�I�[�f�B�I�i���ʉ��j�̏���
	Audio::Initialize();

	//���[�g�I�u�W�F�N�g����
	//���ׂẴQ�[���I�u�W�F�N�g�̐e�ƂȂ�I�u�W�F�N�g
	RootObject* pRootObject = new RootObject;
	pRootObject->Initialize();

	//���b�Z�[�W���[�v�i�����N����̂�҂j
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{

		//���b�Z�[�W����
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (Input::IsKeyDown(DIK_ESCAPE))
			{
				PostQuitMessage(0);
			}
		}
		//���b�Z�[�W�Ȃ�
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

			//���͏��̍X�V
			Input::Update();
			pRootObject->UpdateSub();

			//�Q�[���̏���
			Direct3D::BeginDraw();
			pRootObject->DrawSub();

			//�A�b�v�f�[�g
			Camera::Update();

			//�I��
			Direct3D::EndDraw();
			timeEndPeriod(1);
		}
	}

	//�����ȊJ��
	Audio::Release();
	Model::/*All*/Release();
	Image::AllRelease();
	pRootObject->ReleaseSub();
	SAFE_DELETE(pRootObject);
	Direct3D::Release();

	return 0;
}

//�E�B���h�E�̍쐬
HWND InitApp(HINSTANCE hInstance, int screenWidth, int screenHeight, int nCmdShow)
{
	//�E�B���h�E�N���X�i�݌v�}�j���쐬
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);                     //���̍\���̂̃T�C�Y
	wc.hInstance = hInstance;                           //�C���X�^���X�n���h��
	wc.lpszClassName = WIN_CLASS_NAME;                  //�E�B���h�E�N���X��
	wc.lpfnWndProc = WndProc;                           //�E�B���h�E�v���V�[�W��
	wc.style = CS_VREDRAW | CS_HREDRAW;                 //�X�^�C���i�f�t�H���g�j
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);      //�A�C�R��
	wc.hIconSm = LoadIcon(nullptr, IDI_WINLOGO);        //�������A�C�R��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			//�}�E�X�J�[�\��
	wc.lpszMenuName = nullptr;                          //���j���[�i�Ȃ��j
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //�w�i�i���j
	RegisterClassEx(&wc);

	//�E�B���h�E�T�C�Y�̌v�Z
	RECT winRect = { 0, 0, screenWidth, screenHeight };
	AdjustWindowRect(&winRect, WS_MAXIMIZE, FALSE);

	//�^�C�g���o�[�ɕ\��������e
	char caption[64];
	GetPrivateProfileString("SCREEN", "Caption", "***", caption, 64, ".\\setup.ini");

	//�E�B���h�E���쐬
	HWND hWnd = CreateWindow(
		WIN_CLASS_NAME,						//�E�B���h�E�N���X��
		caption,							//�^�C�g���o�[�ɕ\��������e
		WS_MAXIMIZE,						//�X�^�C���i���ʂ̃E�B���h�E�j
		CW_USEDEFAULT,						//�\���ʒu���i���܂����j
		CW_USEDEFAULT,						//�\���ʒu��i���܂����j
		winRect.right - winRect.left,		//�E�B���h�E��
		winRect.bottom - winRect.top,		//�E�B���h�E����
		NULL,								//�e�E�C���h�E�i�Ȃ��j
		NULL,								//���j���[�i�Ȃ��j
		hInstance,							//�C���X�^���X
		NULL								//�p�����[�^�i�Ȃ��j
	);

	SetWindowLong(hWnd, GWL_STYLE, 0); // Without 1 point border = white rectangle

	//�E�B���h�E��\��
	ShowWindow(hWnd, nCmdShow);

	return hWnd;
}

//�E�B���h�E�v���V�[�W���i�������������ɂ�΂��֐��j
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{	
	case WM_DESTROY:
		PostQuitMessage(0);  //�v���O�����I��
		return 0;
	case WM_CREATE:
		ShowCursor(FALSE);	//�}�E�X�J�[�\���̔�\��
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}