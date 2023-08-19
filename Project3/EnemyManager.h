#pragma once
#include "GameNode.h"
#include "Enemy.h"
#include "hitRenderer.h"
#include "Bullets.h"


typedef vector<Enemy*> vEnemy;
typedef vector<Enemy*>::iterator viEnemy;


class EnemyManager : public GameNode
{
private:
	vEnemy _vMinion;
	viEnemy _viMinion;

	vector<hitRenderer*> _vHitRenderer;
	vector<hitRenderer*>::iterator _viHitRenderer;

	vector<MissileM1*> _vEBullet;
	vector<MissileM1*>::iterator _viEBullet;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setMinion();
	void setNormalMinion(int x, int y, int windex, int hindex, int width, int height);
	void setSpinMinion(int x, int y, int num, int radius);
	void setWaveMinion(int x, int y, int windex, int hindex, int width, int height);
	void setEclipseMinion(int x, int y, float aRange, int num, int radius);
	//POINT findTargetPoint(const POINT& pt);
	//
	//std::function<POINT(const POINT&)> fpFindTarget = findTargetPoint;

	void addHitRenderer(int arrNum);
	void removeMinion(int arrNum);

	vector<Enemy*> getMinions(void) { return _vMinion; }



	EnemyManager();
	~EnemyManager();
};

