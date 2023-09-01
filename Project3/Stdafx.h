// header.h: ǥ�� �ý��� ���� ����
// �Ǵ� ������Ʈ Ư�� ���� ������ ��� �ִ� ���� �����Դϴ�.
//

#pragma once
// ��� ����
#pragma warning(disable : 4005) // 
#define _CRT_SECURE_NO_WARNINGS 
// 4005: DXGI �� �׷��� �������̽����� ��ũ�� �����Ͽ� ��µǴ� ��� //c++ > ��� > Ư����� ������
/*
�� Stdafx

- MS�� ���־� ��Ʃ����� �̿��Ͽ� ������Ʈ�� ����� �����Ǵ� Ŭ����
 �� �� ģ���� �ǹ��ϴ� �ٴ� ǥ�� ���ø����̼� �����ӿ�ũ�� Ʋ

- MS���� �����ڵ��� �ɷ� ����� ���� ������ PCH ����
 �� ���� ���̴� �������� ������� �̸� ������ �صξ� ���� �ٽ� ���������� �ʰ� ���

 - ���߿� �ʱ� ���� �ܰ迡���� �� �ʿ伺�� �� �������� ��������� ũ�Ⱑ Ŀ���ų� ����
   ���������� Ȱ�뵵 �� ȿ���� �޻���Ѵ�. ��


*/

//SDKDDKVER.h �� ���α׷����� ������ os�� ���� 
//or ���̺귯���� ���� Windows ������� �ڵ忡 ���Ե� �Լ�/ ��� ���� �����ϴµ� ���
#include <SDKDDKVER.h>

// ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// �� GDI+ �� ����Ϸ��� ������Ͽ��� �����;� �Ѵ�.
//#include <ole2.h> //ȸ�������� ��� ����� ����
#define WIN32_LEAN_AND_MEAN             

// ����� �ܼ�â
#pragma comment (linker, "/entry:WinMainCRTStartup /subsystem:console")


//! ���̺귯�� �߰�
#pragma comment (lib, "msimg32.lib")
#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "./lib/FMOD/fmodex_vc.lib")
#pragma comment(lib, "./jsoncpp/lib_json.tlog/json_vc71_libmtd.lib")

//! Windows ��� ����
#include <windows.h>
//#include <wdm.h>

#include "./inc/FMOD/fmod.hpp"
#include "./jsoncpp/include/json/json.h"

//! C ��Ÿ�� ��� �����Դϴ�.
// stdlib: C����� ǥ�� ���̺귯�� �Լ��� ��� ����
#include <stdlib.h>
// C��� �޸� �Ҵ翡 ���
#include <malloc.h>

// �޸� ���� ��� ����
// �� memset/ memcopy�� ����ϴ� �������
#include <memory.h>

/*
�� ���ڿ� ��
- �����쿡�� ����� ���ڿ� ��� ����(����) ��(TextOut, DrawText, wsprintf ���)
�� �⺻������ �����ڵ�

 MBCS (��Ƽ����Ʈ ĳ���� ��)
- ������ ����ϴ� ��Ƽ����Ʈ ������ ���ڿ��� ���Ѵ�.
- ��Ƽ����Ʈ �ڵ�� ���� ���� �ƽ�Ű �ڵ忡 ���ԵǴ� ���ڴ� 1����Ʈ�� ǥ���ϰ�
  ���Ե��� �ʴ� ���ڴ� 2����Ʈ�� ó���Ѵ�.

 WBCS (���̵����Ʈ ĳ���� ��)
- ��� ���ڸ� 2����Ʈ�� ó���ϸ� �����ڵ� ����̴�.

- VS������ ���߽� ��Ƽ/ �����ڵ带 ���� �⺻������ ������ ����� �Ѵ�
 �����ڵ��� ��쿡�� ���ڿ��� ����ǥ�� ���ΰ� �� �տ� L�� �ٿ��� (L"")�̶�� ǥ���ϰ�
 ��Ƽ����Ʈ ���� ��쿡�� �׳� "" �� ����ϸ� �ȴ�
 �����ڵ�� ���ߵ� ���α׷��� ��Ƽ����Ʈ�� �̽��Ϸ��� �̵� ���ڿ��� ǥ�� �����
 �ٽ� ������� �ϱ� ������ �ſ� �����ϴ�
 �׷��� _T��ũ�θ� ����ؾ� �Ѵ�
 ���ڿ��� ����ǥ�� ���ΰ� �����ڵ忡�� ����� "L"��� "_T"�� ����ϸ� ��ũ�ΰ� �˾Ƽ� 
 ����ȯ�濡 �°� ġȯ���ش�.
*/
#include <tchar.h>
// stdio: ǥ�� ����� ��� ����
#include <stdio.h>
//! C++ ��Ÿ�� ��� ����
#include <time.h>
#include <ctime>
#include <iostream>
/*
- c++11���� �߰��� �ð� ���� ���̺귯�� (STL)
�� �⺻ C ��Ÿ�ӿ��� �����ϴ� time �Լ����� �پ���/ Ȯ��� ����� ����
�� ����: ���е��� ����. (���� �и� �� ����)
	�� time �Լ��� �� ������ ���� ������ �����ϱ� ������ ���е��� ������ �� ����.
�� OS�� ���������� ������ �Ѵ�.
*/
#include <chrono>
#include <random>
#include <vector>
#include <map>
#include <string>
//unordered_map: Hash �ڷᱸ��
// �� �Ϲ��� ��Ȳ���� map ���� �˻��ӵ��� �� ������
// �� �˻� �ӵ��� ���� ������ �ߺ��� �����͸� ������� �ʱ� ����
// �� ��, ���� �����Ͱ� ������(key), �ؽ� �浹�� �߻��� ������ ����� ������ ���� ���ϰ� �߻�
#include <unordered_map>
// cassert: C++ ���α׷����� ��� -> �� ����.. killing process 
#include <cassert> //������ �� �ƴϿ� /����x
//bitset: ��Ʈ ������ �� �� ���� ������ �ִ� �Լ��� �����ϴ� STL
//reset,set,flip,all,any,size ���..
#include <bitset> //STL //bool �ø������
#include <windef.h>
//���� ģ����
#include<algorithm>
//�Լ� ������
//�� bind: Ư�� ���ڿ� ���ؼ��� �Լ��� �����Ű�� ���� ��, Ư�� ���ڿ� Ư�� �Լ��� ������ ��
//�� �Լ� ������ -> �̺�Ʈ-> Ʈ����-> ��������Ʈ(�ݹ�) (��ũ�� �߻��ؾ� ��)-> �׼� Ʈ���� / ������ ����
#include <functional>
#include <fstream>
#include <queue>
#include <deque>

#define _USE_MATH_DEFINES
#include <math.h>
//using std::vector; << �̷��� �ɰ��� ��� 
using namespace std;

//GDI+
#include <ole2.h>



// !D2D/D3D �������
//#include <d2d1.h>
//#include<d2d1helper.h>
//#include <d3dx9.h>
//#include <D3DX11.h>
//#include <d3d11shader.h>
//#include <dinput.h>
//
//#pragma comment(lib, "d3d1.lib")
//#pragma comment(lib, "d3d9.lib")
//#pragma comment(lib, "d3dx9.lib")
//#pragma comment(lib, "d3d11.lib")
//#pragma comment(lib, "d3dx11.lib")
//#pragma comment(lib, "dinput8.lib")
//#pragma comment(lib, "dxguid.lib")
//
//ID2D1Factory*			_ID2DFactory=nullptr;
//ID2D1HwndRenderTarget*	_ID2DRenderTarget=nullptr;
//

/*
precompiled header
Inline �Լ�
- �Լ� �ڵ��� ���� �ð�
*/

//# ����� ���� ��� ���� #

#include "CommonMacroFunction.h"
#include "RandomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "FontManager.h"
//#include "CollisionManager.h"
#include "TimeManager.h"
//#include "TempSoundManager.h"
//#include "ItemManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "INIData.h"
#include "Utils.h"
#include "JsonSaveLoader.h"
//
#include <memory>
#include <mmsystem.h>

using namespace MY_UTIL;

//# �̱��� #
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define FONTMANAGER FontManager::getSingleton()
//#define COLISIONMANAGER CollisionManager::getSingleton()
#define TIMEMANAGER TimeManager::getSingleton()
#define SCENEMANAGER SceneManager::getSingleton()
#define INIDATAMANAGER INIData::getSingleton()
#define SOUNDMANAGER SoundManager::getSingleton()

//#define SOUNDMANAGER TempSoundManager::getSingleton()
//#define ITEMMANAGER ItemManager::getSingleton()

//Ÿ��Ʋ
#define WINNAME		(LPTSTR)(TEXT("WindowsAPI"))

// !��üȭ��
#define FULLSCREEN

#ifdef FULLSCREEN

#define WINSTART_X	0
#define WINSTART_Y	0
#define WINSIZE_X	GetSystemMetrics(SM_CXSCREEN) //GetSystemMetrics()���ڷ� ���޵Ǵ� �ý��� ���� ������ ��ȯ
#define WINSIZE_Y	GetSystemMetrics(SM_CYSCREEN) //SM_CXSCREEN ,SM_CYSCREEN ���� ȭ�� �ػ� ��ȯ(x,y��) 
#define WINSTYLE	WS_POPUPWINDOW | WS_MAXIMIZE

#else

#define WINSTART_X	0
#define WINSTART_Y	0
#define WINSIZE_X	600
#define WINSIZE_Y	800
#define WINSTYLE	WS_CAPTION | WS_SYSMENU
#endif

//# ��ũ�� # (������â �ʱ�ȭ)

//#define WINNAME  (LPTSTR)(TEXT("WindowsAPI"))
//#define WINSTART_X 0
//#define WINSTART_Y 0
//#define WINSIZE_X  1280
//#define WINSIZE_Y  800
//WS_CAPTION : Ÿ��Ʋ�ٸ� ������ ���� �ɼ�
//WS_SYSMENU : ���� ǥ���ٿ� ��Ʈ�� �޴� ���� â
#define WINSTYLE   WS_CAPTION | WS_SYSMENU

//# ��ũ�� �Լ� #	(Ŭ�������� �����Ҵ�� �κ� ����)			//�����ϰ� ����� ������ array�ϰڴ�
#define SAFE_DELETE(p)  {if(p){delete (p); (p)=nullptr;}}     // �̽� \ ��ũ�� ���ٿ�Ģ
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] (p); (p)=nullptr;}}
#define SAFE_RELEASE(p) {if(p){(p)->release();(p)=nullptr;}} 
#define SAFE_RELEASE_SCENE(p) {if(p) {(p)->Release();(p)=nullptr;}}

// # ���� ���� #  // �÷��̾� Ŭ������ �κ��丮 ��õ
extern HINSTANCE _hInstance;
extern HWND _hWnd;
// X ��ǥ�� Y ��ǥ�� ����� ��ǥ�� �����Ҷ� ����Ѵ�.
extern POINT _ptMouse;

//class Bullet;
//class Drops;


/*

* ��������
extern Ű����� �ٸ� ��� / cpp ���� ������ �����ؼ� ���� ���� ����Ѵ�.
�� ��ü ������ �� ���
�� �⺻������ ���������� Ű���带 �����ص� �⺻������ extern ȭ �Ǵ� ��찡 ����.
static extern ����
�� �ʿ信 ���ؼ� ��Ӽ��� �ٲ��� �� ����
extern �� ������ ����
*/
