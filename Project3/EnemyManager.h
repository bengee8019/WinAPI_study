#pragma once
#include "GameNode.h"
#include "Enemy.h"


class EnemyManager : public GameNode
{
private:
	typedef vector<Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(int x, int y, int windex, int hindex, int width, int height);
	void setSpinMinion(int x, int y, int num, int radius, float rspd, float aspd);

	EnemyManager();
	~EnemyManager();
};

