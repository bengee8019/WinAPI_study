#pragma once
#include "GameNode.h"
#include "Rocket.h"
//#include "TileMap.h"
#include "EnemyManager.h"


class GameManager :public GameNode
{
private:
	GameNode* _GN;
	Rocket* _rocket;
	//TileMap* _tileMap;
	EnemyManager* _em;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();

	virtual void collision(void);


	GameManager() {}
	~GameManager() {}

};

