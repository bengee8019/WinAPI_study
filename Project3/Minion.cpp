#include "Stdafx.h"
#include "Minion.h"

void Minion::move(void)
{
	if (_count > 200)
	{
		_switch = !_switch;
		_count = 0;
	}
	if (_switch)
	{
		_x += 3;
	}
	else
	{
		_x -= 3;
	}
	_count++;
}

Minion::Minion() : _switch(true),_count(0) {
	//! Do Nothing
}

Minion::~Minion() {
	//! Do Nothing
}
//==================================

void SpinMinion::move(void)
{
	_angle = MY_UTIL::getAngle(originPoint.x, originPoint.y, _x, _y);
	_dist = MY_UTIL::getDistance(originPoint.x, originPoint.y, _x, _y);
	if (_dist <= 5)
	{
		_tmpSwitch = true;
	}
	if(_dist >=410)
	{
		_tmpSwitch = false;
	}
	if(_tmpSwitch)
	{
		_dist += _rSpd;
	}
	else
	{
		_dist -= _rSpd;
	}
	_angle += _aSpd;
	_x = originPoint.x + _dist * cosf(_angle);
	_y = originPoint.y + _dist * sinf(_angle);
}

SpinMinion::SpinMinion() : originPoint({ WINSIZE_X / 2 ,400 }), _aSpd(2 * PI / 360), _rSpd(3.0f), _tmpSwitch(true)
{
}

SpinMinion::~SpinMinion()
{
}
//==================================

void WaveMinion::move(void) 
{
	if (_x >= WINSIZE_X+50)
	{
		_x = -50;
	}
	_angle += _aSpd;
	_x += _spd;
	_y += _magnitude * sinf(_angle);
}

WaveMinion::WaveMinion() : _magnitude(5), _angle(0.0f), _aSpd(2 * PI / 180), _spd(5)
{
}

WaveMinion::~WaveMinion()
{
}

void EclipseMinion::move(void)
{
	//_angle = MY_UTIL::getAngle(originPoint.x, originPoint.y, _x, _y);
	_angle += _aSpd;
	_x = originPoint.x + _lRadius * cosf(_angle) - _sRadius * sinf(_angle);
	_y = originPoint.y + _lRadius * cosf(_angle) + _sRadius * sinf(_angle);
	cout << _angle << endl;
}

EclipseMinion::EclipseMinion(): originPoint({ 400 ,0 }), _angle(0.0f), _lRadius(800), _sRadius(200), _aSpd(2 * PI / 180)
{
}

EclipseMinion::~EclipseMinion()
{
}
