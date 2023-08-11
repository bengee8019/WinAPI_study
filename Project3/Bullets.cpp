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
		bullet.img->init("Resources/Missile.bmp",);
		bullet.fire = false;
		bullet.speed = 5.0f;

		_vBullet.push_back(bullet);
	}

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
		_viBullet->x = _viBullet->fireX;
		_viBullet->y = _viBullet->fireY;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());

		break;
	}
}

void Missile::draw(void)
{
	//for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	//{

	//}
}

void Missile::move(void)
{
	//for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	//{

	//}
}

//==============================================================

HRESULT MissileM1::init(int bulletMax, float range)
{
	_range = range;
	_bulletMax = bulletMax;

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
	bullet.img->init("Resources/Missile.bmp");
	//bullet.img->init("Resources/.bmp",);
	bullet.speed = 5.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);



}

void MissileM1::draw(void)
{
}

void MissileM1::move(void)
{
}
