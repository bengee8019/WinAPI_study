#include "Stdafx.h"
#include "Bullets.h"



HRESULT Missile::init(int bulletMax, float range)
{
	_range = range;
	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		//ZeroMemory vs memset
		ZeroMemory(&bullet, sizeof(tagBullet));
		bullet.img = new GImage;
		bullet.img->init("Resources/Missile.bmp",416,64,13,1,true,RGB(255,0,255));
		bullet.fire = false;
		bullet.speed = 5.0f;
		_vBullet.push_back(bullet);
	}
	_BulletTick = 7.0f;

	return S_OK;
}

void Missile::update()
{
	move();
}

void Missile::render()
{
	draw();
}

void Missile::release()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		SAFE_DELETE(_viBullet->img);
	}

	_vBullet.clear();
}

void Missile::fire(float x, float y)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->fire) continue;
		_viBullet->fire = true;
		_viBullet->fireX = x;
		_viBullet->fireY = y;
		_viBullet->x = _viBullet->fireX;
		_viBullet->y = _viBullet->fireY;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());

		break;
	}
}

void Missile::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;

		_viBullet->img->frameRender(getMemDC(), _viBullet->x, _viBullet->y, _viBullet->img->getFrameX(), _viBullet->img->getFrameY());
	}
}

void Missile::move(void)
{
	//MY_UTIL::getDistance();

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y) >= _range)
		{
			_viBullet->fire = false;
		}

		if (BULLET_COUNT + _BulletTick <= GetTickCount())
		{
			_BulletTick = GetTickCount();
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);

			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}
		}
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
	}
}

void Missile::removeBullet(int arrNum)
{
	SAFE_DELETE(_vBullet[arrNum].img);

	_vBullet.erase(_vBullet.begin() + arrNum);
}

//==============================================================

HRESULT MissileM1::init(int bulletMax, float range)
{
	_range = range;
	_bulletMax = bulletMax;
	_BulletTick = 7.0f;
	return S_OK;
}

void MissileM1::update()
{
	move();
}

void MissileM1::render()
{
	draw();
}

void MissileM1::release()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->img->release();
		SAFE_DELETE(_viBullet->img);
	}
}

void MissileM1::fire(float x, float y)
{
	if (_bulletMax <= _vBullet.size()) return;

	tagBullet bullet;
	//ZeroMemory vs memset
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = new GImage;
	bullet.img->init("Resources/Missile.bmp", 416, 64, 13, 1, true, RGB(255, 0, 255));
	//bullet.img->init("Resources/.bmp",);
	bullet.speed = 5.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	//bullet.fire = true;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);
}

void MissileM1::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->img->frameRender(getMemDC(), _viBullet->x, _viBullet->y, _viBullet->img->getFrameX(), _viBullet->img->getFrameY());
	}
}

void MissileM1::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (BULLET_COUNT + _BulletTick <= GetTickCount())
		{
			_BulletTick = GetTickCount();
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);

			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}
		}
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
		if (MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y) >= _range)
		{
			SAFE_DELETE(_viBullet->img);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else
		{
			_viBullet++;
		}
	}
}

void MissileM1::removeBullet(int arrNum)
{
 	//SAFE_DELETE(_vBullet[arrNum].img);

	_vBullet.erase(_vBullet.begin() + arrNum);
}

void MissileM1::clearBullet()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		SAFE_DELETE(_viBullet->img);
		_viBullet = _vBullet.erase(_viBullet);
	}
}



void SpreadMissile::fire(float x, float y)
{
	if (_bulletMax <= _vBullet.size()) return;
	for (int i = 0; i < 3; i++)
	{
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet));

		bullet.img = new GImage;
		bullet.img->init("Resources/Missile.bmp", 416, 64, 13, 1, true, RGB(255, 0, 255));
		bullet.speed = 5.0f;
		bullet.x = bullet.fireX = x;
		bullet.y = bullet.fireY = y;
		bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());
		bullet.angle = (i - 1) * 15 + 90;
		_vBullet.push_back(bullet);
	}
}

void SpreadMissile::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (BULLET_COUNT + _BulletTick <= GetTickCount())
		{
			_BulletTick = GetTickCount();
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);

			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}
		}
		_viBullet->x += _viBullet->speed * cosf(DEG_TO_RAD * _viBullet->angle);
		_viBullet->y -= _viBullet->speed * sinf(DEG_TO_RAD * _viBullet->angle);
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
		if (MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y) >= _range)
		{
			SAFE_DELETE(_viBullet->img);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else
		{
			_viBullet++;
		}
	}
}

SpreadMissile::SpreadMissile()
{
}

SpreadMissile::~SpreadMissile()
{
}

void MiniRocket::fire(float x, float y)
{
	if (_bulletMax <= _vBullet.size()) return;
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.count = 0;
	bullet.img = new GImage;
	bullet.img->init("Resources/MiniRocket.bmp", 30, 39, 1, 1, true, RGB(255, 0, 255));
	bullet.speed = 2.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());
	_vBullet.push_back(bullet);

}

void MiniRocket::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (BULLET_COUNT + _BulletTick <= GetTickCount())
		{
			_BulletTick = GetTickCount();
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);

			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}
		}
		_viBullet->count++;
		_viBullet->y -= _viBullet->speed * _viBullet->count;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
		if (MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y) >= _range)
		{
			SAFE_DELETE(_viBullet->img);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else
		{
			_viBullet++;
		}
	}


}

MiniRocket::MiniRocket()
{
}

MiniRocket::~MiniRocket()
{
}

HRESULT Beam::init(int bulletMax, float range)
{
	_range = range;
	_bulletMax = bulletMax;
	_BulletTick = 7.0f;
	return S_OK;
}

void Beam::update()
{
	move();
}

void Beam::render()
{
	draw();
}

void Beam::release()
{
	
	//1. 정석 (표준 문법)
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		SAFE_DELETE(_viBullet->img);
	}
	_vBullet.clear();
	//다양한 방법들
	//// 2. 변수 이름의 길이에 의해 떨어지는 가독성을 챙기고싶다.
	//_viBullet = _vBullet.begin();
	//for (; _viBullet != _vBullet.end(); ++_viBullet)
	//{
	//	SAFE_DELETE(_viBullet->img);
	//}
	//// 3. 협업시 효율적인 방법	가독성+ 확장성 고려
	//iterBullet iterBullet = _vBullet.begin();

	////협업에서는 지양해야할 방식(auto 자료형이 가독성을 떨어뜨린다.)
	//auto iterBullet = _vBullet.begin();
	//for (; iterBullet != _vBullet.end(); ++iterBullet)
	//{
	//	SAFE_DELETE(iterBullet->img);
	//}

	//// 4. range based	언리얼에 들어가면 더욱 중요하다.
	//// 언리얼에서는 STL이 없고 유사한 기능이 있다. 
	//for (auto iter : _vBullet)
	//{
	//	SAFE_DELETE(iter.img);
	//}

	//// 5. for each (High)
	//// 별도의 연산 로직이 없는 경우에는 사용해도 된다. 기왕이면 4번으로 가자
	//for each (auto iter in _vBullet)
	//{
	//	SAFE_DELETE(iter.img);
	//}

	//// 6. functional for_each
	//// ㄴ 반복자의 시작과 끝, 그리고 함수를 파라미터로 받는다.
	//// ㄴ 마지막 부분이 파라미터이기 때문에 람다식으로 표현이 가능
	////루아식 문법에서 따온 문법 
	//for_each(_vBullet.begin(), _vBullet.end(), update);

	//// 7. transform
	//// ㄴ 반복자를 이용한 반복문이라고 할 수 있다.(결과를 다른 컨테이너에 저장)
	//// ㄴ 원본 컨테이너도 가능 + 람다
	//// 
	//vector<int> _vBulletReload;
	//transform(_vBullet.begin(), _vBullet.end(), _vBulletReload.begin(), update);
	//transform(_vBullet.begin(), _vBullet.end(), _vBulletReload.begin(),
	//	[](__int64 numA)-> auto {return numA; });

	//// 
	//// 
	////람다식
	////ㄴ 1회성 함수
	//// 대괄호 캡쳐: 사용할 변수를 캡처해와서 사용
	//int Value = 0;
	//for_each(_vBullet.begin(), _vBullet.end(), [&Value](auto& number)
	//{
	//	Value += number;
	//});
	///*
	//람다식
	//ㄴ [](){}()
	//ㄴ [캡처](매개변수){(반환)함수 동작}(호출 인자(생략 가능))

	//[](int numA, int numB){cout << numA + numB <<endl;}(10, 20);
	//[](int numA, int numB){return numA + numB}(10, 20);

	//*/

	//int numberA = 10;
	//int numberB = 20;

	//auto resultA = [](int numA, int numB) {return numA + numB; }(10, 10);
	//auto resultB = [&]()->int {return numberA + numberB; }();
	//auto resultC = [=, &numberA]()->int {return numberA + numberB; }();
	///*
	//캡처 연산자
	//[]:				같은 영역에 있는 모든 변수에 접근X
	//[&]:			같은 영역에 있는 모든 변수를 참조O
	//[=]:			같은 영역에 있는 모든 변수를 값O
	//[&, 변수A]:		같은 영역에 있는 모든 변수를 참조 캡처, 단 변수A만 참조로 캡처
	//[=, 변수A]:		같은 영역에 있는 모든 변수를 참조 캡처, 단 변수A만 값으로 캡처
	//[&변수A]:		같은 영역에 있는 권한X
	//*/
}

void Beam::fire(float x, float y)
{
	if (_bulletMax <= _vBullet.size()) return;

	tagBullet bullet;
	//ZeroMemory vs memset
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = new GImage;
	bullet.img->init("Resources/beam.bmp", 412, 801, 4, 1, true, RGB(255, 0, 255));
	//bullet.img->init("Resources/.bmp",);
	bullet.speed = 0.1f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	//bullet.fire = true;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);

}

void Beam::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->img->frameRender(getMemDC(), _viBullet->x, _viBullet->y, _viBullet->img->getFrameX(), _viBullet->img->getFrameY());
	}
}

void Beam::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); _viBullet++)
	{
		if (BULLET_COUNT + _BulletTick <= GetTickCount())
		{
			_BulletTick = GetTickCount();
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);

			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}
		}
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
		//if (MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y) >= _range)
		//{
		//	SAFE_DELETE(_viBullet->img);
		//	_viBullet = _vBullet.erase(_viBullet);
		//}
		/*else
		{
			_viBullet++;
		}*/
	}
}
