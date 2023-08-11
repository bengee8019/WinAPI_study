#pragma once
#include "GImage.h"

static GImage* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZE_X, WINSIZE_Y);

class GameNode
{
private:
	HDC _hdc;
	bool _managerInit;

public:
	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void update(void);
	virtual void render(void);
	virtual void release(void);
	//virtual void IFunction() abstract;

	//����� + ������� �̹��� ���
	GImage* getBackBuffer(void) { return _backBuffer; }

	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	GameNode();	LRESULT MainProc(HWND hwnd, UINT iMessage, WPARAM wparam, LPARAM lparam);

	virtual ~GameNode();
};

