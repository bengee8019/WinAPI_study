#pragma once
#include "GameNode.h"

//Enemy(부모): 적은 이 클래스를 기반으로 일반 몬스터, 보스 등을 만들 수 있다.
class Enemy : public GameNode
{
protected:
	GImage* _image;
	RECT _rc;

	int _CurrentFrameX;
	int _CurrentFrameY;

	float _x, _y;
	float _rndTimeCount;
	float _worldTimeCount;

	float _rndFireCount;
	float _bulletFireCount;

	int _shotCooldown;

public:
	HRESULT init(void);
	HRESULT init(const char* imageName, POINT position);


	void release(void);
	void update(void);
	void render(void);

	virtual void move(void);
	void draw(void);
	void shoot(void);
	void animation(void);

	bool bulletCountFire(void);

	RECT getRect(void) { return _rc; }

	float getX() { return _x; }
	float getY() { return _y; }
	RECT getRC() { return _rc; }

	Enemy(void);
	~Enemy(void);
};

