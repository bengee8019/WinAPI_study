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

	Missile() {}
	~Missile() {}
};

//�߻簡 �� ������ ����� ����
class MissileM1 : public GameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;

public:
	HRESULT init(int bulletMax, float range);
	void update();
	void render();
	void release();

	void fire(float x, float y);
	void draw(void);
	void move(void);

	MissileM1() {}
	~MissileM1() {}
};


//
//class Bullets
//{
//
//public:
//	Bullets();
//	~Bullets();
//};
//
