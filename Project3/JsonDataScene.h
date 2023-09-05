#pragma once
#include "GameNode.h"
#include "QuestSample.h"

class JsonDataScene : public GameNode
{
private:
	QuestSample* _QuestSample;

public:
	HRESULT init();
	void release();
	void render();
	void update();

	void questPopUp();
	void currentQuest();

	JsonDataScene();
	~JsonDataScene();
};

