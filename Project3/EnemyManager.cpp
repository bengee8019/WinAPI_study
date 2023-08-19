#include "Stdafx.h"
#include "EnemyManager.h"
#include "Minion.h"

//########
//cpp는 참조를 하고 넘어간다.	
//헤더는 싹 복사과정을 필요로 한다. 


//벡터에 렌더러 객체 pushback
void EnemyManager::addHitRenderer(int arrNum)
{
	hitRenderer* tmpHitRenderer = new hitRenderer;
	tmpHitRenderer->init(_vMinion[arrNum]->getX(), _vMinion[arrNum]->getY());
	_vHitRenderer.push_back(tmpHitRenderer);
}

void EnemyManager::removeMinion(int arrNum)
{
	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

HRESULT EnemyManager::init(void)
{
	IMAGEMANAGER->addFrameImage("해파리","Resources/JellyFish.bmp", 0.0f, 0.0f, 1140 , 47 , 19 , 1 , true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("히트", "Resources/hitFrame.bmp", 570, 219, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("적총알", "Resources/bullet_laser.bmp", 120, 120, true, RGB(255, 0, 255));

	setMinion();
	return S_OK;
}

void EnemyManager::release(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->release();
		SAFE_DELETE(*_viMinion);
	}
	for (_viHitRenderer = _vHitRenderer.begin(); _viHitRenderer != _vHitRenderer.end(); ++_viHitRenderer)
	{
		(*_viHitRenderer)->release();
	}
}

void EnemyManager::update(void)
{
	//미니언 업데이트
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}
	//히트렌더러 업데이트
	for (_viHitRenderer = _vHitRenderer.begin(); _viHitRenderer != _vHitRenderer.end();)
	{
		if (!(*_viHitRenderer)->getNowAnimate())
		{
			_viHitRenderer = _vHitRenderer.erase(_viHitRenderer);
		}
		else
		{
			(*_viHitRenderer)->update();
			_viHitRenderer++;
		}
	}
}

void EnemyManager::render(void)
{
	//미니언 렌더
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}
	//히트 렌더러 렌더
	for (_viHitRenderer = _vHitRenderer.begin(); _viHitRenderer != _vHitRenderer.end(); ++_viHitRenderer)
	{
		(*_viHitRenderer)->render(getMemDC());
	}
}


void EnemyManager::setMinion()
{
	setNormalMinion(120, 50, 10, 5, 1200, 400);
	setSpinMinion(WINSIZE_X / 2, 400, 10, 500);
	setSpinMinion(WINSIZE_X / 2, 400, 10, 400);
	setSpinMinion(WINSIZE_X / 2, 400, 10, 300);
	setSpinMinion(WINSIZE_X / 2, 400, 10, 200);
	setWaveMinion(0, 100, 10, 3, WINSIZE_X+100, 400);
	setEclipseMinion(WINSIZE_X / 2, 100, 60.0f, 1, 800);
}

void EnemyManager::setNormalMinion(int x, int y, int windex, int hindex, int width, int height)
{
	float wBetween = width / windex;
	float hBetween = height / hindex;

	for (int i = 0; i < hindex; i++)
	{
		for (int j = 0; j < windex; j++)
		{
			Enemy* jellyFish;
			jellyFish = new Minion;
			jellyFish->init("해파리", PointMake(x + j * wBetween, y + i * hBetween));
			_vMinion.push_back(jellyFish);
		}
	}
}

void EnemyManager::setSpinMinion(int x, int y, int num, int radius)
{
	float tmpAngle = 360 / num;
	for (int i = 0; i < num; i++)
	{
		Enemy* jellyFish;
		jellyFish = new SpinMinion;
		jellyFish->init("해파리", PointMake(x+radius*cosf(DEG_TO_RAD*tmpAngle*i), y + radius * sinf(DEG_TO_RAD*tmpAngle * i)));
		_vMinion.push_back(jellyFish);
	}
}


void EnemyManager::setWaveMinion(int x, int y, int windex, int hindex, int width, int height)
{
	float wBetween = width / windex;
	float hBetween = height / hindex;
	for (int i = 0; i < hindex; i++)
	{
		for (int j = 0; j < windex; j++)
		{
			Enemy* jellyFish;
			jellyFish = new WaveMinion;
			jellyFish->init("해파리", PointMake((i%2)*wBetween/2+x + j * wBetween, y + i * hBetween));
			_vMinion.push_back(jellyFish);
		}
	}
}

void EnemyManager::setEclipseMinion(int x, int y, float aRange, int num, int radius)
{
	float tmpAngle = aRange / num;
	for (int i = 0; i < num; i++)
	{
		Enemy* jellyFish;
		jellyFish = new EclipseMinion;
		jellyFish->init("해파리", PointMake(x + radius * cosf(DEG_TO_RAD * tmpAngle * i), y + radius * sinf(DEG_TO_RAD * tmpAngle * i)));
		_vMinion.push_back(jellyFish);
	}
	
}
//
//POINT EnemyManager::findTargetPoint(POINT& pt)
//{
//	int tmpDist = 1000;
//	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
//	{
//		tmpDist = MY_UTIL::getDistance(pt.x, pt.y, (*_viMinion)->getX(), (*_viMinion)->getY());
//	}
//
//	return POINT();
//}

