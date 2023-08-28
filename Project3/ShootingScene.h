#pragma once
#include "GameNode.h"
#include "Rocket.h"
//#include "TileMap.h"
#include "EnemyManager.h"
//#include "AniScene.h"
class ShootingScene :public GameNode
{
private:
	//GameNode* _GN;
	Rocket* _rocket;
	EnemyManager* _em;

	float _x, _y;
	RECT rc;
public:

	HRESULT init();
	void update();
	void render();
	void release();

	virtual void collision(void);

	ShootingScene() {}
	~ShootingScene() {}
};

