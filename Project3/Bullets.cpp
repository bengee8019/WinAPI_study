#include "Stdafx.h"
#include "Bullets.h"



HRESULT Missile::init(int bulletMax, float range)
{
	_range = range;
	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		//ZeroMemory vs memset

		ZeroMemory(&bullet, sizeof(tagBullet));

		bullet.img = new GImage;
		bullet.img->init("Resources/Missile.bmp",416,64,13,1,true,RGB(255,0,255));
		bullet.fire = false;
		bullet.speed = 5.0f;

		_vBullet.push_back(bullet);
	}
	_BulletTick = 7.0f;

	return S_OK;
}

void Missile::update()
{
	move();
}

void Missile::render()
{
	draw();
}

void Missile::release()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		SAFE_DELETE(_viBullet->img);
	}

	_vBullet.clear();
}

void Missile::fire(float x, float y)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->fire) continue;
		_viBullet->fire = true;
		_viBullet->fireX = x;
		_viBullet->fireY = y;
		_viBullet->x = _viBullet->fireX;
		_viBullet->y = _viBullet->fireY;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());

		break;
	}
}

void Missile::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;

		_viBullet->img->frameRender(getMemDC(), _viBullet->x, _viBullet->y, _viBullet->img->getFrameX(), _viBullet->img->getFrameY());
	}
}

void Missile::move(void)
{
	//MY_UTIL::getDistance();

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y) >= _range)
		{
			_viBullet->fire = false;
		}

		if (BULLET_COUNT + _BulletTick <= GetTickCount())
		{
			_BulletTick = GetTickCount();
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);

			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}
		}
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
	}
}

//==============================================================

HRESULT MissileM1::init(int bulletMax, float range)
{
	_range = range;
	_bulletMax = bulletMax;
	_BulletTick = 7.0f;
	return S_OK;
}

void MissileM1::update()
{
	move();
}

void MissileM1::render()
{
	draw();
}

void MissileM1::release()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		SAFE_DELETE(_viBullet->img);
	}
}

void MissileM1::fire(float x, float y)
{
	if (_bulletMax <= _vBullet.size()) return;

	tagBullet bullet;
	//ZeroMemory vs memset
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = new GImage;
	bullet.img->init("Resources/Missile.bmp", 416, 64, 13, 1, true, RGB(255, 0, 255));
	//bullet.img->init("Resources/.bmp",);
	bullet.speed = 5.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	//bullet.fire = true;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);
}

void MissileM1::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->img->frameRender(getMemDC(), _viBullet->x, _viBullet->y, _viBullet->img->getFrameX(), _viBullet->img->getFrameY());
	}
}

void MissileM1::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (BULLET_COUNT + _BulletTick <= GetTickCount())
		{
			_BulletTick = GetTickCount();
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);

			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}
		}
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
		if (MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y) >= _range)
		{
			SAFE_DELETE(_viBullet->img);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else
		{
			_viBullet++;
		}
	}
}
