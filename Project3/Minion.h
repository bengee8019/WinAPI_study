#pragma once
#include "Enemy.h"

class Minion : public Enemy
{
public:

	Minion();
	~Minion();
};

class SpinMinion :public Enemy
{
private:
	float _radius;
	float _angle;
	float _aSpd;
	float _rSpd;

public:

	void Move();
	SpinMinion();
	~SpinMinion();

};

class WaveMinion :public Enemy
{
private:

public:

	void Move();
	WaveMinion();
	~WaveMinion();

};