#pragma once
#include "Enemy.h"

class Minion : public Enemy
{
private:
	int _count;
	bool _switch;

public:
	void move(void);
	Minion();
	~Minion();
};

class SpinMinion : public Enemy
{
private:
	POINT originPoint;
	float _angle;
	float _dist;
	float _aSpd;
	float _rSpd;
	bool _tmpSwitch;

public:
	void move(void);
	SpinMinion();
	~SpinMinion();

};

class WaveMinion : public Enemy
{
private:
	float _magnitude;
	float _angle;
	float _aSpd;
	float _spd;

public:
	void move(void);
	WaveMinion();
	~WaveMinion();

};

class EclipseMinion : public Enemy
{
private:
	POINT originPoint;
	float _lRadius;
	float _sRadius;
	float _angle;
	float _aSpd;

public:
	void move(void);
	EclipseMinion();
	~EclipseMinion();

};