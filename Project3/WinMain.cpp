#include "Stdafx.h"
#include "GameManager.h"

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0,0 };


//�ݹ�
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

GameManager* _gm;
int centerX;
int centerY;

int APIENTRY WinMain(_In_ HINSTANCE hInstance,
	HINSTANCE hprevInstance,
	LPSTR _lpszCmdParam,
	int nCmdShow)
{
	_gm = new GameManager();
	_hInstance = hInstance;

	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow
	(
		WINNAME,
		WINNAME,
		WINSTYLE,
		WINSTART_X,
		WINSTART_Y,
		WINSIZE_X,
		WINSIZE_Y,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL
	);
	//�޸� �ܰ� show �ϱ����� ����
	// Ŭ���̾�Ʈ ������ ����� ��Ȯ�� ����ֱ� ���� 
	setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

	ShowWindow(_hWnd, nCmdShow);

	if (FAILED(_gm->init()))
	{
		return 0;
	}
	//UpdateWindow(_hWnd);

	MSG message;
	//ZeroMemory(&message, sizeof(message));

	while (GetMessage(&message, nullptr, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	_gm->release();
	UnregisterClass(WINNAME, hInstance);
	return message.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wparam, LPARAM lparam)
{
	return _gm->MainProc(hwnd, iMessage, wparam, lparam);
}

void setWindowSize(int x, int y, int width, int height)
{
	RECT rc = { 0,0,width,height };
	//���� ������ ũ�� ����
	//AdjustWindowRect(): RECT ����ü, ������ ��Ÿ��, �޴�����?
	AdjustWindowRect(&rc, WINSTYLE, false);

	//���� ��Ʈ�� ������ ������ ������ ����
	SetWindowPos(_hWnd, NULL, x, y,
		(rc.right - rc.left),
		(rc.bottom - rc.top),
		SWP_NOZORDER | SWP_NOMOVE);
	//�⺻������ ������ �ɼ� ZORDER = ���� 
}