#include "Stdafx.h"
#include "Flame.h"

HRESULT Flame::init(const char* imageName, float* x, float* y)
{

	_image = IMAGEMANAGER->addFrameImage("ºÒ²É", imageName, 432, 297, 9, 1, true, RGB(255, 0, 255));

	_x = x;
	_y = y;

	_rc = RectMakeCenter((int)_x, (int)_y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

void Flame::update()
{

	//flame_count
	if (FLAME_COUNT +_flameTick <= GetTickCount())
	{
		_flameTick = GetTickCount();
		_image->setFrameX(_image->getFrameX() + 1);

		if (_image->getFrameX() >= _image->getMaxFrameX())
		{
			_image->setFrameX(0);
		}
	}
	_rc = RectMakeCenter(*_x, *_y, _image->getFrameWidth(), _image->getFrameHeight());

}



void Flame::render()
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top,_image->getFrameX(), _image->getFrameY());
}

void Flame::release()
{
}

Flame::Flame()
{

}



Flame::~Flame()
{
}
