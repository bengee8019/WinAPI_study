#include "Stdafx.h"
#include "Rocket.h"


HRESULT Rocket::init(void)
{

    _image = IMAGEMANAGER->addImage("╥ндо","Resources/Rocket.bmp", 52, 64, true, RGB(255, 0, 255));
	
	_setWeapon = MISSILE;

    _x = WINSIZE_X / 2;
    _y = 800;

    _rc = RectMakeCenter(_x, _y, _image->getwidth(), _image->getheight());

    _flame = new Flame;
    _flame->init("Resources/Flame.bmp", &_x, &_y);
    _Weapon = new MissileM1;
	_Weapon->init(10,500);

	_beam = new Beam;
	_beam->init(1, 0.5);
	_beamIrradiation = false;

    //spRocket.push_back(std::shared_ptr<Rocket>(new Rocket));
    return S_OK;
}

void Rocket::release(void)
{
    //SAFE_DELETE(_flame);
	_beam->release();
	SAFE_DELETE(_beam);
}

void Rocket::update(void)
{
    WeaponChange();
    if (KEYMANAGER->isStayKeyDown(VK_LEFT)&&_rc.left > 0 && _beamIrradiation==false)
    {
        _x -= ROCKET_SPEED;
    }
    if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right < WINSIZE_X&& _beamIrradiation==false)
    {
        _x += ROCKET_SPEED;
    }
    if (KEYMANAGER->isStayKeyDown(VK_UP) && _rc.top > 0 && _beamIrradiation == false)
    {
        _y -= ROCKET_SPEED;
    }
    if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _rc.bottom < WINSIZE_Y && _beamIrradiation == false)
    {
        _y += ROCKET_SPEED;
    }
    _rc = RectMakeCenter(_x, _y, _image->getwidth(), _image->getheight());

    if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
    {
        //_missile.fire(_x,_y);
        _Weapon->fire(_x+10, _y-60);
    }

	if (KEYMANAGER->isOnceKeyDown(VK_F7))
	{
		_setWeapon = MISSILE;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F6))
	{
		_setWeapon = BEAM;
	}

	switch (_setWeapon)
	{
	case BEAM:
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_beamIrradiation = true;
			_beam->fire(_x, _y - 430);
		}
		else _beamIrradiation = false;
		break;
	}
	case MISSILE:
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_Weapon->fire(_x, _y - 430);
		}
		break;
	}
	}
    _flame->update();
    //_missile.update();
    _Weapon->update();
	_beam->update();
}

void Rocket::render(void)
{
    _image->render(getMemDC(), _x, _y);
    _flame->render();
    //_missile.render();
    _Weapon->render();
	_beam->render();
}

void Rocket::removeMissile(int arrNum)
{
	_missileM1->removeBullet(arrNum);
}

void Rocket::WeaponChange()
{
    if (KEYMANAGER->isOnceKeyDown(VK_F1))
    {
		SAFE_DELETE(_Weapon);
		_Weapon = new MissileM1; 
		_Weapon->init(10, 500);
    }
    if (KEYMANAGER->isOnceKeyDown(VK_F2))
    {
		SAFE_DELETE(_Weapon);
		_Weapon = new SpreadMissile;
		_Weapon->init(30, 500);
    }
    if (KEYMANAGER->isOnceKeyDown(VK_F3))
    {
		SAFE_DELETE(_Weapon);
		_Weapon = new MiniRocket;
		_Weapon->init(10, 800);
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
