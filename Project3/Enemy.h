#pragma once
#include "GameNode.h"

//Enemy(�θ�): ���� �� Ŭ������ ������� �Ϲ� ����, ���� ���� ���� �� �ִ�.
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

	RECT getRect(void) { return _rc; }

	float getX() { return _x; }
	float getY() { return _y; }
	RECT getRC() { return _rc; }

	Enemy(void);
	~Enemy(void);
};

