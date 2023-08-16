#include "Stdafx.h"
#include "Rocket.h"


HRESULT Rocket::init(void)
{

    _image = IMAGEMANAGER->addImage("╥ндо","Resources/Rocket.bmp", 52, 64, true, RGB(255, 0, 255));

    _x = WINSIZE_X / 2;
    _y = 800;

    _rc = RectMakeCenter(_x, _y, _image->getwidth(), _image->getheight());

    _flame = new Flame;
    _flame->init("Resources/Flame.bmp", &_x, &_y);
    _missileM1 = new MissileM1;
    _missileM1->init(10, 500);
	//_spreadMissile = new
    _Weapon = _missileM1;

    //spRocket.push_back(std::shared_ptr<Rocket>(new Rocket));
    return S_OK;
}

void Rocket::release(void)
{
    //SAFE_DELETE(_flame);
}

void Rocket::update(void)
{
    WeaponChange();
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
        //_missile.fire(_x,_y);
        _missileM1->fire(_x+10, _y-60);
    }
    _flame->update();
    //_missile.update();
    _Weapon->update();

}

void Rocket::render(void)
{
    _image->render(getMemDC(), _x, _y);
    _flame->render();
    //_missile.render();
    _Weapon->render();
}

void Rocket::WeaponChange()
{
    if (KEYMANAGER->isOnceKeyDown(VK_F1))
    {
        _Weapon = _missileM1;
    }
    if (KEYMANAGER->isOnceKeyDown(VK_F2))
    {

    }
    if (KEYMANAGER->isOnceKeyDown(VK_F3))
    {
    }
    if (KEYMANAGER->isOnceKeyDown(VK_F4))
    {
    }
    if (KEYMANAGER->isOnceKeyDown(VK_F5))
    {
    }
    if (KEYMANAGER->isOnceKeyDown(VK_F6))
    {
    }
    if (KEYMANAGER->isOnceKeyDown(VK_F7))
    {
    }

}
