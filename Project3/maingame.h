#pragma once
#include "GameNode.h"


//class Flame;

class maingame :public GameNode
{
private:
public:

	HRESULT init();
	void update();
	void render();
	void release();

	maingame() {}
	~maingame() {}
};

