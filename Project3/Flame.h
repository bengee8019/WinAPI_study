#pragma once
#include "GameNode.h"
//#include "Rocket.h"

//���ȭ -> ��ü�� ������ ������Ʈ ��� �����ϸ� ���ϴ�.

/*
�Ϲ����� �߻�ȭ�� ����
�� �߻�ȭ�� ���� -> �������̽�ȭ
*/
#define FLAME_COUNT			9

class Flame : public GameNode
{
private:
	GImage* _image;
	RECT _rc;

	float* _x;
	float* _y;

	float _flameTick;


public:
	HRESULT init(const char* imageName, float* x, float* y);
	void update();
	void render();
	void release();
	Flame* selfReturn(void) { return this; }
	//void setPRocket(Rocket* pRocket) { _rocket = pRocket; }


	Flame();
	~Flame();
};

