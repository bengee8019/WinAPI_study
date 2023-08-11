#pragma once
#include "GameNode.h"
#include "Rocket.h"
#include "TileMap.h"


//class Flame;

class maingame :public GameNode
{
private:
	GameNode* _GN;
	Rocket* _rocket;
	TileMap* _tileMap;

public:

	HRESULT init();
	void update();
	void render();
	void release();

	maingame() {}
	~maingame() {}
};

