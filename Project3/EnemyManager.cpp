#include "Stdafx.h"
#include "EnemyManager.h"
#include "Minion.h"

//########
//cpp는 참조를 하고 넘어간다.	
//헤더는 싹 복사과정을 필요로 한다. 


EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

HRESULT EnemyManager::init(void)
{
	IMAGEMANAGER->addFrameImage("해파리","Resources/JellyFish.bmp", 0.0f, 0.0f, 1140 , 47 , 19 , 1 , true, RGB(255, 0, 255));

	setMinion(100,100,44,20,40,40);

	return S_OK;
}

void EnemyManager::release(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->release();
		SAFE_DELETE(*_viMinion);
	}
}

void EnemyManager::update(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}
}

void EnemyManager::render(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}
}

void EnemyManager::setMinion(int x, int y, int windex, int hindex, int width, int height)
{
	for (int i = 0; i < hindex; i++)
	{
		for (int j = 0; j < windex; j++)
		{
			Enemy* jellyFish;
			jellyFish = new Minion;
			jellyFish->init("해파리", PointMake(x + j * width, y + i * height));
			_vMinion.push_back(jellyFish);
		}
	}
}

void EnemyManager::setSpinMinion(int x, int y, int num, int radius, float rspd, float aspd)
{
	float tmpAngle = 360 / num;
	for (int i = 0; i < num; i++)
	{
		Enemy* jellyFish;
		jellyFish = new SpinMinion;
		jellyFish->init("해파리", PointMake(x+radius*cosf(tmpAngle*i), y + radius * sinf(tmpAngle * i)));
		_vMinion.push_back(jellyFish);
	}
}


