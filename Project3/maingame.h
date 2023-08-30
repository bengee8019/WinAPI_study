#pragma once
#include "GameNode.h"
#include "INIDataScene.h"

//class Flame;

class maingame :public GameNode
{
private:
	INIDataScene ini;
public:

	HRESULT init();
	void update();
	void render();
	void release();

	maingame() {}
	~maingame() {}
};

