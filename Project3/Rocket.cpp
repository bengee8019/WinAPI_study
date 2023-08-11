#include "Stdafx.h"
#include "Rocket.h"


HRESULT Rocket::init(void)
{

    _image = IMAGEMANAGER->addImage("╥ндо","Resources/Rocket.bmp", 52, 64, true, RGB(255, 0, 255));

    _x = WINSIZE_X / 2;
    _y = WINSIZE_Y / 2;

    _rc = RectMakeCenter(_x, _y, _image->getwidth(), _image->getheight());

    _flame = new Flame;
    _flame->init("Resources/Flame.bmp", &_x, &_y);
	_missile.init(5, 500);

    //spRocket.push_back(std::shared_ptr<Rocket>(new Rocket));
    return S_OK;
}

void Rocket::release(void)
{
    //SAFE_DELETE(_flame);
}

void Rocket::update(void)
{
    if (KEYMANAGER->isStayKeyDown(VK_LEFT)&&_rc.left > 0)
    {
        _x -= ROCKET_SPEED;
    }
    if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right < WINSIZE_X)
    {
        _x += ROCKET_SPEED;
    }
    if (KEYMANAGER->isStayKeyDown(VK_UP) && _rc.top > 0)
    {
        _y -= ROCKET_SPEED;
    }
    if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _rc.bottom < WINSIZE_Y)
    {
        _y += ROCKET_SPEED;
    }
    _rc = RectMakeCenter(_x, _y, _image->getwidth(), _image->getheight());

    if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
    {

    }
    _flame->update();

}

void Rocket::render(void)
{
    _image->render(getMemDC(), _x, _y);
    _flame->render();
}
