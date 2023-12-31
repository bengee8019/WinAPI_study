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
typedef vector<tagBullet> vBullet;
typedef vector<tagBullet>::iterator iterBullet;

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

	vector<tagBullet> getBullet(void){ return _vBullet; }
	void removeBullet(int arrNum);


	Missile() {}
	~Missile() {}
};

class Beam : public GameNode
{
private:
	// 언제 삭제될지 명확하지 않기 때문에 stl vector 가 적합하다.
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	typedef vector<tagBullet> vBullet;
	typedef vector<tagBullet>::iterator iterBullet;

	float _range;
	int _bulletMax;
	float _BulletTick;

public:
	HRESULT init(int bulletMax, float range);
	void update();
	void render();
	void release();

	void fire(float x, float y);
	void draw(void);
	void move(void);

	vector<tagBullet> getBullet(void) { return _vBullet; }

	Beam() {}
	~Beam() {}
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

	virtual vector<tagBullet> getBullet(void) { return _vBullet; }
	void removeBullet(int arrNum);
	void clearBullet();

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

//class TrackerMissile : public MissileM1
//{
//private:
//public:
//
//	void fire(float x, float y);
//	void move(void);
//	float findEnemy()
//
//	TrackerMissile();
//	~TrackerMissile();
//};


//공용 총알 (쏠때마다 만들고 삭제)
class Bullet : public GameNode
{
private:
	// 언제 삭제될지 명확하지 않기 때문에 stl vector 가 적합하다.
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	int _bulletMax;
	float _range;

public:
	HRESULT init(const char* imageName, int bulletMax, float range);
	void update();
	void render();
	void release();

	void fire(float x, float y, float angle, float speed);
	void draw(void);
	void move(void);
	void removeBullet(int arrNum);

	vector<tagBullet> getBullet(void) { return _vBullet; }


	Bullet(void) {}
	virtual ~Bullet() {}
};
