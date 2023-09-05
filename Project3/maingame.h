#pragma once
#include "GameNode.h"
#include "INIDataScene.h"
#include "JsonDataScene.h"

//class Flame;

class maingame :public GameNode
{
private:
	INIDataScene ini;
	JsonDataScene jscene;
public:

	HRESULT init();
	void update();
	void render();
	void release();

	maingame() {}
	~maingame() {}
};

