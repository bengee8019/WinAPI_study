#include "Stdafx.h"
#include "Enemy.h"


//GImage* _image;
//RECT _rc;
//
//int _CurrentFrameX;
//int _CurrentFrameY;
//
//float _x, _y;
//float _rndTimeCount;
//float _worldTimeCount;

Enemy::Enemy(void) : _rc(RectMake(0,0,0,0)),
_CurrentFrameX(0),
_CurrentFrameY(0),
_x(0.0f),
_y(0.0f),
_rndTimeCount(0.0f),
_worldTimeCount(0.0f)
{
}

Enemy::~Enemy(void)
{
}


HRESULT Enemy::init(void)
{
	return S_OK;
}

HRESULT Enemy::init(const char* imageName, POINT position)
{
	_worldTimeCount = GetTickCount();
	_rndTimeCount = RND->getFromFloatTo(50, 150);

	_image = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(position.x, position.y, 60, 47);
	return S_OK;
}

void Enemy::release(void)
{
}

void Enemy::update(void)
{
	move();
}

void Enemy::render(void)
{
	draw();
	animation();
}

//적마다 움직임이 다르기 때문에
//개방 폐쇄의 원칙!!
void Enemy::move(void)
{

}

void Enemy::draw(void)
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top, _CurrentFrameX, _CurrentFrameY);
}

void Enemy::animation(void)
{
	if (_rndTimeCount + _worldTimeCount <= GetTickCount())
	{
		_worldTimeCount = GetTickCount();
		_CurrentFrameX++;

		if (_image->getMaxFrameX() < _CurrentFrameX)
		{
			_CurrentFrameX = 0;
		}
	}
}

