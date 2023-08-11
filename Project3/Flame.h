#pragma once
#include "GameNode.h"
//#include "Rocket.h"

//모듈화 -> 교체가 가능한 컴포넌트 라고 생각하면 편하다.

/*
일반적인 추상화로 갈지
극 추상화로 갈지 -> 인터페이스화
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

