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
	float _radius = 50;
	float _angle = 0;
	float _aSpd = 5;
	float _rSpd = 5;

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