#pragma once
#include "SingletonBase.h"
#include "EnemyManager.h"
#include "Bullets.h"

class CollisionManager : public SingletonBase<CollisionManager>
{
private:
	vBullet _cVBullet;
	vEnemy _cVEnemy;

	RECT tmpRC;

public:

	vector<std::function<void(int a)>> vfpContainer;
	HRESULT init();

	void setVBPtr(vBullet& vBPtr) { _cVBullet = vBPtr; }
	void setVEPtr(vEnemy& vEPtr) { _cVEnemy = vEPtr; }
	void addFP(void(*fp)(int a)) { vfpContainer.push_back(*fp); }


	void collisionCheck();
	CollisionManager() {}
	~CollisionManager() {}
};

