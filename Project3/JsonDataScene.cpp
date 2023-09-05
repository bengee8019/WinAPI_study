#include "Stdafx.h"
#include "JsonDataScene.h"

HRESULT JsonDataScene::init()
{
	_QuestSample = new QuestSample;
	_QuestSample->init();

    return S_OK;
}

void JsonDataScene::release()
{
	SAFE_DELETE(_QuestSample);
}

void JsonDataScene::render()
{
	questPopUp();
}

void JsonDataScene::update()
{
}

void JsonDataScene::questPopUp()
{
	char str[256];

	queue<Quest*>* temp = _QuestSample->getQuest();
	Quest* node = temp->front();

	sprintf(str, "%s", node->getName().c_str());
	TextOut(getMemDC(), 200, 150, str, strlen(str));

	sprintf(str, "����: %s", node->getDescription().c_str());
	TextOut(getMemDC(), 200, 200, str, strlen(str));

	sprintf(str, "���� �̸�: %s", node->getMonsterName().c_str());
	TextOut(getMemDC(), 200, 250, str, strlen(str));

	sprintf(str, "óġ�ؾ� �� ����: %d ����", node->getMonster());
	TextOut(getMemDC(), 200, 300, str, strlen(str));

	sprintf(str, "����Ʈ üũ: %s", node->getQuestCheck().c_str());
	TextOut(getMemDC(), 200, 350, str, strlen(str));

	sprintf(str, "���� ����ġ: %d", node->getExp());
	TextOut(getMemDC(), 200, 400, str, strlen(str));

	sprintf(str, "���� ������: %s", node->getItem().c_str());
	TextOut(getMemDC(), 200, 450, str, strlen(str));

	sprintf(str, "���� ���: %d", node->getGold());
	TextOut(getMemDC(), 200, 500, str, strlen(str));

	//sprintf(str, "%s", node->getName().c_str());
	//TextOut(getMemDC(), 200, 150, str, strlen(str));



}

void JsonDataScene::currentQuest()
{
}

JsonDataScene::JsonDataScene()
{
}

JsonDataScene::~JsonDataScene()
{
}
