#include "Stdafx.h"
#include "ProgressBar.h"

HRESULT ProgressBar::init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, width, height);
	_progressBarDown = IMAGEMANAGER->addImage("BarDown", "Resources/HpBarDown.bmp", 0, 0, width, height, true, RGB(255, 0, 255));
	_progressBarUp = IMAGEMANAGER->addImage("BarUp", "Resources/HpBarUp.bmp", 0, 0, width, height, true, RGB(255, 0, 255));

	width = _progressBarDown->getwidth();

	return S_OK;
}

void ProgressBar::release(void)
{
}

void ProgressBar::update(void)
{
	_rc = RectMakeCenter(_x, _y, _progressBarDown->getwidth(),
		_progressBarDown->getFrameHeight());
}

void ProgressBar::render(void)
{
	_progressBarDown->render(getMemDC(),
		_rc.left + _progressBarDown->getwidth() / 2,
		_y + _progressBarDown->getFrameHeight() / 2,
		0, 0, _progressBarDown->getwidth(),
		_progressBarDown->getheight());
	_progressBarUp->render(getMemDC(),
		_rc.left + _progressBarDown->getwidth() / 2,
		_y + _progressBarDown->getFrameHeight() / 2,
		0, 0, _width,
		_progressBarDown->getheight());

}

void ProgressBar::setGauge(float currentScore, float maxScore)
{
	_width = (currentScore / maxScore) * _progressBarDown->getwidth();

}
