#pragma once
#include "Quest.h"

//class Quest;

#pragma region ť
/*
queue

- ť�� ����Ʈ�� �������� ���ð� �ٸ��� ���Լ��� �ڷᱸ��
- ������ �Ͼ�� ���� REAR, ������ �Ͼ�� ���� FRONT
- ����Ʈ ť, �����ٸ�, ����(������), BFS, DFS � ���� ���ȴ�.

�� ť���� ���� ����ϴ� ����Լ�

- front()
	�� ù��° ��� ����

- back()
	�� ������ ��� ����

- push()
	�� ������ ����

- size()
	�� ũ�� ��ȯ

- empty()
	�� �������?
*/
#pragma endregion 

class QuestSample
{
private:
	queue<Quest*> _quest;


public:
	void init(void);
	void questSetup(Quest* pQuest = nullptr);

	queue<Quest*>* getQuest() { return &this->_quest; }


	QuestSample() {}
	~QuestSample() {}
};

