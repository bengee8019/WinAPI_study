#pragma once
#include "GameNode.h"
#define BULLET_COUNT 10
//����� ������!
//����Ѱ� ����
struct tagBullet
{
	GImage* img;
	RECT rc;
	int radius;
	int count;

	//utills �� ������ ��ɿ� ������ �� �ֵ���
	float x, y;
	float fireX, fireY;

	//
	float angle;
	float speed;
	bool fire;

};
typedef vector<tagBullet> vBullet;
typedef vector<tagBullet>::iterator iterBullet;

//��ü�� �����Ѵ�.

//�迭ó�� �̸� ������ �صΰ� �߻�
class Missile : public GameNode
{
private:
	// ���� �������� ��Ȯ���� �ʱ� ������ stl vector �� �����ϴ�.
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
	// ���� �������� ��Ȯ���� �ʱ� ������ stl vector �� �����ϴ�.
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


//�߻簡 �� ������ ����� ����
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