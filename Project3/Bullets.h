#pragma once
#include "GameNode.h"
#define BULLET_COUNT 10
//기능을 묶었다!
//비슷한건 묶자
struct tagBullet
{
	GImage* img;
	RECT rc;
	int radius;
	int count;

	//utills 에 구현한 기능에 적용할 수 있도록
	float x, y;
	float fireX, fireY;

	//
	float angle;
	float speed;
	bool fire;

};

//객체로 정의한다.

//배열처럼 미리 장전을 해두고 발사
class Missile : public GameNode
{
private:
	// 언제 삭제될지 명확하지 않기 때문에 stl vector 가 적합하다.
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	float _BulletTick;

public:
	HRESULT init(int bulletMax, float range);
	void update();
	void render();
	void release();

	void fire(float x, float y);
	void draw(void);
	void move(void);

	Missile() {}
	~Missile() {}
};

//발사가 될 때마다 만들고 삭제
class MissileM1 : public GameNode
{
protected:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;
	float _BulletTick;

public:
	HRESULT init(int bulletMax, float range);
	void update();
	void render();
	void release();

	virtual void fire(float x, float y);
	virtual void draw(void);
	virtual void move(void);

	MissileM1() {}
	~MissileM1() {}
};

class SpreadMissile : public MissileM1
{
private:
public:

	void fire(float x, float y);
	void move(void);

	SpreadMissile();
	~SpreadMissile();
};

class MiniRocket : public MissileM1
{
private:
public:

	void fire(float x, float y);
	void move(void);

	MiniRocket();
	~MiniRocket();
};

class TrackerMissile : public MissileM1
{
private:
public:

	void fire(float x, float y);
	void move(void);
	float findEnemy()

	TrackerMissile();
	~TrackerMissile();
};