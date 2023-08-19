#include "Stdafx.h"
#include "hitRenderer.h"

HRESULT hitRenderer::init(float x, float y)
{
	_nowAnimate = true;
	_x = x;
	_y = y;
	_frameCount = 0;
	_nowFrame = 0;
	return S_OK;
}

void hitRenderer::update()
{
	if (_frameCount < 10)
	{
		_nowFrame = 0;
	}
	else if (_frameCount < 20)
	{
		_nowFrame = 1;
	}
	else if (_frameCount < 30)
	{
		_nowFrame = 2;
	}
	else
	{
		_nowAnimate = false;
	}
	_frameCount++;
}

void hitRenderer::render(HDC hdc)
{
	if (_nowAnimate)
	{
		IMAGEMANAGER->frameRender("히트", hdc, _x - IMAGEMANAGER->findImage("히트")->getFrameWidth() / 2, _y - IMAGEMANAGER->findImage("히트")->getFrameHeight() / 2, _nowFrame, 0);
	}
}

void hitRenderer::release()
{
}
