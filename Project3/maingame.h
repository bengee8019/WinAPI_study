#pragma once
#include "GameNode.h"
#include "Rocket.h"


//class Flame;

class maingame :public GameNode
{
private:
	Rocket* _rocket;

public:

	HRESULT init();
	void update();
	void render();
	void release();

	maingame() {}
	~maingame() {}
};

