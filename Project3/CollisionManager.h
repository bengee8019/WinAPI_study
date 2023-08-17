#pragma once
#include "EnemyManager.h"
#include "Bullets.h"

class CollisionManager
{
private:
	vBullet _cVBullet;
	vEnemy _cVEnemy;

	RECT tmpRC;
public:
	HRESULT init();

	void setVBPtr(vBullet& vBPtr) { _cVBullet = vBPtr; }
	void setVEPtr(vEnemy& vEPtr) { _cVEnemy = vEPtr; }

	void collisionCheck();
	CollisionManager() {}
	~CollisionManager() {}
};

